/*
    Initial author: Convery (tcn@ayria.se)
    Started: 09-01-2018
    License: MIT
    Notes:
        Provides an implementation of SSL over TCP parsing.
*/

#pragma once
#if __has_include(<openssl\ssl.h>)
#include "../../Stdinclude.hpp"
#include <openssl\bio.h>
#include <openssl\ssl.h>
#include <openssl\err.h>

struct ISSLServer : IStreamserver
{
    std::unordered_map<size_t, SSL_CTX *> Context;
    std::unordered_map<size_t, BIO *> Write_BIO;
    std::unordered_map<size_t, BIO *> Read_BIO;
    std::unordered_map<size_t, SSL *> State;
    std::string SSLCert = "";
    std::string SSLKey = "";

    // SSL helper.
    virtual void Syncbuffers(const size_t Socket)
    {
        auto Buffer = std::make_unique<uint8_t []>(4096 * 1024);
        auto Readcount = BIO_read(Write_BIO[Socket], Buffer.get(), 4096 * 1024);
        if (Readcount > 0) IStreamserver::Send(Socket, Buffer.get(), Readcount);
    }

    // Usercode interactions.
    virtual void onStreamdecrypted(const size_t Socket, std::vector<uint8_t> &Stream) = 0;
    virtual void Send(const size_t Socket, const void *Databuffer, const uint32_t Datasize)
    {
        auto Lambda = [&](const size_t lSocket) -> void
        {
            SSL_write(State[lSocket], Databuffer, Datasize);
        };

        // If there is a socket, just enqueue to its stream.
        if (0 != Socket) return Lambda(Socket);

        // Else we treat it as a broadcast request.
        for (auto &Item : Validconnection)
            if (Item.second == true)
                Lambda(Item.first);
    }
    virtual void Send(const size_t Socket, std::string &Databuffer)
    {
        return Send(Socket, Databuffer.data(), uint32_t(Databuffer.size()));
    }
    virtual void onData(const size_t Socket, std::vector<uint8_t> &Stream)
    {
        int Readcount;
        int Writecount;

        // Insert the data into the SSL buffer.
        Writecount = BIO_write(Read_BIO[Socket], Stream.data(), Stream.size());

        if (!SSL_is_init_finished(State[Socket]))
        {
            SSL_do_handshake(State[Socket]);
        }
        else
        {
            auto Buffer = std::make_unique<uint8_t []>(4096 * 1024);
            Readcount = SSL_read(State[Socket], Buffer.get(), 4096 * 1024);

            // Check errors.
            if (Readcount == 0)
            {
                size_t Error = SSL_get_error(State[Socket], 0);
                if (Error == SSL_ERROR_ZERO_RETURN)
                {
                    // Remake the SSL state.
                    {
                        SSL_free(State[Socket]);

                        Write_BIO[Socket] = BIO_new(BIO_s_mem());
                        Read_BIO[Socket] = BIO_new(BIO_s_mem());
                        BIO_set_nbio(Write_BIO[Socket], 1);
                        BIO_set_nbio(Read_BIO[Socket], 1);

                        State[Socket] = SSL_new(Context[Socket]);
                        if(!State[Socket]) Infoprint("OpenSSL error: Failed to create the SSL state.");

                        SSL_set_bio(State[Socket], Read_BIO[Socket], Write_BIO[Socket]);
                        SSL_set_verify(State[Socket], SSL_VERIFY_NONE, NULL);
                        SSL_set_accept_state(State[Socket]);
                    }

                    Stream.clear();
                    return;
                }
            }

            if (Readcount > 0)
            {
                std::vector<uint8_t> Request(Buffer.get(), Buffer.get() + Readcount);
                onStreamdecrypted(Socket, Request);
            }
        }

        Stream.erase(Stream.begin(), Stream.begin() + Writecount);
        Threadguard.unlock();
        Syncbuffers(Socket);
    }

    // Stream-based IO for protocols such as TCP.
    virtual void onDisconnect(const size_t Socket)
    {
        IStreamserver::onDisconnect(Socket);
        Write_BIO.erase(Socket);
        Read_BIO.erase(Socket);
        Context.erase(Socket);
        State.erase(Socket);
    }
    virtual void onConnect(const size_t Socket, const uint16_t Port)
    {
        size_t Resultcode;
        IStreamserver::onConnect(Socket, Port);

        // Initialize the context.
        {
            Context[Socket] = SSL_CTX_new(SSLv23_server_method());
            SSL_CTX_set_verify(Context[Socket], SSL_VERIFY_NONE, NULL);

            SSL_CTX_set_options(Context[Socket], SSL_OP_SINGLE_DH_USE);
            SSL_CTX_set_ecdh_auto(Context[Socket], 1);

            uint8_t ssl_context_id[16]{ 2, 3, 4, 5, 6 };
            SSL_CTX_set_session_id_context(Context[Socket], (const unsigned char *)&ssl_context_id, sizeof(ssl_context_id));
        }

        // Load the certificate and key for this server.
        {
            Resultcode = SSL_CTX_use_certificate_file(Context[Socket], SSLCert.c_str(), SSL_FILETYPE_PEM);
            if (Resultcode != 1) Infoprint(va("OpenSSL error: %s", ERR_error_string(Resultcode, NULL)).c_str());

            Resultcode = SSL_CTX_use_PrivateKey_file(Context[Socket], SSLKey.c_str(), SSL_FILETYPE_PEM);
            if (Resultcode != 1) Infoprint(va("OpenSSL error: %s", ERR_error_string(Resultcode, NULL)).c_str());

            Resultcode = SSL_CTX_check_private_key(Context[Socket]);
            if (Resultcode != 1) Infoprint(va("OpenSSL error: %s", ERR_error_string(Resultcode, NULL)).c_str());
        }

        // Create the BIO buffers.
        {
            Write_BIO[Socket] = BIO_new(BIO_s_mem());
            Read_BIO[Socket] = BIO_new(BIO_s_mem());
            BIO_set_nbio(Write_BIO[Socket], 1);
            BIO_set_nbio(Read_BIO[Socket], 1);
        }

        // Initialize the SSL state.
        {
            State[Socket] = SSL_new(Context[Socket]);
            if (!State[Socket]) Infoprint("OpenSSL error: Failed to create the SSL state.");

            SSL_set_bio(State[Socket], Read_BIO[Socket], Write_BIO[Socket]);
            SSL_set_verify(State[Socket], SSL_VERIFY_NONE, NULL);
            SSL_set_accept_state(State[Socket]);
        }
    }
};

#endif

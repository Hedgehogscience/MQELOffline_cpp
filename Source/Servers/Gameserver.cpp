/*
    Initial author: Convery (tcn@ayria.se)
    Started: 11-01-2018
    License: MIT
    Notes:
        Implements the games main server.
*/

#include "../Stdinclude.hpp"

// Services handled by this server.
std::unordered_map<std::string, Servicecallback> *Servicemap;
void Mapservice(std::string Request, Servicecallback Callback)
{
    if (!Servicemap) Servicemap = new std::unordered_map<std::string, Servicecallback>();
    Servicemap->emplace(Request, Callback);
}

// Add a HTTP header to the message.
void Sendreply(struct Gameserver *Server, std::string Result)
{
    // Check that we didn't send an uninitialized buffer.
    assert(0 != std::strcmp(Result.c_str(), "null"));

    // Ensure that notifications are sent first.
    auto Message = MQEL_json::object();
    auto Notifications = World::Notifications::Dequeue();
    if(Notifications.size()) Message["Notifications"] = Notifications;

    // Serialize the result. TODO(Convery): Remove legacy check.
    auto Parsed = MQEL_json::parse(Result);
    if (Parsed["Result"].is_null()) Message["Result"] = Parsed;
    else Message["Result"] = Parsed["Result"];

    // Should be optimized out.
    std::string Plaintext = Message.dump();

    // Basic HTTP header.
    std::string Response;
    Response.append("HTTP/1.1 200 OK\r\n");
    Response.append("Connection: Close\r\n");
    Response.append("Content-Type: application/json\r\n");
    Response.append(va("Content-Length: %u\r\n\r\n", Plaintext.size()));
    Response.append(Plaintext);

    Server->Send(0, Response);
}

// Callbacks on parsed data.
void Gameserver::onGET(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
    std::string Servicepath = Request.URL.substr(0, Request.URL.find_first_of('?'));

    auto Service = Servicemap->find(Servicepath);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second(this, Request.URL, Request.Body);
};
void Gameserver::onPUT(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
    std::string Servicepath = Request.URL.substr(0, Request.URL.find_first_of('?'));

    auto Service = Servicemap->find(Servicepath);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second(this, Request.URL, Request.Body);
};
void Gameserver::onPOST(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
    std::string Servicepath = Request.URL.substr(0, Request.URL.find_first_of('?'));

    auto Service = Servicemap->find(Servicepath);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second(this, Request.URL, Request.Body);
};
void Gameserver::onCOPY(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
    std::string Servicepath = Request.URL.substr(0, Request.URL.find_first_of('?'));

    auto Service = Servicemap->find(Servicepath);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second(this, Request.URL, Request.Body);
};
void Gameserver::onDELETE(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
    std::string Servicepath = Request.URL.substr(0, Request.URL.find_first_of('?'));

    auto Service = Servicemap->find(Servicepath);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second(this, Request.URL, Request.Body);
};

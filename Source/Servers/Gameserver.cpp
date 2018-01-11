/*
    Initial author: Convery (tcn@ayria.se)
    Started: 11-01-2018
    License: MIT
    Notes:
        Implements the games main server.
*/

#include "../Stdinclude.hpp"

// Callbacks on parsed data.
void Gameserver::onGET(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
};
void Gameserver::onPUT(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
};
void Gameserver::onPOST(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
};
void Gameserver::onCOPY(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
};
void Gameserver::onDELETE(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));
};

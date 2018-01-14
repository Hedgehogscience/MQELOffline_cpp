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

// Callbacks on parsed data.
void Gameserver::onGET(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));

    auto Service = Servicemap->find(Request.URL);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second((IServer *)this, Request.URL, Request.Body);
};
void Gameserver::onPUT(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));

    auto Service = Servicemap->find(Request.URL);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second((IServer *)this, Request.URL, Request.Body);
};
void Gameserver::onPOST(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));

    auto Service = Servicemap->find(Request.URL);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second((IServer *)this, Request.URL, Request.Body);
};
void Gameserver::onCOPY(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));

    auto Service = Servicemap->find(Request.URL);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second((IServer *)this, Request.URL, Request.Body);
};
void Gameserver::onDELETE(const size_t Socket, HTTPRequest &Request)
{
    Debugprint(va("%s: %s", __FUNCTION__, Request.URL.c_str()));

    auto Service = Servicemap->find(Request.URL);
    if (Service == Servicemap->end()) Debugprint("No service");
    else Service->second((IServer *)this, Request.URL, Request.Body);
};

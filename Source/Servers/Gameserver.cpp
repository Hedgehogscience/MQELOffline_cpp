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
    /*
        TODO(Convery):
        Remove the legacy checks before 1.0.
    */

    // Check that we didn't send an uninitialized buffer.
    assert(0 != std::strcmp(Result.c_str(), "null"));

    // Legacy, extract from the result string.
    auto Parsed = MQEL_json::parse(Result);
    auto Globalnotifications = Parsed.value("GlobalNotifications", MQEL_json::array());
    auto Localnotifications = Parsed.value("Notifications", MQEL_json::array());
    auto Resultobject = Parsed.value("Result", MQEL_json::object());

    // Fetch notifications to the client.
    auto Notifications = World::Notifications::Dequeue();
    if (Notifications.size())
    {
        if (Localnotifications.empty())
            Localnotifications = Notifications;
        else
            for(auto &Item : Notifications)
                Localnotifications += Item;
    }

    // Serialize the message, with legacy checks.
    auto Message = MQEL_json::object();
    if (!Globalnotifications.empty())
        Message["GlobalNotifications"] = Globalnotifications;
    if (!Localnotifications.empty())
        Message["Notifications"] = Localnotifications;
    if (!Resultobject.empty())
        Message["Result"] = Resultobject;
    if (!Parsed.empty() && Message["Result"].is_null())
        Message["Result"] = Parsed;

    // Should be optimized out.
    std::string Plaintext = Message.dump();
    Debugprint(va("Sending message len: %i", Plaintext.size()));

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

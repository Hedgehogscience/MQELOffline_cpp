/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for Account-modification services.
*/

#pragma once
#include "../Stdinclude.hpp"

// Endpoints.
void ChooseDisplayName(Gameserver *Server, std::string Request, std::string Body)
{
    Request_t Parsed{ Body };
    auto Username = Parsed.Get("displayName", "Invalid");

    Debugprint(Parsed.toString());
    Sendreply(Server, "{}");


    //MQEL_json Parsed = MQEL_json::parse(Body);

    //Infoprint(va("Name updated to: %s", Parsed["displayName"].get<std::string>().c_str()));
    //Sendreply(Server, "{}");
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/AccountService.hqs/ChooseDisplayName", ChooseDisplayName);
        };
    };
    static Startup Loader{};
}

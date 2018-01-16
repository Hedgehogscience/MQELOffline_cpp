/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for hero services.
*/

#pragma once
#include "../Stdinclude.hpp"

// Endpoints.
void ChooseFirstHero(Gameserver *Server, std::string Request, std::string Body)
{
    MQEL_json Parsed = MQEL_json::parse(Body);
    Infoprint(va("Selected hero %i", Parsed["heroSpecContainerId"].get<uint32_t>()));
    World::Hero::Create((eHerotype)Parsed["heroSpecContainerId"].get<uint32_t>());

    MQEL_json Response;
    Response["Result"] = World::Hero::Serialize();
    Sendreply(Server, Response.dump());
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/HeroService.hqs/ChooseFirstHero", ChooseFirstHero);
        };
    };
    static Startup Loader{};
}

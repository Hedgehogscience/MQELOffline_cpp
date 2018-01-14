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
    nlohmann::json Parsed = nlohmann::json::parse(Body);
    Infoprint(va("Selected hero %i", Parsed["heroSpecContainerId"].get<uint32_t>()));

    nlohmann::json Response = R"({"Result":{"HeroSpecContainerId":4,"Level":1,"Equipment":{"Head":{"ItemLevel":1,"ArchetypeId":8,"PrimaryStatsModifiers":[0.4,0.4,0.4],"TemplateId":129},"Shoulders":{"ItemLevel":1,"ArchetypeId":8,"PrimaryStatsModifiers":[0.4,0.4,0.4],"TemplateId":134},"Body":{"ItemLevel":1,"ArchetypeId":8,"PrimaryStatsModifiers":[0.4,0.4,0.4],"TemplateId":130},"Hands":{"ItemLevel":1,"ArchetypeId":8,"PrimaryStatsModifiers":[0.4,0.4,0.4],"TemplateId":131},"MainHand":{"ItemLevel":1,"ArchetypeId":9,"PrimaryStatsModifiers":[0.4,0.4,0.4],"TemplateId":128}},"EquippedConsumables":[{"TemplateId":1}],"AttackRegions":[{"AttackRegionId":3,"Status":2}]}})"_json;

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

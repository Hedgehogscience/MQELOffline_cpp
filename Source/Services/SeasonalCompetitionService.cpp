/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for league stats.
*/

#pragma once
#include "../Stdinclude.hpp"

// Endpoints.
void CheckSeasonalCompetitionRewards(Gameserver *Server, std::string Request, std::string Body)
{
    MQEL_json Response = MQEL_json::parse(R"({"Notifications":[{"$type":"HyperQuest.GameServer.Contracts.LeagueUpdatedNotification, HyperQuest.GameServer.Contracts","LeagueId":1,"SubLeagueId":1,"NotificationType":65},{"$type":"HyperQuest.GameServer.Contracts.NewsAddedNotification, HyperQuest.GameServer.Contracts","NewsItem":{"Id":"580d4fa55c98320a9cb0e55d","PublishDate":"2016-10-24T00:00:00Z","Data":{"$type":"HyperQuest.GameServer.Contracts.LeagueUpdatedNewsData, HyperQuest.GameServer.Contracts","CurrentLeagueId":1,"CurrentSubleagueId":1,"PreviousLeagueId":1,"PreviousSubleagueId":1,"Type":18},"IsUnread":true,"Priority":1},"NotificationType":22}]})");

    Sendreply(Server, Response.dump());
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/SeasonalCompetitionService.hqs/CheckSeasonalCompetitionRewards", CheckSeasonalCompetitionRewards);
        };
    };
    static Startup Loader{};
}

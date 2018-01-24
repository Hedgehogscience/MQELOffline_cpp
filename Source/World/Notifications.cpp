/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Tracks the notifications created and delivered.
*/

#include "../Stdinclude.hpp"

// Internal state.
std::queue<MQEL_json> Notificationqueue;

// Notification tracking.
void World::Notifications::Enqueue(MQEL_json Notification)
{
    Notificationqueue.push(Notification);
}
std::vector<MQEL_json> World::Notifications::Dequeue()
{
    std::vector<MQEL_json> Result;

    while (!Notificationqueue.empty())
    {
        auto Local = Notificationqueue.front();
        Notificationqueue.pop();
        Result.push_back(Local);
    }

    return std::move(Result);
}

// Create a notification.
MQEL_json World::Notifications::Leagueupdated(uint32_t LeagueID, uint32_t LeaguesubID)
{
    MQEL_json Object = MQEL_json::object();

    Object["$type"] = "HyperQuest.GameServer.Contracts.LeagueUpdatedNotification, HyperQuest.GameServer.Contracts";
    Object["LeagueId"] = LeagueID;
    Object["SubLeagueId"] = LeaguesubID;
    Object["NotificationType"] = 65;

    return Object;
}

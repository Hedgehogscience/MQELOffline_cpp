/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Tracks the notifications created and delivered.
*/

#include "../Stdinclude.hpp"

// Internal state.
std::queue<nlohmann::json> Notificationqueue;

// Notification tracking.
void World::Notifications::Enqueue(nlohmann::json Notification)
{
    Notificationqueue.push(Notification);
}
std::vector<nlohmann::json> World::Notifications::Dequeue()
{
    std::vector<nlohmann::json> Result;

    while (!Notificationqueue.empty())
    {
        auto Local = Notificationqueue.front();
        Notificationqueue.pop();
        Result.push_back(Local);
    }

    return std::move(Result);
}

// Create a notification.
nlohmann::json World::Notifications::Leagueupdated(uint32_t LeagueID, uint32_t LeaguesubID)
{
    nlohmann::json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.LeagueUpdatedNotification, HyperQuest.GameServer.Contracts";
    Object["SubLeagueId"] = LeaguesubID;
    Object["NotificationType"] = 65;
    Object["LeagueId"] = LeagueID;

    return Object;
}

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
nlohmann::json World::Notifications::Assignmentactioncomplete(uint32_t AssignmentID, uint32_t ActionID)
{
    nlohmann::json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.ServerAssignmentActionCompletedNotification, HyperQuest.GameServer.Contracts";
    Object["AssignmentActionIndex"] = ActionID;
    Object["AssignmentId"] = AssignmentID;
    Object["NotificationType"] = 74;

    return Object;
}
nlohmann::json World::Notifications::Walletupdate(std::vector<std::pair<uint32_t, uint32_t>> Currencies)
{
    nlohmann::json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts";
    Object["NotificationType"] = 24;

    for (auto &Item : Currencies)
    {
        if (Item.second == 0) Object["Amounts"] += { "CurrencyType", Item.first };
        else Object["Amounts"] += { {"CurrencyType", Item.first}, {"CurrencyType", Item.first, "Amount", Item.second} };
    }

    return Object;
}
nlohmann::json World::Notifications::XPUpdate(uint32_t HeroID, uint32_t XPIncrease, uint32_t XPTotal, uint32_t Level)
{
    nlohmann::json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.HeroXpChangedNotification, HyperQuest.GameServer.Contracts";
    Object["HeroSpecContainerId"] = HeroID;
    Object["NotificationType"] = 43;
    Object["XpAdded"] = XPIncrease;
    Object["TotalXp"] = XPTotal;
    Object["Level"] = Level;

    return Object;
}





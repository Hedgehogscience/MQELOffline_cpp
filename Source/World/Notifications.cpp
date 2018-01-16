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
    MQEL_json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.LeagueUpdatedNotification, HyperQuest.GameServer.Contracts";
    Object["LeagueId"] = LeagueID;
    Object["SubLeagueId"] = LeaguesubID;
    Object["NotificationType"] = 65;

    return Object;
}
MQEL_json World::Notifications::Assignmentactioncomplete(uint32_t AssignmentID, uint32_t ActionID)
{
    MQEL_json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.ServerAssignmentActionCompletedNotification, HyperQuest.GameServer.Contracts";
    Object["AssignmentId"] = AssignmentID;
    Object["AssignmentActionIndex"] = ActionID;
    Object["NotificationType"] = 74;

    return Object;
}
MQEL_json World::Notifications::Walletupdate(std::vector<std::pair<eCurrencytype, uint32_t>> Currencies)
{
    MQEL_json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts";
    for (auto &Item : Currencies)
    {
        if (Item.second == 0) Object["Amounts"] += { "CurrencyType", (uint32_t)Item.first };
        else Object["Amounts"] += { {"CurrencyType", (uint32_t)Item.first}, {"CurrencyType", Item.first, "Amount", Item.second} };
    }
    Object["NotificationType"] = 24;

    return Object;
}
MQEL_json World::Notifications::XPUpdate(uint32_t HeroID, uint32_t XPIncrease, uint32_t XPTotal, uint32_t Level)
{
    MQEL_json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.HeroXpChangedNotification, HyperQuest.GameServer.Contracts";
    Object["HeroSpecContainerId"] = HeroID;
    Object["XpAdded"] = XPIncrease;
    Object["TotalXp"] = XPTotal;
    Object["Level"] = Level;
    Object["NotificationType"] = 43;

    return Object;
}
MQEL_json World::Notifications::Walletcapacityupdate(eCurrencytype Currencytype, uint32_t Amount)
{
    MQEL_json Object;

    Object["$type"] = "HyperQuest.GameServer.Contracts.WalletCapacityUpdatedNotification, HyperQuest.GameServer.Contracts";
    Object["CurrencyType"] = (uint32_t)Currencytype;
    Object["Amount"] = Amount;
    Object["NotificationType"] = 47;

    return Object;
}

/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Provides access to the internal Worldstate.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace World
{
    // Quest tracking.
    namespace Quests
    {
        void Start(uint32_t QuestID);
        void Complete(uint32_t QuestID);
        std::vector<uint32_t> Completedquests();
        void Update(uint32_t QuestID, uint32_t ActionID);
    }

    // Notification tracking.
    namespace Notifications
    {
        void Enqueue(nlohmann::json Notification);
        std::vector<nlohmann::json> Dequeue();

        // Create a notification.
        /* 065 */ nlohmann::json Leagueupdated(uint32_t LeagueID, uint32_t LeaguesubID);
        /* 074 */ nlohmann::json Assignmentactioncomplete(uint32_t AssignmentID, uint32_t ActionID);
        /* 023 */ nlohmann::json Walletupdate(std::vector<std::pair<uint32_t, uint32_t>> Currencies);
        /* 043 */ nlohmann::json XPUpdate(uint32_t HeroID, uint32_t XPIncrease, uint32_t XPTotal, uint32_t Level);
        /* 047 */ nlohmann::json Walletcapacityupdate(uint32_t Currencytype, uint32_t Amount);
    }
}

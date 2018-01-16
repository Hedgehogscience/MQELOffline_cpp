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
        nlohmann::json Leagueupdated(uint32_t LeagueID, uint32_t LeaguesubID);
    }
}

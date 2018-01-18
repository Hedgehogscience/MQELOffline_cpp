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
        void Enqueue(MQEL_json Notification);
        std::vector<MQEL_json> Dequeue();

        // Create a notification.
        /* 065 */ MQEL_json Leagueupdated(uint32_t LeagueID, uint32_t LeaguesubID);
        /* 074 */ MQEL_json Assignmentactioncomplete(uint32_t AssignmentID, uint32_t ActionID);
        /* 023 */ MQEL_json Walletupdate(std::vector<std::pair<eCurrencytype, uint32_t>> Currencies);
        /* 043 */ MQEL_json XPUpdate(uint32_t HeroID, uint32_t XPIncrease, uint32_t XPTotal, uint32_t Level);
        /* 047 */ MQEL_json Walletcapacityupdate(eCurrencytype Currencytype, uint32_t Amount);
    }

    // Hero progress and management.
    namespace Hero
    {
        // A character with starting-gear.
        void Create(eHerotype Class);
        MQEL_json Serialize();

        // Modify the character.
        void IncreaseXP(uint32_t XP);
        void Increaselevel(uint32_t Level);
        void Increasekillstat(uint32_t Kills);
        void Increaselootstat(uint32_t Looted);
        void Increasetimesplayedstat(uint32_t Played);
        void Equipspell(uint32_t Slot, uint32_t ID);
    }
}

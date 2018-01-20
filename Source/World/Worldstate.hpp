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
        struct Stat_t
        {
            uint32_t Creatureskilled;
            uint32_t Castleslooted;
            uint32_t Timesplayed;

            MQEL_json Serialize()
            {
                MQEL_json Object = MQEL_json::object();

                if(Creatureskilled) Object["TotalCreaturesKilled"] = Creatureskilled;
                if(Castleslooted)   Object["TotalCastlesLooted"] = Castleslooted;
                if(Timesplayed)     Object["TimePlayed"] = Timesplayed;

                return std::move(Object);
            }
            void Deserialize(MQEL_json &Object)
            {
                if (!Object["TotalCreaturesKilled"].is_null()) { Creatureskilled = Object["TotalCreaturesKilled"]; }
                if (!Object["TotalCastlesLooted"].is_null()) { Castleslooted = Object["TotalCastlesLooted"]; }
                if (!Object["TimePlayed"].is_null()) { Timesplayed = Object["TimePlayed"]; }
            }
        };
        struct Spell_t
        {
            uint32_t ID;
            uint32_t Slot;

            MQEL_json Serialize()
            {
                MQEL_json Object = MQEL_json::object();

                if(Slot) Object["SlotIndex"] = Slot;
                Object["SpellSpecContainerId"] = ID;

                return std::move(Object);
            }
        };
        struct Effect_t
        {
            uint32_t ID;
            uint32_t Level;

            MQEL_json Serialize()
            {
                MQEL_json Object = MQEL_json::object();

                Object["Id"] = ID;
                Object["Level"] = Level;

                return std::move(Object);
            }
        };
        struct Equipment_t
        {
            uint32_t ID;
            bool Sellable;
            uint32_t Type;
            uint32_t Level;
            std::vector<double> Modifiers;
            std::vector<Effect_t> Effects;

            /*
                NOTE(Convery):
                Possibly contains:
                uint32_t EnchantmentLevel;
                array Stats;
            */

            MQEL_json Serialize()
            {
                MQEL_json Object = MQEL_json::object();

                Object["ItemLevel"] = Level;
                Object["ArchetypeId"] = Type;
                Object["PrimaryStatsModifiers"] = Modifiers;
                for (auto &Item : Effects) Object["Effects"] += Item.Serialize();
                if(Sellable) Object["IsSellable"] = Sellable;
                Object["TemplateId"] = ID;

                return std::move(Object);
            }
            void Deserialize(MQEL_json &Object)
            {
                if (!Object["ItemLevel"].is_null()) { Level = Object["ItemLevel"]; }
                if (!Object["ArchetypeId"].is_null()) { Type = Object["ArchetypeId"]; }
                if (!Object["PrimaryStatsModifiers"].is_null()) { for (auto &Item : Object["PrimaryStatsModifiers"]) Modifiers.push_back(Item); }
                if (!Object["Effects"].is_null()) { for (auto &Item : Object["Effects"]) Effects.push_back({ Item["Id"], Item["Level"]}); }
                if (!Object["IsSellable"].is_null()) { Sellable = Object["IsSellable"]; }
                if (!Object["TemplateId"].is_null()) { ID = Object["TemplateId"]; }
            }
        };
        struct Consumable_t
        {
            uint32_t ID;

            MQEL_json Serialize()
            {
                MQEL_json Object = MQEL_json::object();

                /* TODO(Convery): RE the other properties. */
                Object["TemplateId"] = ID;

                return std::move(Object);
            }
        };
        struct Attackregion_t
        {
            uint32_t ID;
            eRegionstatus Status;

            MQEL_json Serialize()
            {
                MQEL_json Object = MQEL_json::object();

                Object["AttackRegionId"] = ID;
                Object["Status"] = (uint32_t)Status;

                return std::move(Object);
            }
        };

        // Do we have a hero in memory?
        bool Created();

        // To game-readable data.
        MQEL_json Serialize();

        // Initialize the character.
        void Create(eHerotype Class);

        // Modify the character.
        void IncreaseXP(uint32_t XP);
        void Increasestats(Stat_t Delta);
        void Increaselevel(uint32_t Level);
        void Equipitem(eItemslot Slot, Equipment_t Item);
        void Equipspell(Spell_t Spell);
    }
}

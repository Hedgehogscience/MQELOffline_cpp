/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Track the characters progress.
*/

#include "../Stdinclude.hpp"

namespace World
{
    namespace Hero
    {
        struct Hero_t
        {
            Stat_t Stats;
            eHerotype Type;
            uint32_t Level;
            uint32_t TotalXP;
            std::vector<Spell_t> Spells;
            std::vector<Consumable_t> Consumables;
            std::vector<Attackregion_t> Knownregions;
            std::array<Equipment_t, (uint32_t)eItemslot::Count> Gear;

            MQEL_json Serialize()
            {
                MQEL_json Object;

                // Core data.
                Object["HeroSpecContainerId"] = (uint32_t)Type;
                if(TotalXP) Object["XP"] = TotalXP;
                Object["Level"] = Level;

                // User-modifiable equipment.
                if(Gear[(uint32_t)eItemslot::Head].ID)
                    Object["Equipment"]["Head"] =       Gear[(uint32_t)eItemslot::Head].Serialize();
                if(Gear[(uint32_t)eItemslot::Shoulders].ID)
                    Object["Equipment"]["Shoulders"] =  Gear[(uint32_t)eItemslot::Shoulders].Serialize();
                if(Gear[(uint32_t)eItemslot::Body].ID)
                    Object["Equipment"]["Body"] =       Gear[(uint32_t)eItemslot::Body].Serialize();
                if(Gear[(uint32_t)eItemslot::Back].ID)
                    Object["Equipment"]["Back"] =       Gear[(uint32_t)eItemslot::Back].Serialize();
                if(Gear[(uint32_t)eItemslot::Neck].ID)
                    Object["Equipment"]["Neck"] =       Gear[(uint32_t)eItemslot::Neck].Serialize();
                if(Gear[(uint32_t)eItemslot::Finger].ID)
                    Object["Equipment"]["Finger"] =     Gear[(uint32_t)eItemslot::Finger].Serialize();
                if(Gear[(uint32_t)eItemslot::Hands].ID)
                    Object["Equipment"]["Hands"] =      Gear[(uint32_t)eItemslot::Hands].Serialize();
                if(Gear[(uint32_t)eItemslot::Mainhand].ID)
                    Object["Equipment"]["MainHand"] =   Gear[(uint32_t)eItemslot::Mainhand].Serialize();
                if(Gear[(uint32_t)eItemslot::Offhand].ID)
                    Object["Equipment"]["OffHand"] =    Gear[(uint32_t)eItemslot::Offhand].Serialize();
                if(Gear[(uint32_t)eItemslot::Costume].ID)
                    Object["Equipment"]["Costume"] =    Gear[(uint32_t)eItemslot::Costume].Serialize();
                if(Gear[(uint32_t)eItemslot::Pet].ID)
                    Object["Equipment"]["Pet"] =        Gear[(uint32_t)eItemslot::Pet].Serialize();

                // Game-assigned equipment.
                for (auto &Item : Spells)               Object["EquippedSpells"] += Item.Serialize();
                for (auto &Item : Consumables)          Object["EquippedConsumables"] += Item.Serialize();

                // Semi-public statistics.
                Object["Stats"] =                       Stats.Serialize();
                for (auto &Item : Knownregions)         Object["AttackRegions"] +=  Item.Serialize();

                return std::move(Object);
            }
        };
        Hero_t Currenthero;

        // To game-readable data.
        MQEL_json Serialize()
        {
            return Currenthero.Serialize();
        }

        // Initialize the character.
        void Create(eHerotype Class)
        {
            // Clear any previous info.
            Currenthero = Hero_t();

            // Common data.
            Currenthero.Type = Class;
            Currenthero.Level = 1;
            Currenthero.Consumables.push_back({ 1 });
            Currenthero.Knownregions.push_back({ 1, eRegionstatus::Unlocked });
        }

        // Modify the character.
        void IncreaseXP(uint32_t XP)
        {
            Currenthero.TotalXP += XP;
        }
        void Increasestats(Stat_t Delta)
        {
            Currenthero.Stats.Creatureskilled += Delta.Creatureskilled;
            Currenthero.Stats.Castleslooted += Delta.Castleslooted;
            Currenthero.Stats.Timesplayed += Delta.Timesplayed;
        }
        void Increaselevel(uint32_t Level)
        {
            Currenthero.Level += Level;
        }
        void Equipitem(eItemslot Slot, Equipment_t Item)
        {
            Currenthero.Gear[(uint32_t)Slot] = Item;
        }
        void Equipspell(Spell_t Spell)
        {
            // Remove any old instance of the spell.
            for (auto Iterator = Currenthero.Spells.begin(); Iterator != Currenthero.Spells.end(); ++Iterator)
            {
                if (Iterator->ID == Spell.ID)
                {
                    Currenthero.Spells.erase(Iterator);
                    break;
                }
            }

            // Add the new spell.
            Currenthero.Spells.push_back(Spell);
        }
    }
}

/*
    TODO(Convery):
    Load and save the hero to disk.
*/

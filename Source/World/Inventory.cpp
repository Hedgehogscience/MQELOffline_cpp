/*
    Initial author: Convery (tcn@ayria.se)
    Started: 30-01-2018
    License: MIT
    Notes:
        Implements an inventory system.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace World
{
    namespace Inventory
    {
        std::array<std::array<std::unique_ptr<Hero::Equipment_t>, 42>, (int)eHerotype::Count> Inventory;
        std::unordered_map<uint32_t, Hero::Equipment_t> Lootdrops;

        uint32_t Additem(uint32_t Slot, Hero::Equipment_t Item)
        {
            uint32_t HeroID = Hero::GetheroID();

            // Find an empty slot if the current one is busy.
            while (Slot < 42 && Inventory[HeroID][Slot].get()) Slot++;
            if (Slot == 42) return 0xFFFFFFFF;

            Inventory[HeroID][Slot] = std::make_unique<Hero::Equipment_t>(Item);
            return Slot;
        }
        std::string Createloot(Hero::Equipment_t Item)
        {
            // The game expects 96 bits.
            std::string ObjectID = va("%x%x%x", Item.ID, Item.Level, Item.Archetype);
            ObjectID.append(24 - ObjectID.size(), 'a');

            Lootdrops[Hash::FNV1a_32(ObjectID.c_str())] = Item;
            return ObjectID;
        }
        void Claimitem(std::string ID, uint32_t Slot)
        {
            uint32_t Hash = Hash::FNV1a_32(ID.c_str());

            assert(Lootdrops.find(Hash) != Lootdrops.end());
            Additem(Slot, Lootdrops[Hash]);
            Lootdrops.erase(Hash);
        }

    }
}

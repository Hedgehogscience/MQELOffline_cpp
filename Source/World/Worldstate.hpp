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
    // Hero progress and management.
    namespace Hero
    {
        // Do we have a hero in memory?
        uint32_t GetheroID();
        bool Created();

        // To game-readable data.
        MQEL_json Serialize(eHerotype Class);

        // Initialize the character.
        void Create(eHerotype Class);

        // Modify the character.
        void IncreaseXP(uint32_t XP);
        void Increasestats(Stat_t Delta);
        void Increaselevel(uint32_t Level);
        void Equipitem(eHerotype Class, eItemslot Slot, Equipment_t Item);
        void Equipspell(eHerotype Class, Spell_t Spell);
    }
}

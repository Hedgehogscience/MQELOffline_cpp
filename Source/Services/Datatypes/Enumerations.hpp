/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Some game-defined enumerations.
*/

#pragma once
#include "../../Stdinclude.hpp"

enum class eCurrencytype
{
    None = 0,
    PremiumCash = 1,
    IGC = 2,
    Lifeforce = 4
};

enum class eRegionstatus
{
    None = 0,
    Locked = 1,
    Unlocked = 2,
    Completed = 3
};

enum class eHerotype
{
    Knight = 2,
    Archer = 3,
    Mage = 4,
    Runaway = 5
};

enum class eItemslot
{
    None = 0,
    Head = 1,
    Shoulders = 2,
    Body = 3,
    Back = 4,
    Neck = 5,
    Finger = 6,
    Hands = 7,
    Mainhand = 8,
    Offhand = 9,
    Costume = 10,
    Pet = 11,
    Count
};

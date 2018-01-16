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

/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for hero services.
*/

#pragma once
#include "../../Stdinclude.hpp"

// Endpoints.
void ChooseFirstHero(Gameserver *Server, std::string Request, std::string Body)
{
    // Get which hero-class we use.
    int Heroclass = MQEL_json::parse(Body)["heroSpecContainerId"];
    Infoprint(va("Creating hero of type: %s", [Heroclass]() -> const char *
    {
        switch ((eHerotype)Heroclass)
        {
            case eHerotype::Archer:     return "Archer";
            case eHerotype::Knight:     return "Knight";
            case eHerotype::Mage:       return "Mage";
            case eHerotype::Runaway:    return "Runaway";
            default:                    return "Unknown";
        }
    }()));

    // Create the core data for the character.
    Backend::Hero::Createhero(Heroclass);

    // Add gear to the character.
    switch ((eHerotype)Heroclass)
    {
        case eHerotype::Knight:
        {
            std::vector<double> Modifiers = { 0.4, 0.4, 0.4 };
            Equipment_t Basegear = { 0, 0, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} };

            Basegear.ID = 108;  // "Board with a nail in it"
            Basegear.Archetype = 2;
            Backend::Hero::Equipgear(eItemslot::Mainhand, Basegear);

            Basegear.ID = 109;  // "Mom's Favorite Haircut"
            Backend::Hero::Equipgear(eItemslot::Head, Basegear);

            Basegear.ID = 110;  // "Chiseled Pecs"
            Backend::Hero::Equipgear(eItemslot::Body, Basegear);

            Basegear.ID = 111;  // "Perfect Manicure"
            Backend::Hero::Equipgear(eItemslot::Hands, Basegear);

            Basegear.ID = 132;  // "Bane of Grindstone"
            Backend::Hero::Equipgear(eItemslot::Shoulders, Basegear);
            break;
        }
        case eHerotype::Archer:
        {
            std::vector<double> Modifiers = { 0.4, 0.4, 0.4 };
            Equipment_t Basegear = { 0, 0, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} };

            Basegear.ID = 124;  // "Pea shooter"
            Basegear.Archetype = 2;
            Backend::Hero::Equipgear(eItemslot::Mainhand, Basegear);

            Basegear.ID = 125;  // "Pure Ginger"
            Backend::Hero::Equipgear(eItemslot::Head, Basegear);

            Basegear.ID = 126;  // "Trusty Underpants"
            Backend::Hero::Equipgear(eItemslot::Body, Basegear);

            Basegear.ID = 127;  // "Trigger Finger"
            Backend::Hero::Equipgear(eItemslot::Hands, Basegear);

            Basegear.ID = 133;  // "Smirking Shrug"
            Backend::Hero::Equipgear(eItemslot::Shoulders, Basegear);
            break;
        }
        case eHerotype::Mage:
        {
            std::vector<double> Modifiers = { 0.4, 0.4, 0.4 };
            Equipment_t Basegear = { 0, 0, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} };

            Basegear.ID = 128;  // "Twig"
            Basegear.Archetype = 9;
            Backend::Hero::Equipgear(eItemslot::Mainhand, Basegear);

            Basegear.ID = 129;  // "Sleepytime 2000"
            Backend::Hero::Equipgear(eItemslot::Head, Basegear);

            Basegear.ID = 130;  // "Silken Robe"
            Backend::Hero::Equipgear(eItemslot::Body, Basegear);

            Basegear.ID = 131;  // "Creepy Claw"
            Backend::Hero::Equipgear(eItemslot::Hands, Basegear);

            Basegear.ID = 131;  // "Drape of Wrath"
            Backend::Hero::Equipgear(eItemslot::Shoulders, Basegear);
            break;
        }
        case eHerotype::Runaway:
        {
            /* TODO(Convery): Reverse-engineer this. */
            assert(false);
            break;
        }
    }

    // Return this basic character to the game.
    MQEL_json Response; Response["Result"] = Backend::Hero::Serialize();
    Sendreply(Server, Response.dump());
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/HeroService.hqs/ChooseFirstHero", ChooseFirstHero);
        };
    };
    static Startup Loader{};
}

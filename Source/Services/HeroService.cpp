/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for hero services.
*/

#pragma once
#include "../Stdinclude.hpp"

// Endpoints.
void ChooseFirstHero(Gameserver *Server, std::string Request, std::string Body)
{
    // Get which hero-class we use.
    uint32_t Heroclass = MQEL_json::parse(Body)["heroSpecContainerId"];
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
    World::Hero::Create((eHerotype)Heroclass);

    // Add gear to the character.
    switch ((eHerotype)Heroclass)
    {
        case eHerotype::Knight:
        {
            std::vector<double> Modifiers = { 0.4, 0.4, 0.4 };

            // Equipment_t { ID, Branded, Sellable, Level, TypeID, Itemtype, Modifiers, Effects }
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Head,       { 109, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Shoulders,  { 132, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Body,       { 110, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Hands,      { 111, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Mainhand,   { 108, false, false, 1, (int)eWeapontype::Sword, "HeroEquipmentItem", Modifiers, {} });
            break;
        }
        case eHerotype::Archer:
        {
            /* TODO(Convery): Reverse-engineer this. */
            assert(false);
            break;
        }
        case eHerotype::Mage:
        {
            std::vector<double> Modifiers = { 0.4, 0.4, 0.4 };

            // Equipment_t { ID, Branded, Sellable, Level, TypeID, Itemtype, Modifiers, Effects }
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Head,       { 129, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Shoulders,  { 134, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Body,       { 130, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Hands,      { 131, false, false, 1, 8, "HeroEquipmentItem", Modifiers, {} });
            World::Hero::Equipitem((eHerotype)Heroclass, eItemslot::Mainhand,   { 128, false, false, 1, (int)eWeapontype::Staff, "HeroEquipmentItem", Modifiers, {} });
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
    MQEL_json Response; Response["Result"] = World::Hero::Serialize((eHerotype)Heroclass);
    Sendreply(Server, Response.dump());

    /*
        HACK(Convery):
        This specialization should be done after the tutorial fight.
        In dev builds we replace the tutorial map with a 'real' map.
    */
    switch ((eHerotype)Heroclass)
    {
        case eHerotype::Archer:
        {
            /* TODO(Convery): Reverse-engineer this. */
            assert(false);
            break;
        }
        case eHerotype::Knight:
        {
            /* TODO(Convery): Reverse-engineer this. */
            assert(false);
            break;
        }
        case eHerotype::Mage:
        {
            World::Hero::Equipspell((eHerotype)Heroclass, { 611, 3 });
            World::Hero::Equipspell((eHerotype)Heroclass, { 613, 0 });
            break;
        }
        case eHerotype::Runaway:
        {
            /* TODO(Convery): Reverse-engineer this. */
            assert(false);
            break;
        }
    }
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

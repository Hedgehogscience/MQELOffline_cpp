/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Track the characters progress.
*/

#include "../Stdinclude.hpp"

struct Equipment_t
{
    uint32_t ID;
    uint32_t Type;
    uint32_t Level;
    std::vector<double> Modifiers;

    MQEL_json Serialize()
    {
        MQEL_json Object;

        Object["ItemLevel"] = Level;
        Object["ArchetypeId"] = Type;
        Object["PrimaryStatsModifiers"] = Modifiers;
        Object["TemplateId"] = ID;

        return std::move(Object);
    }
};
struct Consumable_t
{
    uint32_t ID;

    MQEL_json Serialize()
    {
        MQEL_json Object;

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
        MQEL_json Object;

        Object["AttackRegionId"] = ID;
        Object["Status"] = (uint32_t)Status;

        return std::move(Object);
    }
};
struct Hero_t
{
    eHerotype Type;
    uint32_t Level;
    std::vector<Consumable_t> Consumables;
    std::vector<Attackregion_t> Knownregions;
    std::array<Equipment_t, (uint32_t)eItemslot::Count> Gear;

    MQEL_json Serialize()
    {
        MQEL_json Object;

        Object["HeroSpecContainerId"] =     (uint32_t)Type;
        Object["Level"] = Level;
        Object["Equipment"]["Head"] =       Gear[(uint32_t)eItemslot::Head].Serialize();
        Object["Equipment"]["Shoulders"] =  Gear[(uint32_t)eItemslot::Shoulders].Serialize();
        Object["Equipment"]["Body"] =       Gear[(uint32_t)eItemslot::Body].Serialize();
        Object["Equipment"]["Hands"] =      Gear[(uint32_t)eItemslot::Hands].Serialize();
        Object["Equipment"]["MainHand"] =   Gear[(uint32_t)eItemslot::Mainhand].Serialize();

        for (auto &Item : Consumables)  Object["EquippedConsumables"] += Item.Serialize();
        for (auto &Item : Knownregions) Object["AttackRegions"] +=  Item.Serialize();

        return std::move(Object);
    }
};
Hero_t Currenthero;

// A character with starting-gear.
void World::Hero::Create(eHerotype Class)
{
    Currenthero.Type = Class;
    Currenthero.Level = 1;
    Currenthero.Consumables.push_back({ 1 });
    Currenthero.Knownregions.push_back({ 1, eRegionstatus::Unlocked });

    Currenthero.Gear[(uint32_t)eItemslot::Head].Level = 1;
    Currenthero.Gear[(uint32_t)eItemslot::Head].Type = 8;
    Currenthero.Gear[(uint32_t)eItemslot::Head].ID = 129;
    Currenthero.Gear[(uint32_t)eItemslot::Head].Modifiers = { 0.4, 0.4, 0.4, 0.4 };

    Currenthero.Gear[(uint32_t)eItemslot::Shoulders].Level = 1;
    Currenthero.Gear[(uint32_t)eItemslot::Shoulders].Type = 8;
    Currenthero.Gear[(uint32_t)eItemslot::Shoulders].ID = 134;
    Currenthero.Gear[(uint32_t)eItemslot::Shoulders].Modifiers = { 0.4, 0.4, 0.4, 0.4 };

    Currenthero.Gear[(uint32_t)eItemslot::Body].Level = 1;
    Currenthero.Gear[(uint32_t)eItemslot::Body].Type = 8;
    Currenthero.Gear[(uint32_t)eItemslot::Body].ID = 130;
    Currenthero.Gear[(uint32_t)eItemslot::Body].Modifiers = { 0.4, 0.4, 0.4, 0.4 };

    Currenthero.Gear[(uint32_t)eItemslot::Hands].Level = 1;
    Currenthero.Gear[(uint32_t)eItemslot::Hands].Type = 8;
    Currenthero.Gear[(uint32_t)eItemslot::Hands].ID = 131;
    Currenthero.Gear[(uint32_t)eItemslot::Hands].Modifiers = { 0.4, 0.4, 0.4, 0.4 };

    Currenthero.Gear[(uint32_t)eItemslot::Mainhand].Level = 1;
    Currenthero.Gear[(uint32_t)eItemslot::Mainhand].Type = 9;
    Currenthero.Gear[(uint32_t)eItemslot::Mainhand].ID = 128;
    Currenthero.Gear[(uint32_t)eItemslot::Mainhand].Modifiers = { 0.4, 0.4, 0.4, 0.4 };
}
MQEL_json World::Hero::Serialize()
{
    return Currenthero.Serialize();
}

/*
    TODO(Convery):
    Load and save the hero to disk.
*/

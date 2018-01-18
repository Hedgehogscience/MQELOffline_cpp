/*
    Initial author: Convery (tcn@ayria.se)
    Started: 16-01-2018
    License: MIT
    Notes:
        Track the characters progress.
*/

#include "../Stdinclude.hpp"

struct Stat_t
{
    uint32_t Creatureskilled;
    uint32_t Castleslooted;
    uint32_t Timesplayed;

    MQEL_json Serialize()
    {
        MQEL_json Object;

        Object["TotalCreaturesKilled"] = Creatureskilled;
        Object["TotalCastlesLooted"] = Castleslooted;
        Object["TimePlayed"] = Timesplayed;

        return std::move(Object);
    }
};
struct Spell_t
{
    uint32_t ID;
    uint32_t Slot;

    MQEL_json Serialize()
    {
        MQEL_json Object;

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
        MQEL_json Object;

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

    MQEL_json Serialize()
    {
        MQEL_json Object;

        Object["ItemLevel"] = Level;
        Object["ArchetypeId"] = Type;
        Object["PrimaryStatsModifiers"] = Modifiers;
        for (auto &Item : Effects) Object["Effects"] += Item.Serialize();
        if(Sellable) Object["IsSellable"] = Sellable;
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

        Object["HeroSpecContainerId"] =     (uint32_t)Type;
        if(TotalXP) Object["XP"] =          TotalXP;
        Object["Level"] =                   Level;
        Object["Equipment"]["Head"] =       Gear[(uint32_t)eItemslot::Head].Serialize();
        Object["Equipment"]["Shoulders"] =  Gear[(uint32_t)eItemslot::Shoulders].Serialize();
        Object["Equipment"]["Body"] =       Gear[(uint32_t)eItemslot::Body].Serialize();
        Object["Equipment"]["Hands"] =      Gear[(uint32_t)eItemslot::Hands].Serialize();
        Object["Equipment"]["MainHand"] =   Gear[(uint32_t)eItemslot::Mainhand].Serialize();

        for (auto &Item : Spells)           Object["EquippedSpells"] += Item.Serialize();
        for (auto &Item : Consumables)      Object["EquippedConsumables"] += Item.Serialize();

        if(Stats.Timesplayed) 
            Object["Stats"] =               Stats.Serialize();
        for (auto &Item : Knownregions)     Object["AttackRegions"] +=  Item.Serialize();

        return std::move(Object);
    }
};
Hero_t Currenthero;

// A character with starting-gear.
void World::Hero::Create(eHerotype Class)
{
    Currenthero = Hero_t();

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

// Modify the character.
void World::Hero::IncreaseXP(uint32_t XP)
{
    Currenthero.TotalXP += XP;
}
void World::Hero::Increaselevel(uint32_t Level)
{
    Currenthero.Level += Level;
}
void World::Hero::Increasekillstat(uint32_t Kills)
{
    Currenthero.Stats.Creatureskilled += Kills;
}
void World::Hero::Increaselootstat(uint32_t Looted)
{
    Currenthero.Stats.Castleslooted += Looted;
}
void World::Hero::Increasetimesplayedstat(uint32_t Played)
{
    Currenthero.Stats.Timesplayed += Played;
}
void World::Hero::Equipspell(uint32_t Slot, uint32_t ID)
{
    Currenthero.Spells.push_back({ ID, Slot });
}

/*
    TODO(Convery):
    Load and save the hero to disk.
*/

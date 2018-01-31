/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for attack services.
*/

#pragma once
#include "../../Stdinclude.hpp"

uint64_t CurrentattackID;
constexpr uint64_t TutorialID1 = 12345;
constexpr uint64_t TutorialID2 = 54321;

// Helper.
uint32_t GetCastlelevel()
{
    return 3;
}
MQEL_json GetCastle(uint32_t AccountID)
{
    return MQEL_json::parse(R"({"Result":{"AttackId":"58043d5d5c98320eb4f506fa","Castle":{"$type":"HyperQuest.GameServer.Contracts.UbisoftCastle, HyperQuest.GameServer.Contracts","Level":3,"CastleValidationDuration":44.23333,"AccountId":3000947,"AccountDisplayName":"Hedgehog","LayoutId":1,"CreationDate":"2015-12-27T10:15:45Z","ModificationDate":"2016-01-08T20:11:15Z","Rooms":[{"X":5,"Y":3,"Id":1,"SpecContainerId":21},{"Creatures":[{"RoomZoneId":1,"X":13,"Y":26,"Orientation":3,"Id":40,"SpecContainerId":1081},{"RoomZoneId":1,"X":20,"Y":27,"Orientation":3,"Id":41,"SpecContainerId":1081},{"RoomZoneId":1,"X":19,"Y":27,"Orientation":3,"Id":42,"SpecContainerId":1081},{"RoomZoneId":1,"X":20,"Y":26,"Orientation":3,"Id":43,"SpecContainerId":1081},{"RoomZoneId":1,"X":19,"Y":26,"Orientation":3,"Id":44,"SpecContainerId":1081},{"RoomZoneId":1,"X":12,"Y":26,"Orientation":3,"Id":45,"SpecContainerId":1081},{"RoomZoneId":1,"X":12,"Y":25,"Orientation":3,"Id":46,"SpecContainerId":1081},{"RoomZoneId":1,"X":13,"Y":25,"Orientation":3,"Id":47,"SpecContainerId":1081},{"RoomZoneId":1,"X":15,"Y":14,"Orientation":3,"Id":48,"SpecContainerId":1003}],"Buildings":[{"Rank":3,"RoomZoneId":12,"X":3,"Y":3,"Orientation":2,"Id":1,"SpecContainerId":1},{"Rank":1,"RoomZoneId":11,"Id":2,"SpecContainerId":3},{"Rank":1,"RoomZoneId":13,"Id":3,"SpecContainerId":4},{"Rank":1,"RoomZoneId":7,"X":3,"Orientation":3,"Id":4,"SpecContainerId":13},{"RoomZoneId":4,"X":3,"Orientation":3,"Id":6,"SpecContainerId":10},{"Rank":1,"RoomZoneId":6,"X":3,"Y":3,"Orientation":2,"Id":7,"SpecContainerId":8},{"RoomZoneId":3,"Y":3,"Orientation":1,"Id":8,"SpecContainerId":9},{"Rank":1,"RoomZoneId":1,"X":26,"Y":1,"Orientation":3,"Id":9,"SpecContainerId":5}],"X":3,"Y":3,"Id":3,"SpecContainerId":25},{"Traps":[{"PowerSupplyCastleBuildableId":6,"RoomZoneId":1,"X":33,"Y":17,"Id":5,"SpecContainerId":1004},{"RoomZoneId":1,"X":27,"Y":16,"Id":6,"SpecContainerId":67}],"X":4,"Y":3,"Id":4,"SpecContainerId":5018}],"CreatureTiers":[{"SpecContainerId":1081},{"SpecContainerId":1003}],"TrapTiers":[{"SpecContainerId":1004},{"SpecContainerId":67}],"ThemeId":21},"Level":3,"Hero":{},"AttackerDisplayName":"Hedgehog","CreatureLoot":[{"Id":40,"Gold":3,"Xp":4,"HealthOrbFragments":1,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":2,"ArchetypeId":4,"PrimaryStatsModifiers":[0.566,0.342,0.122],"IsSellable":true,"TemplateId":17}]},{"Id":41,"Gold":2,"Xp":5,"LifeForce":10,"HealthOrbFragments":1,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroConsumableItem, HyperQuest.GameServer.Contracts","StackCount":1,"TemplateId":1000}]},{"Id":42,"Gold":1,"Xp":5,"HealthOrbFragments":1},{"Id":43,"Gold":1,"Xp":5,"LifeForce":2,"HealthOrbFragments":1},{"Id":44,"Gold":2,"Xp":4,"LifeForce":4,"HealthOrbFragments":1},{"Id":45,"Gold":2,"Xp":5,"LifeForce":1,"HealthOrbFragments":1},{"Id":46,"Gold":13,"Xp":5,"LifeForce":1,"HealthOrbFragments":1},{"Id":47,"Gold":2,"Xp":5,"HealthOrbFragments":1},{"Id":48,"Gold":2,"Xp":28,"LifeForce":10,"HealthOrbFragments":24,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":4,"ArchetypeId":3,"PrimaryStatsModifiers":[0.938,0.568,0.491],"IsSellable":true,"TemplateId":205},{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":3,"ArchetypeId":8,"PrimaryStatsModifiers":[0.98,0.24,0.777],"IsSellable":true,"TemplateId":44}]}],"TrapLoot":[{"Id":5,"Gold":1,"Xp":14,"LifeForce":1}],"FirstResurrectionCost":500,"AttackRandomSeed":2109661510,"UnlockedSpells":[{"SpellSpecContainerId":611,"Level":1},{"SpellSpecContainerId":608,"Level":1},{"SpellSpecContainerId":613,"Level":1}],"UnlockedEmotes":[1,2,3],"AttackUserSettings":{},"VictoryConditionRewardRatios":[1,0.75,0.5],"FreeInventorySlotsCount":22,"InventoryConsumablesInfo":[{"TemplateId":1002,"StackCount":2},{"TemplateId":1004,"StackCount":2},{"TemplateId":1011,"StackCount":1},{"TemplateId":1000,"StackCount":1}],"DefenderActiveConsumables":[{"TemplateId":402,"ConsumableType":10}],"TreasureRoomStealableIGC":{"CurrencyType":2,"Amount":7},"TreasureRoomStealableLifeForce":{"CurrencyType":4},"StealableMines":[{"CastleBuildingId":9,"StealableAmount":67,"MaxStealableAmount":67}],"TreasureRoomGoldRatio":0.3,"TreasureRoomLifeForceRatio":0.3,"AttackType":5,"CastleValidationDuration":44.23333,"IsResurrectionAllowed":true}})");
}
MQEL_json GetTutorialcastle(eAttacktype Type)
{
    // Wilderness tutorial.
    if (Type == eAttacktype::None)
    {
        return MQEL_json::parse(R"({"$type":"HyperQuest.GameServer.Contracts.UbisoftCastle, HyperQuest.GameServer.Contracts","IsTutorialCastle":true,"ForceCastleLevelOnBuildables":true,"AccountId":2,"OasisNameId":2325,"LayoutId":1,"Rooms":[{"Triggers":[{"SizeX":18,"SizeY":6,"RoomZoneId":1,"Y":18,"Orientation":1,"Id":1,"SpecContainerId":52}],"X":4,"Y":8,"Orientation":3,"Id":11,"SpecContainerId":7105},{"Creatures":[{"AggroPropagationOffsetX":2.539598,"AggroPropagationOffsetZ":-0.9580116,"RoomZoneId":1,"X":9,"Y":11,"Orientation":3,"Id":45,"SpecContainerId":1081},{"AggroPropagationOffsetX":-0.1254749,"AggroPropagationOffsetZ":-0.4284554,"RoomZoneId":1,"X":14,"Y":21,"Orientation":2,"Id":46,"SpecContainerId":1081},{"AggroPropagationOffsetX":-0.588815,"AggroPropagationOffsetZ":0.1549107,"RoomZoneId":1,"X":9,"Y":28,"Orientation":1,"Id":47,"SpecContainerId":1081},{"AggroPropagationOffsetX":1.657236,"AggroPropagationOffsetZ":-1.133854,"RoomZoneId":1,"X":22,"Y":7,"Orientation":2,"Id":48,"SpecContainerId":1081},{"AggroPropagationOffsetX":-1.982243,"AggroPropagationOffsetZ":0.1102066,"RoomZoneId":1,"X":23,"Y":29,"Orientation":2,"Id":49,"SpecContainerId":1081},{"RoomZoneId":1,"X":26,"Y":18,"Orientation":2,"Id":50,"SpecContainerId":1081}],"Triggers":[{"SizeX":18,"SizeY":6,"RoomZoneId":1,"X":18,"Y":2,"Id":8,"SpecContainerId":52}],"Decorations":[{"RoomZoneId":1,"X":13,"Y":8,"Orientation":3,"Id":115,"SpecContainerId":224},{"RoomZoneId":1,"X":20,"Y":20,"Orientation":2,"Id":116,"SpecContainerId":224},{"RoomZoneId":1,"X":18,"Y":18,"Orientation":2,"Id":118,"SpecContainerId":224},{"RoomZoneId":1,"X":18,"Y":22,"Orientation":2,"Id":119,"SpecContainerId":224},{"RoomZoneId":1,"X":16,"Y":29,"Orientation":3,"Id":120,"SpecContainerId":224},{"RoomZoneId":1,"X":7,"Y":19,"Orientation":3,"Id":131,"SpecContainerId":223},{"RoomZoneId":1,"X":23,"Y":11,"Orientation":2,"Id":126,"SpecContainerId":224},{"RoomZoneId":1,"X":25,"Y":25,"Orientation":3,"Id":139,"SpecContainerId":223},{"RoomZoneId":1,"X":15,"Y":27,"Orientation":3,"Id":166,"SpecContainerId":236},{"RoomZoneId":1,"X":30,"Y":11,"Orientation":2,"Id":167,"SpecContainerId":236},{"RoomZoneId":1,"X":33,"Y":22,"Orientation":2,"Id":169,"SpecContainerId":236},{"RoomZoneId":1,"X":6,"Y":17,"Orientation":3,"Id":170,"SpecContainerId":235},{"RoomZoneId":1,"X":29,"Y":5,"Id":171,"SpecContainerId":235},{"RoomZoneId":1,"X":22,"Y":33,"Orientation":3,"Id":172,"SpecContainerId":236}],"X":4,"Y":7,"Id":26,"SpecContainerId":5025},{"Traps":[{"RoomZoneId":4,"X":17,"Y":33,"Id":1,"SpecContainerId":79},{"RoomZoneId":4,"X":18,"Y":33,"Id":2,"SpecContainerId":79}],"Triggers":[{"SizeX":14,"SizeY":7,"RoomZoneId":1,"X":30,"Y":18,"Orientation":1,"Id":2,"SpecContainerId":52},{"SizeX":2,"SizeY":2,"RoomZoneId":1,"X":24,"Y":18,"Orientation":1,"Id":3,"SpecContainerId":52},{"SizeX":2,"SizeY":2,"RoomZoneId":1,"X":6,"Y":25,"Orientation":1,"Id":4,"SpecContainerId":52},{"SizeX":12,"SizeY":2,"RoomZoneId":1,"X":14,"Y":18,"Orientation":1,"Id":5,"SpecContainerId":52}],"Decorations":[{"RoomZoneId":4,"X":13,"Y":34,"Id":174,"SpecContainerId":236},{"RoomZoneId":4,"X":21,"Y":34,"Id":175,"SpecContainerId":235}],"Buildings":[{"Rank":1,"RoomZoneId":1,"Id":3,"SpecContainerId":1}],"X":4,"Y":3,"Orientation":3,"Id":23,"SpecContainerId":7104},{"Creatures":[{"RoomZoneId":1,"X":21,"Y":18,"Orientation":2,"Id":68,"SpecContainerId":1081},{"RoomZoneId":1,"X":18,"Y":34,"Orientation":3,"Id":58,"SpecContainerId":1029},{"RoomZoneId":1,"X":16,"Y":17,"Id":65,"SpecContainerId":1081}],"Decorations":[{"RoomZoneId":1,"X":20,"Y":13,"Id":110,"SpecContainerId":223},{"RoomZoneId":1,"X":19,"Y":3,"Orientation":3,"Id":111,"SpecContainerId":223},{"RoomZoneId":1,"X":16,"Y":4,"Id":112,"SpecContainerId":223},{"RoomZoneId":1,"X":14,"Y":34,"Orientation":2,"Id":114,"SpecContainerId":224},{"RoomZoneId":1,"X":21,"Y":29,"Id":140,"SpecContainerId":224},{"RoomZoneId":1,"X":13,"Y":22,"Id":141,"SpecContainerId":224},{"RoomZoneId":1,"X":22,"Y":1,"Orientation":3,"Id":143,"SpecContainerId":224},{"RoomZoneId":1,"X":13,"Y":7,"Orientation":1,"Id":142,"SpecContainerId":224},{"RoomZoneId":1,"X":16,"Y":1,"Id":113,"SpecContainerId":223}],"X":4,"Y":6,"Orientation":3,"Id":29,"SpecContainerId":2006},{"Creatures":[{"RoomZoneId":1,"X":24,"Y":19,"Orientation":2,"Id":56,"SpecContainerId":1003},{"AggroPropagationOffsetX":-0.6984169,"AggroPropagationOffsetZ":-0.2310722,"RoomZoneId":1,"X":21,"Y":25,"Orientation":1,"Id":44,"SpecContainerId":1081},{"RoomZoneId":1,"X":20,"Y":13,"Orientation":1,"Id":69,"SpecContainerId":1081},{"RoomZoneId":1,"X":21,"Y":1,"Orientation":1,"Id":81,"SpecContainerId":1001}],"Decorations":[{"RoomZoneId":1,"X":13,"Y":14,"Id":153,"SpecContainerId":155},{"RoomZoneId":1,"X":14,"Y":25,"Orientation":2,"Id":154,"SpecContainerId":155},{"RoomZoneId":1,"X":22,"Y":25,"Orientation":2,"Id":155,"SpecContainerId":155},{"RoomZoneId":1,"X":22,"Y":14,"Orientation":2,"Id":156,"SpecContainerId":155},{"RoomZoneId":1,"X":18,"Y":24,"Orientation":2,"Id":157,"SpecContainerId":154},{"RoomZoneId":1,"X":10,"Y":20,"Orientation":2,"Id":158,"SpecContainerId":154},{"RoomZoneId":1,"X":17,"Y":11,"Orientation":2,"Id":159,"SpecContainerId":154},{"RoomZoneId":1,"X":28,"Y":21,"Orientation":2,"Id":160,"SpecContainerId":154},{"RoomZoneId":1,"X":1,"Y":18,"Orientation":1,"Id":144,"SpecContainerId":224},{"RoomZoneId":1,"X":21,"Orientation":3,"Id":165,"SpecContainerId":238}],"X":4,"Y":4,"Id":36,"SpecContainerId":5020},{"Creatures":[{"RoomZoneId":1,"X":16,"Y":10,"Id":70,"SpecContainerId":1081},{"RoomZoneId":1,"X":26,"Y":16,"Orientation":2,"Id":59,"SpecContainerId":1029},{"RoomZoneId":1,"X":25,"Y":21,"Orientation":1,"Id":57,"SpecContainerId":1029},{"RoomZoneId":1,"X":18,"Y":28,"Orientation":2,"Id":66,"SpecContainerId":1081}],"Triggers":[{"SizeX":14,"SizeY":7,"RoomZoneId":1,"X":17,"Y":32,"Id":6,"SpecContainerId":52},{"SizeX":14,"SizeY":7,"RoomZoneId":1,"X":17,"Y":2,"Id":7,"SpecContainerId":52}],"Decorations":[{"RoomZoneId":1,"X":18,"Y":16,"Orientation":1,"Id":146,"SpecContainerId":224},{"RoomZoneId":1,"X":17,"Y":24,"Orientation":1,"Id":145,"SpecContainerId":224},{"RoomZoneId":1,"X":13,"Y":17,"Orientation":3,"Id":147,"SpecContainerId":223},{"RoomZoneId":1,"X":22,"Y":6,"Orientation":3,"Id":173,"SpecContainerId":236}],"X":4,"Y":5,"Id":39,"SpecContainerId":5020}],"CreatureTiers":[{"SpecContainerId":1081},{"SpecContainerId":1029},{"SpecContainerId":1003},{"SpecContainerId":1001}],"TrapTiers":[{"SpecContainerId":79}],"ThemeId":25})");
    }

    // Castle tutorial.
    else
    {
        return MQEL_json::parse(R"({"$type":"HyperQuest.GameServer.Contracts.UbisoftCastle, HyperQuest.GameServer.Contracts","IsTutorialCastle":true,"ForceCastleLevelOnBuildables":true,"AccountId":3,"AccountDisplayName":"HedgehogCastle","OasisNameId":16675,"LayoutId":1,"Rooms":[{"X":5,"Y":5,"Id":11,"SpecContainerId":22},{"Triggers":[{"SizeX":4,"SizeY":1,"RoomZoneId":1,"X":19,"Y":18,"Orientation":1,"Id":5,"SpecContainerId":52},{"SizeX":20,"SizeY":6,"RoomZoneId":1,"X":5,"Y":18,"Orientation":1,"Id":8,"SpecContainerId":52}],"Buildings":[{"Rank":1,"RoomZoneId":1,"Id":4,"SpecContainerId":1},{"Rank":1,"RoomZoneId":2,"Id":5,"SpecContainerId":3},{"Rank":1,"RoomZoneId":3,"Id":6,"SpecContainerId":4}],"X":5,"Y":1,"Orientation":3,"Id":25,"SpecContainerId":27},{"Creatures":[{"RoomZoneId":1,"X":20,"Y":26,"Orientation":3,"Id":6,"SpecContainerId":1000},{"RoomZoneId":1,"X":17,"Y":19,"Orientation":3,"Id":10,"SpecContainerId":1000},{"RoomZoneId":1,"X":20,"Y":18,"Orientation":3,"Id":7,"SpecContainerId":1000},{"RoomZoneId":1,"X":16,"Y":31,"Orientation":3,"Id":9,"SpecContainerId":1000}],"Triggers":[{"SizeX":14,"SizeY":12,"RoomZoneId":1,"X":35,"Y":17,"Id":1,"SpecContainerId":52}],"Decorations":[{"RoomZoneId":1,"X":16,"Y":15,"Orientation":3,"Id":8,"SpecContainerId":141},{"RoomZoneId":1,"X":25,"Y":22,"Orientation":3,"Id":19,"SpecContainerId":149},{"RoomZoneId":1,"X":32,"Y":13,"Orientation":3,"Id":20,"SpecContainerId":127}],"X":4,"Y":5,"Id":40,"SpecContainerId":7045},{"Creatures":[{"RoomZoneId":1,"X":16,"Y":5,"Orientation":3,"Id":18,"SpecContainerId":1006},{"RoomZoneId":1,"X":20,"Y":5,"Orientation":3,"Id":20,"SpecContainerId":1006},{"RoomZoneId":1,"X":17,"Y":28,"Orientation":3,"Id":37,"SpecContainerId":1000},{"RoomZoneId":1,"X":14,"Y":28,"Id":42,"SpecContainerId":1000},{"RoomZoneId":1,"X":19,"Y":27,"Orientation":1,"Id":43,"SpecContainerId":1000},{"RoomZoneId":1,"X":22,"Y":28,"Id":44,"SpecContainerId":1000},{"RoomZoneId":1,"X":20,"Y":25,"Orientation":3,"Id":45,"SpecContainerId":1000},{"AggroPropagationOffsetX":-3.080803,"AggroPropagationOffsetZ":-0.786087,"RoomZoneId":1,"X":17,"Y":31,"Orientation":2,"Id":46,"SpecContainerId":1000},{"RoomZoneId":1,"X":15,"Y":25,"Orientation":3,"Id":47,"SpecContainerId":1000},{"RoomZoneId":1,"X":17,"Y":11,"Orientation":3,"Id":48,"SpecContainerId":1000},{"RoomZoneId":1,"X":21,"Y":13,"Orientation":2,"Id":49,"SpecContainerId":1000},{"RoomZoneId":1,"X":14,"Y":13,"Orientation":2,"Id":50,"SpecContainerId":1000},{"RoomZoneId":1,"X":18,"Y":14,"Orientation":1,"Id":51,"SpecContainerId":1000}],"Decorations":[{"RoomZoneId":1,"X":13,"Y":24,"Orientation":2,"Id":9,"SpecContainerId":141},{"RoomZoneId":1,"X":22,"Y":35,"Orientation":3,"Id":10,"SpecContainerId":141},{"RoomZoneId":1,"X":22,"Y":26,"Orientation":2,"Id":39,"SpecContainerId":141},{"RoomZoneId":1,"X":19,"Y":25,"Orientation":3,"Id":40,"SpecContainerId":141},{"RoomZoneId":1,"X":16,"Y":32,"Orientation":2,"Id":41,"SpecContainerId":141},{"RoomZoneId":1,"X":20,"Y":17,"Id":43,"SpecContainerId":140},{"RoomZoneId":1,"X":15,"Y":18,"Id":44,"SpecContainerId":140},{"RoomZoneId":1,"X":22,"Y":20,"Orientation":2,"Id":45,"SpecContainerId":141},{"RoomZoneId":1,"X":15,"Y":32,"Id":91,"SpecContainerId":261},{"RoomZoneId":1,"X":21,"Y":4,"Id":92,"SpecContainerId":261},{"RoomZoneId":1,"X":14,"Y":4,"Id":93,"SpecContainerId":261}],"X":5,"Y":2,"Orientation":3,"Id":41,"SpecContainerId":2006},{"Creatures":[{"RoomZoneId":1,"X":12,"Y":11,"Orientation":3,"Id":11,"SpecContainerId":1023},{"RoomZoneId":1,"X":8,"Y":12,"Orientation":3,"Id":15,"SpecContainerId":1023},{"RoomZoneId":1,"X":27,"Y":23,"Orientation":3,"Id":16,"SpecContainerId":1023},{"RoomZoneId":1,"X":17,"Y":35,"Orientation":3,"Id":8,"SpecContainerId":1000},{"RoomZoneId":1,"X":23,"Y":24,"Id":38,"SpecContainerId":1000},{"RoomZoneId":1,"X":28,"Y":26,"Orientation":2,"Id":39,"SpecContainerId":1000},{"RoomZoneId":1,"X":12,"Y":15,"Orientation":3,"Id":40,"SpecContainerId":1000},{"RoomZoneId":1,"X":6,"Y":16,"Id":41,"SpecContainerId":1000}],"Traps":[{"RoomZoneId":1,"X":24,"Y":13,"Id":30,"SpecContainerId":1000},{"RoomZoneId":1,"X":21,"Y":7,"Id":33,"SpecContainerId":1000},{"RoomZoneId":1,"X":29,"Y":12,"Id":29,"SpecContainerId":1000},{"RoomZoneId":1,"X":26,"Y":6,"Id":34,"SpecContainerId":1000}],"Decorations":[{"RoomZoneId":1,"X":22,"Y":32,"Orientation":3,"Id":28,"SpecContainerId":141},{"RoomZoneId":1,"X":15,"Y":35,"Id":11,"SpecContainerId":140},{"RoomZoneId":1,"X":8,"Y":23,"Orientation":2,"Id":30,"SpecContainerId":141},{"RoomZoneId":1,"X":9,"Y":23,"Orientation":2,"Id":31,"SpecContainerId":141},{"RoomZoneId":1,"X":8,"Y":24,"Orientation":1,"Id":32,"SpecContainerId":141},{"RoomZoneId":1,"X":25,"Y":9,"Id":35,"SpecContainerId":140},{"RoomZoneId":1,"X":5,"Y":16,"Id":36,"SpecContainerId":127},{"RoomZoneId":1,"X":20,"Y":25,"Id":67,"SpecContainerId":127},{"RoomZoneId":1,"X":15,"Y":10,"Orientation":2,"Id":68,"SpecContainerId":127},{"RoomZoneId":1,"X":5,"Y":9,"Id":88,"SpecContainerId":261},{"RoomZoneId":1,"X":8,"Y":21,"Id":89,"SpecContainerId":261},{"RoomZoneId":1,"X":15,"Y":34,"Id":90,"SpecContainerId":261}],"X":5,"Y":3,"Orientation":3,"Id":45,"SpecContainerId":7062},{"Creatures":[{"RoomZoneId":1,"X":17,"Y":27,"Orientation":1,"Id":12,"SpecContainerId":1023}],"Traps":[{"RoomZoneId":1,"X":35,"Y":20,"Orientation":2,"Id":25,"SpecContainerId":1000}],"Decorations":[{"RoomZoneId":1,"X":35,"Y":17,"Orientation":2,"Id":7,"SpecContainerId":141},{"RoomZoneId":1,"X":28,"Y":18,"Orientation":2,"Id":27,"SpecContainerId":141},{"RoomZoneId":1,"X":17,"Y":17,"Orientation":2,"Id":85,"SpecContainerId":261},{"RoomZoneId":1,"X":33,"Y":15,"Orientation":2,"Id":86,"SpecContainerId":261},{"RoomZoneId":1,"X":33,"Y":20,"Orientation":2,"Id":87,"SpecContainerId":261}],"X":5,"Y":4,"Orientation":1,"Id":47,"SpecContainerId":7057},{"Creatures":[{"RoomZoneId":1,"X":18,"Y":34,"Orientation":3,"Id":19,"SpecContainerId":1006}],"Traps":[{"RoomZoneId":1,"X":25,"Y":20,"Id":22,"SpecContainerId":1000},{"RoomZoneId":1,"X":27,"Y":10,"Id":24,"SpecContainerId":1000},{"RoomZoneId":1,"X":33,"Y":21,"Id":21,"SpecContainerId":1000},{"RoomZoneId":1,"X":32,"Y":16,"Id":23,"SpecContainerId":1000},{"RoomZoneId":1,"X":24,"Y":14,"Id":26,"SpecContainerId":1000},{"RoomZoneId":1,"X":20,"Y":11,"Id":27,"SpecContainerId":1000},{"RoomZoneId":1,"X":19,"Y":19,"Id":28,"SpecContainerId":1000},{"RoomZoneId":1,"X":7,"Y":16,"Id":32,"SpecContainerId":1000}],"Triggers":[{"SizeX":1,"SizeY":4,"RoomZoneId":1,"X":14,"Y":21,"Orientation":1,"Id":4,"SpecContainerId":52}],"Decorations":[{"RoomZoneId":1,"X":21,"Y":14,"Id":2,"SpecContainerId":141},{"RoomZoneId":1,"X":30,"Y":19,"Id":4,"SpecContainerId":141},{"RoomZoneId":1,"X":29,"Y":13,"Id":5,"SpecContainerId":141},{"RoomZoneId":1,"X":23,"Y":9,"Id":6,"SpecContainerId":141},{"RoomZoneId":1,"X":5,"Y":23,"Id":21,"SpecContainerId":127},{"RoomZoneId":1,"X":22,"Y":22,"Id":23,"SpecContainerId":140},{"RoomZoneId":1,"X":31,"Y":13,"Orientation":3,"Id":25,"SpecContainerId":141},{"RoomZoneId":1,"X":31,"Y":18,"Orientation":3,"Id":26,"SpecContainerId":141},{"RoomZoneId":1,"X":26,"Y":16,"Id":42,"SpecContainerId":141},{"RoomZoneId":1,"X":16,"Y":34,"Id":81,"SpecContainerId":261},{"RoomZoneId":1,"X":5,"Y":17,"Id":83,"SpecContainerId":261},{"RoomZoneId":1,"X":15,"Y":34,"Id":94,"SpecContainerId":140}],"X":4,"Y":4,"Orientation":3,"Id":52,"SpecContainerId":7068}],"CreatureTiers":[{"SpecContainerId":1000},{"SpecContainerId":1006},{"SpecContainerId":1023}],"TrapTiers":[{"SpecContainerId":1000}],"ThemeId":26})");
    }
}
MQEL_json GetCreatureloot()
{
    return MQEL_json::parse(R"([{"Id":45,"Gold":1,"Xp":2,"LifeForce":1,"HealthOrbFragments":1},{"Id":46,"Gold":9,"Xp":2,"LifeForce":1,"HealthOrbFragments":1},{"Id":47,"Gold":1,"Xp":2,"LifeForce":2,"HealthOrbFragments":1},{"Id":48,"Gold":1,"Xp":2,"HealthOrbFragments":1},{"Id":49,"Gold":1,"Xp":2,"LifeForce":1,"HealthOrbFragments":1},{"Id":50,"Gold":3,"Xp":2,"LifeForce":5,"HealthOrbFragments":1},{"Id":68,"Gold":2,"Xp":2,"HealthOrbFragments":1},{"Id":58,"Gold":2,"Xp":8,"LifeForce":4,"HealthOrbFragments":16},{"Id":65,"Gold":1,"Xp":2,"LifeForce":2,"HealthOrbFragments":1},{"Id":56,"Gold":1,"Xp":12,"LifeForce":1,"HealthOrbFragments":24,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":1,"ArchetypeId":9,"PrimaryStatsModifiers":[0.354,0.998,0.021],"Effects":[{"Id":22,"Level":1}],"IsSellable":true,"TemplateId":37},{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":1,"ArchetypeId":8,"PrimaryStatsModifiers":[0.375,0.364,0.821],"IsSellable":true,"TemplateId":40}]},{"Id":44,"Gold":1,"Xp":2,"LifeForce":5,"HealthOrbFragments":1},{"Id":69,"Gold":2,"Xp":2,"HealthOrbFragments":1},{"Id":81,"Gold":1,"Xp":2,"LifeForce":1,"HealthOrbFragments":4},{"Id":70,"Gold":2,"Xp":2,"LifeForce":1,"HealthOrbFragments":1},{"Id":59,"Gold":3,"Xp":8,"LifeForce":2,"HealthOrbFragments":16},{"Id":57,"Gold":1,"Xp":8,"LifeForce":5,"HealthOrbFragments":16},{"Id":66,"Gold":2,"Xp":2,"LifeForce":3,"HealthOrbFragments":1}])");
}
MQEL_json GetTraploot()
{
    return MQEL_json::parse(R"([{"Id":1,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":1,"ArchetypeId":2,"PrimaryStatsModifiers":[1,1,1],"IsSellable":true,"TemplateId":53}]},{"Id":2}])");
}
MQEL_json GetIGCreward()
{
    return MQEL_json::parse(R"({"CurrencyType": 2,"Amount": 10})");
}
MQEL_json GetLifereward()
{
    return MQEL_json::parse(R"({"CurrencyType": 4})");
}
MQEL_json GetMines()
{
    return MQEL_json::parse(R"([{"CastleBuildingId":9,"StealableAmount":67,"MaxStealableAmount":67}])");
}
MQEL_json GetSpells()
{
    return MQEL_json::parse(R"([{"SpellSpecContainerId":611,"Level":1},{"SpellSpecContainerId":608,"Level":1},{"SpellSpecContainerId":613,"Level":1}])");
}
MQEL_json GetAttackerconsumables()
{
    return MQEL_json::parse(R"([{"TemplateId":1002,"StackCount":2},{"TemplateId":1004,"StackCount":2},{"TemplateId":1011,"StackCount":1},{"TemplateId":1000,"StackCount":1}])");
}
MQEL_json GetDefenderconsumables()
{
    return MQEL_json::parse(R"([{"TemplateId":402,"ConsumableType":10}])");
}

// Endpoints.
void StartAttack(Gameserver *Server, std::string Request, std::string Body)
{
    auto Parsed = MQEL_json::parse(Body);
    eAttacksource Attacksource = (eAttacksource)Parsed["attackSource"].get<uint32_t>();
    eAttacktype Attacktype = (eAttacktype)Parsed["attackType"].get<uint32_t>();
    eCastletype Castletype = (eCastletype)Parsed["castleType"].get<uint32_t>();
    bool Tutorial = Attacktype == eAttacktype::None || Attacktype == eAttacktype::Progression;

    // Log this event.
    Infoprint(va("%s a %s-castle from %s",
        [Attacktype]() -> const char *
        {
            switch (Attacktype)
            {
                case eAttacktype::Competition: return "Challenging";
                case eAttacktype::Progression: return "Questing in";
                case eAttacktype::Revenge: return "Taking revenge on";
                case eAttacktype::Validation: return "Validating";
                case eAttacktype::Visit: return "Visiting";
                case eAttacktype::None: return "Querying";
            }
            return "";
        }(),
        [Castletype]() -> const char *
        {
            switch (Castletype)
            {
                case eCastletype::Ubisoft: return "bot";
                case eCastletype::User: return "player";
            }
            return "";
        }(),
        [Attacksource]() -> const char *
        {
            switch (Attacksource)
            {
                case eAttacksource::Chat: return "chat-link";
                case eAttacksource::Competition: return "challenge";
                case eAttacksource::Friends: return "friendslist";
                case eAttacksource::Guild: return "guildpost";
                case eAttacksource::Machinelearning: return "suggestion";
                case eAttacksource::MOTD: return "welcome page";
                case eAttacksource::News: return "notification";
                case eAttacksource::Quest: return "questlog";
                case eAttacksource::Regular: return "worldmap";
            }
            return "";
        }()));

    // Create the attack ID;
    if (!Tutorial) CurrentattackID = time(NULL);
    if (Tutorial && Attacktype == eAttacktype::None) CurrentattackID = TutorialID1;
    if (Tutorial && Attacktype == eAttacktype::Progression) CurrentattackID = TutorialID1;

    // Create the challenge.
    auto Response = MQEL_json::object();
                    Response["Result"]["AttackId"] = va("%x", CurrentattackID);
    if(Tutorial)    Response["Result"]["Castle"] = GetTutorialcastle(Attacktype);
    if(!Tutorial)   Response["Result"]["Castle"] = GetCastle(Parsed["castleAccountId"]);
    if(Tutorial)    Response["Result"]["CastleType"] = Parsed["castleType"].get<uint32_t>();
                    Response["Result"]["Level"] = Tutorial ? 1 : GetCastlelevel();
                    Response["Result"]["Hero"] = World::Hero::Serialize((eHerotype)World::Hero::GetheroID());
                    Response["Result"]["AttackerDisplayName"] = "Hedgehog";
                    Response["Result"]["CreatureLoot"] = GetCreatureloot();
                    Response["Result"]["TrapLoot"] = GetTraploot();
    if(!Tutorial)   Response["Result"]["FirstResurrectionCost"] = 500;
                    Response["Result"]["AttackRandomSeed"] = CurrentattackID;
    if(!Tutorial)   Response["Result"]["UnlockedSpells"] = GetSpells();
                    Response["Result"]["UnlockedEmotes"] = MQEL_json::parse(R"([ 1, 2, 3 ])");
                    Response["Result"]["AttackUserSettings"] = MQEL_json::object();
                    Response["Result"]["VictoryConditionRewardRatios"] = MQEL_json::parse(R"([ 1, 0.75, 0.5 ])");
                    Response["Result"]["FreeInventorySlotsCount"] = 42;
    if(!Tutorial)   Response["Result"]["InventoryConsumablesInfo"] = GetAttackerconsumables();
    if(!Tutorial)   Response["Result"]["DefenderActiveConsumables"] = GetDefenderconsumables();
                    Response["Result"]["TreasureRoomStealableIGC"] = GetIGCreward();
                    Response["Result"]["TreasureRoomStealableLifeForce"] = GetLifereward();
    if(!Tutorial)   Response["Result"]["StealableMines"] = GetMines();
    if(Tutorial)    Response["Result"]["IsTutorial"] = true;
                    Response["Result"]["TreasureRoomGoldRatio"] = 0.3;
                    Response["Result"]["TreasureRoomLifeForceRatio"] = 0.3;
                    Response["Result"]["AttackType"] = Tutorial ? 5 : Parsed["attackType"].get<uint32_t>();
    if(!Tutorial)   Response["Result"]["CastleValidationDuration"] = 44.23333;
                    Response["Result"]["IsResurrectionAllowed"] = true;

    // Return the castle info.
    Sendreply(Server, Response.dump());
}
void EndAttack(Gameserver *Server, std::string Request, std::string Body)
{
    MQEL_json Response;

    // Handle tutorial fights.
    if (CurrentattackID == TutorialID1)
    {
        Response = MQEL_json::parse(R"({"Notifications":[{"$type":"HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts","Amounts":[{"CurrencyType":2,"Amount":33},{"CurrencyType":4,"Amount":33}],"NotificationType":24},{"$type":"HyperQuest.GameServer.Contracts.HeroXpChangedNotification, HyperQuest.GameServer.Contracts","HeroSpecContainerId":4,"XpAdded":60,"TotalXp":60,"Level":1,"NotificationType":43},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":1,"ArchetypeId":9,"PrimaryStatsModifiers":[0.354,0.998,0.021],"Effects":[{"Id":22,"Level":1}],"IsSellable":true,"TemplateId":37},"ItemType":3,"ObjectId":"580d50cd5c98320a9cb0e719"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":1,"ArchetypeId":8,"PrimaryStatsModifiers":[0.375,0.364,0.821],"IsSellable":true,"TemplateId":40},"ItemType":3,"ObjectId":"580d50cd5c98320a9cb0e71a"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":1,"ArchetypeId":2,"PrimaryStatsModifiers":[1,1,1],"IsSellable":true,"TemplateId":53},"ItemType":3,"ObjectId":"580d50cd5c98320a9cb0e71b"}],"NotificationType":111}],"Result":{"AttackId":"580d504f5c98320c1881325a","DefenderCastleId":2,"DefenderCastleType":1,"DefenderOasisNameId":2325,"Duration":119100,"InitialGold":1000,"HeroLevel":1,"TotalXp":60,"TotalGold":33,"TotalLifeForce":33,"KillsXp":60,"KillsGold":33,"KillsLifeForce":33,"CastleRatingFreePrize":{"CurrencyType":2,"Amount":50},"IsTutorial":true,"IsCastleAttackable":true,"UpdatedAccountStats":{"TotalCreaturesKilled":16,"AttackTotalIGCWon":33,"TotalCastlesLooted":1,"CastlesDefeated":{"Medium":1},"KilledCreatures":{"1081":12,"1029":3,"1003":1},"CurrencyAccumulation":{"IGC":33,"LifeForce":33},"DefeatCastleStrike":1,"TotalItemsLooted":3},"TrophyScoreVariation":{},"VictoryConditionRewardRatios":[1,0.75,0.5],"VictoryConditionLevel":1,"MaxVictoryConditionLevel":1,"EnterTreasureRoom":true,"VictoryConditionType":1}})");
    }
    else if (CurrentattackID == TutorialID2)
    {
        Response = MQEL_json::parse(R"({"Notifications":[{"$type":"HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts","Amounts":[{"CurrencyType":2},{"CurrencyType":4,"Amount":29}],"NotificationType":24},{"$type":"HyperQuest.GameServer.Contracts.HeroXpChangedNotification, HyperQuest.GameServer.Contracts","HeroSpecContainerId":4,"XpAdded":66,"TotalXp":1868,"Level":4,"NotificationType":43},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1000},"ItemType":4,"ObjectId":"58043d945c98320eb4f50727"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":2,"ArchetypeId":4,"PrimaryStatsModifiers":[0.566,0.342,0.122],"IsSellable":true,"TemplateId":17},"ItemType":3,"ObjectId":"58043d945c98320eb4f50728"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":3,"ArchetypeId":8,"PrimaryStatsModifiers":[0.98,0.24,0.777],"IsSellable":true,"TemplateId":44},"ItemType":3,"ObjectId":"58043d945c98320eb4f50729"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":4,"ArchetypeId":3,"PrimaryStatsModifiers":[0.938,0.568,0.491],"IsSellable":true,"TemplateId":205},"ItemType":3,"ObjectId":"58043d945c98320eb4f5072a"}],"NotificationType":111}],"Result":{"AttackId":"58043d5d5c98320eb4f506fa","DefenderCastleId":3000947,"DefenderAccountDisplayName":"jonsie111","Duration":49933,"InitialXp":1802,"InitialGold":2000,"HeroLevel":4,"TotalXp":66,"TotalGold":103,"TotalLifeForce":29,"KillsXp":66,"KillsGold":29,"KillsLifeForce":29,"TreasureRoomGold":7,"PillagedIGCMinesAmount":67,"PillagedIGCMineCount":1,"CastleRatingFreePrize":{"CurrencyType":2,"Amount":50},"IsCastleAttackable":true,"UpdatedAccountStats":{"TotalCreaturesKilled":202,"AttackTotalIGCWon":833,"TotalCastlesLooted":10,"CastlesDefeated":{"Medium":5,"Easy":4,"Hard":1},"KilledCreatures":{"1081":86,"1029":7,"1003":2,"1000":21,"1006":3,"1023":4,"1079":8,"1155":1,"1001":24,"1026":9,"1024":7,"1016":5,"1009":6,"1015":13,"1002":6},"CurrencyAccumulation":{"IGC":1300,"LifeForce":1035},"DefeatCastleStrike":4,"TotalItemsLooted":31,"TotalPotionsConsumed":5},"TrophyScoreVariation":{},"VictoryConditionRewardRatios":[1,0.75,0.5],"VictoryConditionLevel":3,"DefenderLossIGC":7,"EnterTreasureRoom":true,"CastleShieldedByAttacker":true,"VictoryConditionType":1,"RevengeEnabled":true,"CastleValidationDuration":44233,"LastComment":{"AttackId":"580238555c98321778c363ba","AccountId":3140910,"Comment":{"Raw":"for beginners..."},"AvatarId":10}}})");
    }
    else
    {
        Response = MQEL_json::parse(R"({"Notifications":[{"$type":"HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts","Amounts":[{"CurrencyType":2},{"CurrencyType":4,"Amount":165}],"NotificationType":24},{"$type":"HyperQuest.GameServer.Contracts.HeroXpChangedNotification, HyperQuest.GameServer.Contracts","HeroSpecContainerId":4,"XpAdded":333,"TotalXp":2201,"Level":4,"NotificationType":43},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":3,"ArchetypeId":10,"PrimaryStatsModifiers":[0.979,0.193,0.183],"IsSellable":true,"TemplateId":318},"ItemType":3,"ObjectId":"58043e625c98320eb4f507ba"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":3,"ArchetypeId":4,"PrimaryStatsModifiers":[0.381,0.771,0.188],"IsSellable":true,"TemplateId":45},"ItemType":3,"ObjectId":"58043e625c98320eb4f507bb"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.ObjectiveCompletedNotification, HyperQuest.GameServer.Contracts","ObjectiveId":302,"NotificationType":14},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1003},"ItemType":4,"ObjectId":"58043e625c98320eb4f507bc"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1003},"ItemType":4,"ObjectId":"58043e625c98320eb4f507bd"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1001},"ItemType":4,"ObjectId":"58043e625c98320eb4f507be"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1001},"ItemType":4,"ObjectId":"58043e625c98320eb4f507bf"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1000},"ItemType":4,"ObjectId":"58043e625c98320eb4f507c0"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.ObjectiveUnlockedNotification, HyperQuest.GameServer.Contracts","AccountObjective":{"ObjectiveId":303,"LastStatusDate":"2016-10-17T02:58:42Z","Status":1},"NotificationType":17}],"Result":{"AttackId":"58043dab5c98320eb4f50743","DefenderCastleId":101,"DefenderCastleType":1,"DefenderAccountDisplayName":"Fendrick's Farm","DefenderOasisNameId":16659,"Duration":172600,"InitialXp":1868,"InitialGold":2000,"HeroLevel":4,"TotalXp":333,"TotalGold":179,"TotalLifeForce":165,"KillsXp":333,"KillsGold":133,"KillsLifeForce":119,"TreasureRoomGold":46,"TreasureRoomLifeForce":46,"CastleRatingFreePrize":{"CurrencyType":2,"Amount":75},"IsTutorial":true,"IsCastleAttackable":true,"UpdatedAccountStats":{"TotalCreaturesKilled":243,"AttackTotalIGCWon":1012,"TotalCastlesLooted":11,"CastlesDefeated":{"Medium":5,"Easy":5,"Hard":1},"KilledCreatures":{"1081":103,"1029":7,"1003":5,"1000":24,"1006":3,"1023":4,"1079":8,"1155":1,"1001":26,"1026":9,"1024":7,"1016":5,"1009":6,"1015":13,"1002":6,"1028":3,"1007":4,"1090":8,"1087":1},"CurrencyAccumulation":{"IGC":1300,"LifeForce":1200},"DefeatCastleStrike":5,"TotalItemsLooted":33,"TotalPotionsConsumed":5},"TrophyScoreVariation":{},"VictoryConditionRewardRatios":[1,0.75,0.5],"VictoryConditionLevel":1,"MaxVictoryConditionLevel":1,"EnterTreasureRoom":true,"VictoryConditionType":1}})");
    }

    // Modify hardcoded data.
    Response["Result"]["AttackId"] = va("%x", CurrentattackID);


    Sendreply(Server, Response.dump());
}
void RateCastle(Gameserver *Server, std::string Request, std::string Body)
{
    World::Wallet::Updateamount(eCurrencytype::IGC, 50);
    Sendreply(Server, World::Wallet::Serialize(eCurrencytype::IGC).dump());
}
void Resurrect(Gameserver *Server, std::string Request, std::string Body)
{
    Response_t Response;
    Response.Set("NextResurrectionCost", 750);
    Response.Set("ResurrectionCost", 500);
    Response.Set("ResurrectionCount", 1);

    World::Wallet::Updateamount(eCurrencytype::IGC, -500);
    Sendreply(Server, Response.toString());
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/AttackService.hqs/StartAttack", StartAttack);
            Mapservice("/AttackService.hqs/EndAttack", EndAttack);
            Mapservice("/AttackService.hqs/RateCastle", RateCastle);
            Mapservice("/AttackService.hqs/Resurrect", Resurrect);
        };
    };
    static Startup Loader{};
}

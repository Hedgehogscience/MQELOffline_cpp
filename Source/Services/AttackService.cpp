/*
    Initial author: Convery (tcn@ayria.se)
    Started: 15-01-2018
    License: MIT
    Notes:
        Provides implementations for attack services.
*/

#pragma once
#include "../Stdinclude.hpp"

// Endpoints.
void StartAttack(Gameserver *Server, std::string Request, std::string Body)
{
    MQEL_json Response = MQEL_json::parse(R"({"Result":{"AttackId":"58043d5d5c98320eb4f506fa","Castle":{"$type":"HyperQuest.GameServer.Contracts.UbisoftCastle, HyperQuest.GameServer.Contracts","Level":3,"CastleValidationDuration":44.23333,"AccountId":3000947,"AccountDisplayName":"Hedgehog","LayoutId":1,"CreationDate":"2015-12-27T10:15:45Z","ModificationDate":"2016-01-08T20:11:15Z","Rooms":[{"X":5,"Y":3,"Id":1,"SpecContainerId":21},{"Creatures":[{"RoomZoneId":1,"X":13,"Y":26,"Orientation":3,"Id":40,"SpecContainerId":1081},{"RoomZoneId":1,"X":20,"Y":27,"Orientation":3,"Id":41,"SpecContainerId":1081},{"RoomZoneId":1,"X":19,"Y":27,"Orientation":3,"Id":42,"SpecContainerId":1081},{"RoomZoneId":1,"X":20,"Y":26,"Orientation":3,"Id":43,"SpecContainerId":1081},{"RoomZoneId":1,"X":19,"Y":26,"Orientation":3,"Id":44,"SpecContainerId":1081},{"RoomZoneId":1,"X":12,"Y":26,"Orientation":3,"Id":45,"SpecContainerId":1081},{"RoomZoneId":1,"X":12,"Y":25,"Orientation":3,"Id":46,"SpecContainerId":1081},{"RoomZoneId":1,"X":13,"Y":25,"Orientation":3,"Id":47,"SpecContainerId":1081},{"RoomZoneId":1,"X":15,"Y":14,"Orientation":3,"Id":48,"SpecContainerId":1003}],"Buildings":[{"Rank":3,"RoomZoneId":12,"X":3,"Y":3,"Orientation":2,"Id":1,"SpecContainerId":1},{"Rank":1,"RoomZoneId":11,"Id":2,"SpecContainerId":3},{"Rank":1,"RoomZoneId":13,"Id":3,"SpecContainerId":4},{"Rank":1,"RoomZoneId":7,"X":3,"Orientation":3,"Id":4,"SpecContainerId":13},{"RoomZoneId":4,"X":3,"Orientation":3,"Id":6,"SpecContainerId":10},{"Rank":1,"RoomZoneId":6,"X":3,"Y":3,"Orientation":2,"Id":7,"SpecContainerId":8},{"RoomZoneId":3,"Y":3,"Orientation":1,"Id":8,"SpecContainerId":9},{"Rank":1,"RoomZoneId":1,"X":26,"Y":1,"Orientation":3,"Id":9,"SpecContainerId":5}],"X":3,"Y":3,"Id":3,"SpecContainerId":25},{"Traps":[{"PowerSupplyCastleBuildableId":6,"RoomZoneId":1,"X":33,"Y":17,"Id":5,"SpecContainerId":1004},{"RoomZoneId":1,"X":27,"Y":16,"Id":6,"SpecContainerId":67}],"X":4,"Y":3,"Id":4,"SpecContainerId":5018}],"CreatureTiers":[{"SpecContainerId":1081},{"SpecContainerId":1003}],"TrapTiers":[{"SpecContainerId":1004},{"SpecContainerId":67}],"ThemeId":21},"Level":3,"Hero":{},"AttackerDisplayName":"Hedgehog","CreatureLoot":[{"Id":40,"Gold":3,"Xp":4,"HealthOrbFragments":1,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":2,"ArchetypeId":4,"PrimaryStatsModifiers":[0.566,0.342,0.122],"IsSellable":true,"TemplateId":17}]},{"Id":41,"Gold":2,"Xp":5,"LifeForce":10,"HealthOrbFragments":1,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroConsumableItem, HyperQuest.GameServer.Contracts","StackCount":1,"TemplateId":1000}]},{"Id":42,"Gold":1,"Xp":5,"HealthOrbFragments":1},{"Id":43,"Gold":1,"Xp":5,"LifeForce":2,"HealthOrbFragments":1},{"Id":44,"Gold":2,"Xp":4,"LifeForce":4,"HealthOrbFragments":1},{"Id":45,"Gold":2,"Xp":5,"LifeForce":1,"HealthOrbFragments":1},{"Id":46,"Gold":13,"Xp":5,"LifeForce":1,"HealthOrbFragments":1},{"Id":47,"Gold":2,"Xp":5,"HealthOrbFragments":1},{"Id":48,"Gold":2,"Xp":28,"LifeForce":10,"HealthOrbFragments":24,"InventoryItems":[{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":4,"ArchetypeId":3,"PrimaryStatsModifiers":[0.938,0.568,0.491],"IsSellable":true,"TemplateId":205},{"$type":"HyperQuest.GameServer.Contracts.HeroEquipmentItem, HyperQuest.GameServer.Contracts","ItemLevel":3,"ArchetypeId":8,"PrimaryStatsModifiers":[0.98,0.24,0.777],"IsSellable":true,"TemplateId":44}]}],"TrapLoot":[{"Id":5,"Gold":1,"Xp":14,"LifeForce":1}],"FirstResurrectionCost":500,"AttackRandomSeed":2109661510,"UnlockedSpells":[{"SpellSpecContainerId":611,"Level":1},{"SpellSpecContainerId":608,"Level":1},{"SpellSpecContainerId":613,"Level":1}],"UnlockedEmotes":[1,2,3],"AttackUserSettings":{},"VictoryConditionRewardRatios":[1,0.75,0.5],"FreeInventorySlotsCount":22,"InventoryConsumablesInfo":[{"TemplateId":1002,"StackCount":2},{"TemplateId":1004,"StackCount":2},{"TemplateId":1011,"StackCount":1},{"TemplateId":1000,"StackCount":1}],"DefenderActiveConsumables":[{"TemplateId":402,"ConsumableType":10}],"TreasureRoomStealableIGC":{"CurrencyType":2,"Amount":7},"TreasureRoomStealableLifeForce":{"CurrencyType":4},"StealableMines":[{"CastleBuildingId":9,"StealableAmount":67,"MaxStealableAmount":67}],"TreasureRoomGoldRatio":0.3,"TreasureRoomLifeForceRatio":0.3,"AttackType":5,"CastleValidationDuration":44.23333,"IsResurrectionAllowed":true}})");


    /* 
        HACK(Convery):
        These values should be set through other serverices.
        The spells here are for Hero 2, need to RE the others.
    */
    World::Hero::Increasekillstat(1);
    World::Hero::Increaselootstat(1);
    World::Hero::Increasetimesplayedstat(1);
    World::Hero::Equipspell(3, 611);
    World::Hero::Equipspell(0, 613);
    World::Hero::IncreaseXP(1000);

    Response["Result"]["Hero"] = World::Hero::Serialize();

    Sendreply(Server, Response.dump());
}
void EndAttack(Gameserver *Server, std::string Request, std::string Body)
{
    MQEL_json Response = MQEL_json::parse(R"({"Notifications":[{"$type":"HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts","Amounts":[{"CurrencyType":2},{"CurrencyType":4,"Amount":29}],"NotificationType":24},{"$type":"HyperQuest.GameServer.Contracts.HeroXpChangedNotification, HyperQuest.GameServer.Contracts","HeroSpecContainerId":4,"XpAdded":66,"TotalXp":1868,"Level":4,"NotificationType":43},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxConsumableItem, HyperQuest.GameServer.Contracts","HeroItem":{"StackCount":1,"TemplateId":1000},"ItemType":4,"ObjectId":"58043d945c98320eb4f50727"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":2,"ArchetypeId":4,"PrimaryStatsModifiers":[0.566,0.342,0.122],"IsSellable":true,"TemplateId":17},"ItemType":3,"ObjectId":"58043d945c98320eb4f50728"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":3,"ArchetypeId":8,"PrimaryStatsModifiers":[0.98,0.24,0.777],"IsSellable":true,"TemplateId":44},"ItemType":3,"ObjectId":"58043d945c98320eb4f50729"}],"NotificationType":111},{"$type":"HyperQuest.GameServer.Contracts.InboxItemsAddedNotification, HyperQuest.GameServer.Contracts","InboxItems":[{"$type":"HyperQuest.GameServer.Contracts.InboxHeroEquipmentItem, HyperQuest.GameServer.Contracts","HeroItem":{"ItemLevel":4,"ArchetypeId":3,"PrimaryStatsModifiers":[0.938,0.568,0.491],"IsSellable":true,"TemplateId":205},"ItemType":3,"ObjectId":"58043d945c98320eb4f5072a"}],"NotificationType":111}],"Result":{"AttackId":"58043d5d5c98320eb4f506fa","DefenderCastleId":3000947,"DefenderAccountDisplayName":"Hedgehog","Duration":49933,"InitialXp":1802,"InitialGold":2000,"HeroLevel":4,"TotalXp":66,"TotalGold":103,"TotalLifeForce":29,"KillsXp":66,"KillsGold":29,"KillsLifeForce":29,"TreasureRoomGold":7,"PillagedIGCMinesAmount":67,"PillagedIGCMineCount":1,"CastleRatingFreePrize":{"CurrencyType":2,"Amount":50},"IsCastleAttackable":true,"UpdatedAccountStats":{"TotalCreaturesKilled":202,"AttackTotalIGCWon":833,"TotalCastlesLooted":10,"CastlesDefeated":{"Medium":5,"Easy":4,"Hard":1},"KilledCreatures":{"1081":86,"1029":7,"1003":2,"1000":21,"1006":3,"1023":4,"1079":8,"1155":1,"1001":24,"1026":9,"1024":7,"1016":5,"1009":6,"1015":13,"1002":6},"CurrencyAccumulation":{"IGC":1300,"LifeForce":1035},"DefeatCastleStrike":4,"TotalItemsLooted":31,"TotalPotionsConsumed":5},"TrophyScoreVariation":{},"VictoryConditionRewardRatios":[1,0.75,0.5],"VictoryConditionLevel":3,"DefenderLossIGC":7,"EnterTreasureRoom":true,"CastleShieldedByAttacker":true,"VictoryConditionType":1,"RevengeEnabled":true,"CastleValidationDuration":44233,"LastComment":{"AttackId":"580238555c98321778c363ba","AccountId":3140910,"Comment":{"Raw":"for beginners..."},"AvatarId":10}}})");

    Sendreply(Server, Response.dump());
}
void RateCastle(Gameserver *Server, std::string Request, std::string Body)
{
    World::Notifications::Enqueue(World::Notifications::Walletupdate({ {eCurrencytype::IGC, 0} }));
    Sendreply(Server, R"({"Result":{"CurrencyType":2}})");
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/AttackService.hqs/StartAttack", StartAttack);
            Mapservice("/AttackService.hqs/EndAttack", EndAttack);
            Mapservice("/AttackService.hqs/RateCastle", RateCastle);
        };
    };
    static Startup Loader{};
}

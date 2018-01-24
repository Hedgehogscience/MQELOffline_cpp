/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Provides implementations for ServerCommand services.
*/

#include "../Stdinclude.hpp"

// Commands that we can process.
void Handletracking(TrackingCommand *Command)
{
    switch (Hash::FNV1a_32(Command->Type.c_str()))
    {
        case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.GameStartTracking, HyperQuest.GameServer.Contracts"):
        {
            Infoprint(va("Starting game-version %s for HWID %s",
                Command->Gamestart._GameClientVersion.get<std::string>().c_str(),
                Command->Gamestart._MachineId.get<std::string>().c_str()));

            break;
        }
        case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.GameStateTracking, HyperQuest.GameServer.Contracts"):
        {
            Debugprint("Gamestate heartbeat");
            break;
        }
        case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.GameInitializeTracking, HyperQuest.GameServer.Contracts"):
        {
            Debugprint("Gamestate epoch-change");
            break;
        }
    }
}
void Handleassignment(AssignmentCommand *Command, bool Completed)
{
    if (!Completed) World::Quests::Start(Command->_AssignmentId);
    else World::Quests::Complete(Command->_AssignmentId);
}
void Handleassignmentupdate(ExecuteAssignmentActionCommand *Command)
{
    World::Quests::Update(Command->_AssignmentId, Command->_ActionIndex);
}
void Handlepurchase(BuyCommand *Command)
{
    Printfunction();

    // Set the max capacity for gold and life.
    World::Wallet::Updateamount(eCurrencytype::IGC, 2000);
    World::Wallet::Updateamount(eCurrencytype::Lifeforce, 2000);

    /* TODO(Convery): Implement these notifications rather than hardcoding. */
    World::Notifications::Enqueue(MQEL_json::parse(R"({"$type":"HyperQuest.GameServer.Contracts.CastleBoughtNotification, HyperQuest.GameServer.Contracts","IsStartupCastle":true,"BuildInfo":{"Draft":{"AccountId":3142975,"LayoutId":1,"CreationDate":"2016-10-23T07:20:03Z","ModificationDate":"2016-10-24T00:00:50Z","Rooms":[{"X":4,"Y":3,"Id":1,"SpecContainerId":21},{"Buildings":[{"Rank":1,"RoomZoneId":12,"X":3,"Y":3,"Orientation":2,"Id":1,"SpecContainerId":1},{"Rank":1,"RoomZoneId":11,"Id":2,"SpecContainerId":3},{"Rank":1,"RoomZoneId":13,"Id":3,"SpecContainerId":4},{"RoomZoneId":7,"X":3,"Orientation":3,"Id":4,"SpecContainerId":13},{"RoomZoneId":4,"X":3,"Orientation":3,"Id":6,"SpecContainerId":10},{"RoomZoneId":6,"X":3,"Y":3,"Orientation":2,"Id":7,"SpecContainerId":8},{"RoomZoneId":3,"Y":3,"Orientation":1,"Id":8,"SpecContainerId":9}],"X":3,"Y":3,"Id":3,"SpecContainerId":25}],"ThemeId":21},"Level":1,"InventoryThemes":[ 2,21],"RoomNextIndex":4,"CreatureNextIndex":40,"TrapNextIndex":5,"DecorationNextIndex":32,"TriggerNextIndex":1,"BuildingNextIndex":9,"CastleStats":{"TotalConstructionPoints":56,"MaxConstructionPoints":56,"WinRatio":0.5,"WinRatioDifficulty":2},"CastleHeartRank":1},"NotificationType":86})"));
    World::Notifications::Enqueue(MQEL_json::parse(R"({"$type":"HyperQuest.GameServer.Contracts.SkusModifiersUpdatedNotification, HyperQuest.GameServer.Contracts","ShopSkuModifiers":[{"SkuCode":"15221","LimitedQuantityMax":15,"LimitedQuantityNextUnlockCastleLevelRequirement":3,"LimitedQuantityNextUnlockQuantity":10},{"SkuCode":"13911","LimitedQuantityMax":1,"LimitedQuantityNextUnlockCastleLevelRequirement":2,"LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15266","LimitedQuantityMax":2},{"SkuCode":"15226","LimitedQuantityMax":20,"LimitedQuantityNextUnlockCastleLevelRequirement":2,"LimitedQuantityNextUnlockQuantity":5},{"SkuCode":"15224","LimitedQuantityMax":2,"LimitedQuantityNextUnlockCastleLevelRequirement":2,"LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15502","LimitedQuantityMax":4},{"SkuCode":"15503","LimitedQuantityMax":4},{"SkuCode":"15504","LimitedQuantityMax":3},{"SkuCode":"15513","LimitedQuantityMax":3},{"SkuCode":"15262","LimitedQuantityNextUnlockCastleLevelRequirement":2,"LimitedQuantityNextUnlockQuantity":4},{"SkuCode":"15229","LimitedQuantityNextUnlockCastleLevelRequirement":3,"LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15220","LimitedQuantityNextUnlockCastleLevelRequirement":4,"LimitedQuantityNextUnlockQuantity":20},{"SkuCode":"15264","LimitedQuantityNextUnlockCastleLevelRequirement":4,"LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15230","LimitedQuantityNextUnlockCastleLevelRequirement":5,"LimitedQuantityNextUnlockQuantity":5},{"SkuCode":"15263","LimitedQuantityNextUnlockCastleLevelRequirement":6,"LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15268","LimitedQuantityNextUnlockCastleLevelRequirement":6,"LimitedQuantityNextUnlockQuantity":5},{"SkuCode":"15225","LimitedQuantityNextUnlockCastleLevelRequirement":7,"LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15467","LimitedQuantityNextUnlockCastleLevelRequirement":8,"LimitedQuantityNextUnlockQuantity":3},{"SkuCode":"15234","LimitedQuantityNextUnlockCastleLevelRequirement":9,"LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16070","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16071","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16072","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16073","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16074","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16075","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16076","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16077","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16078","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16079","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16080","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16049","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15805","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15810","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15811","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15806","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15835","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15807","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15812","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15808","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15804","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15809","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15813","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15825","LimitedQuantityNextUnlockQuantity":3},{"SkuCode":"15834","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15872","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15974","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15957","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15814","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15892","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16067","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15815","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15816","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16068","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15827","LimitedQuantityNextUnlockQuantity":6},{"SkuCode":"15828","LimitedQuantityNextUnlockQuantity":3},{"SkuCode":"15817","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15856","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16006","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16055","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16058","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15818","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15819","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15855","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15890","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16059","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16060","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15820","LimitedQuantityNextUnlockQuantity":3},{"SkuCode":"15821","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15874","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15981","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16064","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16057","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16061","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15822","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16010","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15961","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15853","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15984","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16062","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16063","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15823","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"15830","LimitedQuantityNextUnlockQuantity":3},{"SkuCode":"15977","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16046","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16065","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"16066","LimitedQuantityNextUnlockQuantity":2},{"SkuCode":"15854","LimitedQuantityNextUnlockQuantity":1},{"SkuCode":"16032","LimitedQuantityNextUnlockQuantity":1}],"NotificationType":90})"));
}

// Endpoints.
void SendCommand(Gameserver *Server, std::string Request, std::string Body)
{
    MQEL_json Parsed = MQEL_json::parse(Body);
    MQEL_json Commands = Parsed["commands"];
    MQEL_json Response = MQEL_json::object();

    // Deserialize and handle the commands.
    for (auto &Item : Commands)
    {
        auto Type = Item["$type"].get<std::string>();

        switch (Hash::FNV1a_32(Type.c_str()))
        {
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.TrackingCommand, HyperQuest.GameServer.Contracts"):
            {
                Handletracking(new TrackingCommand(Item));
                break;
            }
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.BuyCommand, HyperQuest.GameServer.Contracts"):
            {
                Handlepurchase(new BuyCommand(Item));
                break;
            }
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.ExecuteAssignmentActionCommand, HyperQuest.GameServer.Contracts"):
            {
                Handleassignmentupdate(new ExecuteAssignmentActionCommand(Item));
                break;
            }
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.StartAssignmentCommand, HyperQuest.GameServer.Contracts"):
            {
                Handleassignment(new AssignmentCommand(Item), false);
                break;
            }
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.CompleteAssignmentCommand, HyperQuest.GameServer.Contracts"):
            {
                Handleassignment(new AssignmentCommand(Item), true);
                break;
            }

            default:
            {
                Debugprint(va("Got an unknown command of type: %s", Type.c_str()));
            }
        }
    }

    Sendreply(Server, Response.dump());
}

// Add the services to the gameserver on startup.
namespace {
    struct Startup {
        Startup()
        {
            Mapservice("/ServerCommandService.hqs/SendCommands", SendCommand);
        };
    };
    static Startup Loader{};
}

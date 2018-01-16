/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Basic requests for the gameserver.
*/

#pragma once
#include "../../Stdinclude.hpp"

// Client information on startup.
struct GameStartTracking : ISerializable
{
    MQEL_json _GameClientVersion;
    MQEL_json _TrackingTagId;
    MQEL_json _CreationDate;
    MQEL_json _MachineId;

    virtual void Deserialize(MQEL_json &Buffer)
    {
        DESERIALIZE(GameClientVersion);
        DESERIALIZE(TrackingTagId);
        DESERIALIZE(CreationDate);
        DESERIALIZE(MachineId);
    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        SERIALIZE(GameClientVersion);
        SERIALIZE(TrackingTagId);
        SERIALIZE(CreationDate);
        SERIALIZE(MachineId);
        return Buffer;
    }
    CONSTRUCT(GameStartTracking);
};

// Client information in heartbeats.
struct GameStateTracking : ISerializable
{
    MQEL_json _GameStateTotalTime;
    MQEL_json _GameStateIdleTime;
    MQEL_json _NextGameStateType;
    MQEL_json _TrackingTagId;
    MQEL_json _GameStateType;
    MQEL_json _CreationDate;
    MQEL_json _GameStateId;

    virtual void Deserialize(MQEL_json &Buffer)
    {
        DESERIALIZE(GameStateTotalTime);
        DESERIALIZE(GameStateIdleTime);
        DESERIALIZE(NextGameStateType);
        DESERIALIZE(TrackingTagId);
        DESERIALIZE(GameStateType);
        DESERIALIZE(CreationDate);
        DESERIALIZE(GameStateId);
    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        SERIALIZE(GameStateTotalTime);
        SERIALIZE(GameStateIdleTime);
        SERIALIZE(NextGameStateType);
        SERIALIZE(TrackingTagId);
        SERIALIZE(GameStateType);
        SERIALIZE(CreationDate);
        SERIALIZE(GameStateId);
        return Buffer;
    }
    CONSTRUCT(GameStateTracking);
};

// Create a new epoch of logs.
struct GameInitializeTracking : ISerializable
{
    MQEL_json _TrackingTagId;
    MQEL_json _CreationDate;

    virtual void Deserialize(MQEL_json &Buffer)
    {
        DESERIALIZE(TrackingTagId);
        DESERIALIZE(CreationDate);
    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        SERIALIZE(TrackingTagId);
        SERIALIZE(CreationDate);
        return Buffer;
    }
    CONSTRUCT(GameInitializeTracking);
};

// Base contract / datatype.
struct TrackingCommand : ISerializable
{
    std::string Type;
    union
    {
        GameStartTracking Gamestart;
        GameStateTracking Gamestate;
        GameInitializeTracking Gameepoch;
    };

    virtual void Deserialize(MQEL_json &Buffer)
    {
        auto Wrapper = Buffer["TrackingTag"];
        Type = Wrapper["$type"].get<std::string>();

        switch (Hash::FNV1a_32(Type.c_str()))
        {
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.GameStartTracking, HyperQuest.GameServer.Contracts"):
            {
                Gamestart = GameStartTracking(Wrapper);
                break;
            }
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.GameStateTracking, HyperQuest.GameServer.Contracts"):
            {
                Gamestate = GameStateTracking(Wrapper);
                break;
            }
            case Hash::FNV1a_32("HyperQuest.GameServer.Contracts.GameInitializeTracking, HyperQuest.GameServer.Contracts"):
            {
                Gameepoch = GameInitializeTracking(Wrapper);
                break;
            }
        }

    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        return Buffer;
    }
    CONSTRUCT(TrackingCommand);
};

// Purchase something.
struct BuyCommand : ISerializable
{
    MQEL_json _ClientCraftingMaterials;
    MQEL_json _ConsumedHeroInventory;
    MQEL_json _DiscountApplied;
    MQEL_json _SkuCode;

    virtual void Deserialize(MQEL_json &Buffer)
    {
        DESERIALIZE(ClientCraftingMaterials);
        DESERIALIZE(ConsumedHeroInventory);
        DESERIALIZE(DiscountApplied);
        DESERIALIZE(SkuCode);
    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        SERIALIZE(ClientCraftingMaterials);
        SERIALIZE(ConsumedHeroInventory);
        SERIALIZE(DiscountApplied);
        SERIALIZE(SkuCode);
        return Buffer;
    }
    CONSTRUCT(BuyCommand);
};

// Start or complete quests.
struct AssignmentCommand : ISerializable
{
    MQEL_json _AssignmentId;

    virtual void Deserialize(MQEL_json &Buffer)
    {
        DESERIALIZE(AssignmentId);
    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        SERIALIZE(AssignmentId);
        return Buffer;
    }
    CONSTRUCT(AssignmentCommand);
};

// Update a quest.
struct ExecuteAssignmentActionCommand : ISerializable
{
    MQEL_json _AssignmentId;
    MQEL_json _ActionIndex;

    virtual void Deserialize(MQEL_json &Buffer)
    {
        DESERIALIZE(AssignmentId);
        DESERIALIZE(ActionIndex);
    }
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        SERIALIZE(AssignmentId);
        SERIALIZE(ActionIndex);
        return Buffer;
    }
    CONSTRUCT(ExecuteAssignmentActionCommand);
};

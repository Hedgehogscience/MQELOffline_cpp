/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Basic telemetry for the gameserver.
*/

#pragma once
#include "../../Stdinclude.hpp"

// Client information on startup.
struct GameStartTracking : ISerializable
{
    nlohmann::json _GameClientVersion;
    nlohmann::json _TrackingTagId;
    nlohmann::json _CreationDate;
    nlohmann::json _MachineId;

    virtual void Deserialize(nlohmann::json &Buffer)
    {
        DESERIALIZE(GameClientVersion);
        DESERIALIZE(TrackingTagId);
        DESERIALIZE(CreationDate);
        DESERIALIZE(MachineId);
    }
    virtual nlohmann::json Serialize()
    {
        nlohmann::json Buffer;
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
    nlohmann::json _GameStateTotalTime;
    nlohmann::json _GameStateIdleTime;
    nlohmann::json _NextGameStateType;
    nlohmann::json _TrackingTagId;
    nlohmann::json _GameStateType;
    nlohmann::json _CreationDate;
    nlohmann::json _GameStateId;

    virtual void Deserialize(nlohmann::json &Buffer)
    {
        DESERIALIZE(GameStateTotalTime);
        DESERIALIZE(GameStateIdleTime);
        DESERIALIZE(NextGameStateType);
        DESERIALIZE(TrackingTagId);
        DESERIALIZE(GameStateType);
        DESERIALIZE(CreationDate);
        DESERIALIZE(GameStateId);
    }
    virtual nlohmann::json Serialize()
    {
        nlohmann::json Buffer;
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
    nlohmann::json _TrackingTagId;
    nlohmann::json _CreationDate;

    virtual void Deserialize(nlohmann::json &Buffer)
    {
        DESERIALIZE(TrackingTagId);
        DESERIALIZE(CreationDate);
    }
    virtual nlohmann::json Serialize()
    {
        nlohmann::json Buffer;
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

    virtual void Deserialize(nlohmann::json &Buffer)
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
    virtual nlohmann::json Serialize()
    {
        nlohmann::json Buffer;
        return Buffer;
    }
    CONSTRUCT(TrackingCommand);
};

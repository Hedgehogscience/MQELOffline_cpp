/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Provides implementations ServerCommand services.
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

void SendCommand(Gameserver *Server, std::string Request, std::string Body)
{
    nlohmann::json Parsed = nlohmann::json::parse(Body);
    nlohmann::json Commands = Parsed["commands"];

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
            default:
            {
                Debugprint(va("Got an unknown command of type: %s", Type.c_str()));
            }
        }
    }

    // No data is returned from this service.
    Sendreply(Server, "{}");
}

// Add the services to the gameserver on startup.
struct Startup {
    Startup()
    {
        Mapservice("/ServerCommandService.hqs/SendCommands", SendCommand);
    };
};
static Startup Loader{};

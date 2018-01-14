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

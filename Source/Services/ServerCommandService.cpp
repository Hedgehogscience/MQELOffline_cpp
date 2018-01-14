/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Provides implementations ServerCommand services.
*/

#include "../Stdinclude.hpp"

void SendCommand(IServer *Server, std::string Request, std::string Body)
{

}

// Add the services to the gameserver on startup.
struct Startup {
    Startup()
    {
        Mapservice("/ServerCommandService.hqs/SendCommands", SendCommand);
    };
};
static Startup Loader{};

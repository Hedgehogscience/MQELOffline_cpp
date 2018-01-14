/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Includes and declares all services.
*/

#pragma once
#include "../Stdinclude.hpp"
#include "Datatypes/ISerializable.hpp"
#include "Datatypes/TrackingCommand.hpp"

using Servicecallback = std::function<void(struct IServer *Server, std::string Request, std::string Body)>;
extern void Mapservice(std::string Request, Servicecallback Callback);
extern std::unordered_map<std::string, Servicecallback> *Servicemap;

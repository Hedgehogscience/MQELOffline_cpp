/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Provides a base for serializable objects.
*/

#pragma once
#include "../../Stdinclude.hpp"
#include <nlohmann/json.hpp>

// Save the authors fingers when creating derived types.
#define DESERIALIZE(Property)   if(!Buffer[#Property].is_null()) _ ##Property = { Buffer[#Property] };
#define CONSTRUCT(Type)         Type() {}; Type(nlohmann::json &Buffer) { Deserialize(Buffer); };
#define SERIALIZE(Property)     Buffer[#Property] = _ ##Property;

// Base structure.
struct ISerializable
{
    virtual void Deserialize(nlohmann::json &Buffer) {}
    virtual nlohmann::json Serialize()
    {
        nlohmann::json Buffer;
        return Buffer;
    }
    CONSTRUCT(ISerializable);
};

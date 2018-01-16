/*
    Initial author: Convery (tcn@ayria.se)
    Started: 14-01-2018
    License: MIT
    Notes:
        Provides a base for serializable objects.
*/

#pragma once
#include "../../Stdinclude.hpp"

// MQEL requires unordered JSON elements. - nlohmann::json issue #485
template<class K, class V, class dummy_compare, class A>
using MQEL_map = nlohmann::fifo_map<K, V, nlohmann::fifo_map_compare<K>, A>;
using MQEL_json = nlohmann::basic_json<MQEL_map>;

// Save the authors fingers when creating derived types.
#define CONSTRUCT(Type)         Type() {}; Type(MQEL_json &Buffer) { Deserialize(Buffer); }; ~Type() {};
#define DESERIALIZE(Property)   if(!Buffer[#Property].is_null()) _ ##Property = { Buffer[#Property] };
#define SERIALIZE(Property)     Buffer[#Property] = _ ##Property;

// Base structure.
struct ISerializable
{
    virtual void Deserialize(MQEL_json &Buffer) {}
    virtual MQEL_json Serialize()
    {
        MQEL_json Buffer;
        return Buffer;
    }
    CONSTRUCT(ISerializable);
};

/*
    Initial author: Convery (tcn@ayria.se)
    Started: 31-01-2018
    License: MIT
    Notes:
        Provides implementations for the frontend.
*/

#pragma once
#include "../Stdinclude.hpp"

namespace Backend
{
    // Quest tracking and management.
    namespace Quest
    {
        void Start(uint32_t QuestID);
        void Complete(uint32_t QuestID);
        std::vector<uint32_t> Getcompleted();
        void Update(uint32_t QuestID, uint32_t ActionID);
    }

    // Notification tracking and management.
    namespace Notification
    {
        std::vector<MQEL_json> Dequeuelocals();
        std::vector<MQEL_json> Dequeueglobals();
        void Enqueuelocal(MQEL_json Notification);
        void Enqueueglobal(MQEL_json Notification);
    }
}

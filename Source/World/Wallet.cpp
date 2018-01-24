/*
    Initial author: Convery (tcn@ayria.se)
    Started: 24-01-2018
    License: MIT
    Notes:
        Provides wealth management for the account.
*/

#include "../Stdinclude.hpp"

namespace World
{
    namespace Wallet
    {
        struct Wallet_t
        {
            int32_t Amount;
            uint32_t Capacity;
        };
        std::array<Wallet_t, (size_t)eCurrencytype::Count> Wallets{};

        // Notifications.
        void NotifyWalletamountupdate(eCurrencytype Type)
        {
            MQEL_json Notification = MQEL_json::object();
            Notification["$type"] = "HyperQuest.GameServer.Contracts.WalletUpdatedNotification, HyperQuest.GameServer.Contracts";

            Notification["Amounts"] += Serialize(Type);

            Notification["NotificationType"] = 24;
            World::Notifications::Enqueue(Notification);
        }
        void NotifyWalletcapacityupdate(eCurrencytype Type)
        {
            MQEL_json Notification = MQEL_json::object();
            Notification["$type"] = "HyperQuest.GameServer.Contracts.WalletCapacityUpdatedNotification, HyperQuest.GameServer.Contracts";

            Notification["CurrencyType"] = (uint32_t)Type;
            Notification["Amount"] = Wallets[(uint32_t)Type].Capacity;

            Notification["NotificationType"] = 47;
            World::Notifications::Enqueue(Notification);
        }

        // Modify the wallet state.
        int32_t Getamount(eCurrencytype Type)
        {
            return Wallets[(size_t)Type].Amount;
        }
        void Setcapacity(eCurrencytype Type, uint32_t Max)
        {
            Wallets[(size_t)Type].Capacity = Max;
            NotifyWalletcapacityupdate(Type);
        }
        void Updateamount(eCurrencytype Type, int32_t Delta)
        {
            Wallets[(size_t)Type].Amount += Delta;
            NotifyWalletamountupdate(Type);
        }

        // Serialize to game-readable JSON.
        MQEL_json Serialize(eCurrencytype Type)
        {
            auto Object = MQEL_json::object();

            Object["CurrencyType"] = (uint32_t)Type;
            if (Wallets[(uint32_t)Type].Amount)
                Object["Amount"] = Wallets[(uint32_t)Type].Amount;

            return std::move(Object);
        }
    }
}

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
            World::Notifications::Enqueuelocal(Notification);
        }
        void NotifyWalletcapacityupdate(eCurrencytype Type)
        {
            MQEL_json Notification = MQEL_json::object();
            Notification["$type"] = "HyperQuest.GameServer.Contracts.WalletCapacityUpdatedNotification, HyperQuest.GameServer.Contracts";

            Notification["CurrencyType"] = (uint32_t)Type;
            Notification["Amount"] = Wallets[(uint32_t)Type].Capacity;

            Notification["NotificationType"] = 47;
            World::Notifications::Enqueuelocal(Notification);
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

        // Load wallet-info on startup and save it on exit.
        void Savewallets()
        {
            auto Object = MQEL_json::object();

            // Serialize the array.
            for (size_t i = 0; i < (size_t)eCurrencytype::Count; ++i)
            {
                Object[va("%i", i)]["Amount"] = Wallets[i].Amount;
                Object[va("%i", i)]["Capacity"] = Wallets[i].Capacity;
            }

            // Save to the archive.
            Package::Write("Wallets.json", Object.dump(4));
        }
        void Loadwallets()
        {
            // Save the wallets on exit.
            std::atexit(Savewallets);

            // Load the file from the archive.
            auto Filebuffer = Package::Read("Wallets.json");
            if (Filebuffer.size() == 0) return;

            // Deserialize the file.
            MQEL_json Object = MQEL_json::parse(Filebuffer);
            for (size_t i = 0; i < (size_t)eCurrencytype::Count; ++i)
            {
                Wallets[i].Amount = Object[va("%i", i)]["Amount"];
                Wallets[i].Capacity = Object[va("%i", i)]["Capacity"];
            }
        }

        // Initialize the questing.
        namespace {
            struct Startup {
                Startup()
                {
                    Loadwallets();
                };
            };
            static Startup Loader{};
        }
    }
}

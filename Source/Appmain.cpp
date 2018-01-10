/*
    Initial author: Convery (tcn@ayria.se)
    Started: 08-01-2018
    License: MIT
    Notes:
        Provides the entrypoint for Windows and Nix.
*/

#include "Stdinclude.hpp"

// Localnetworking callback for server lookups.
extern "C" EXPORT_ATTR IServer *Createserver(const char *Hostname)
{
    /*
        if(std::strstr(Hostname, "auth.domain.com"))
            return new MyAuthserver();
    */

    return nullptr;
}

#if defined _WIN32
BOOLEAN WINAPI DllMain(HINSTANCE hDllHandle, DWORD nReason, LPVOID Reserved)
{
    switch (nReason)
    {
        case DLL_PROCESS_ATTACH:
        {
            // Opt-out of further thread notifications.
            DisableThreadLibraryCalls(hDllHandle);

            // Clear the previous sessions logfile.
            Clearlog();
        }
    }

    return TRUE;
}
#else
__attribute__((constructor)) void DllMain()
{
    // Clear the previous sessions logfile.
    Clearlog();
}
#endif

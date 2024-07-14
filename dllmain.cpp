#include "Includes.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Minerva;

void ShowForm()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Form1());
}

DWORD WINAPI MyThreadFunction(LPVOID lpParam)
{
    ShowForm();
    InitializeHook();
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, MyThreadFunction, NULL, 0, NULL);
        break;
    case DLL_PROCESS_DETACH:
        CleanupHook();
        break;
    }
    return TRUE;
}

#include "Includes.h"

// Initialize the function pointers
ProcessPacket_t oProcessPacket = nullptr;
SendPacket_t oSendPacket = nullptr;

void __fastcall DetourProcessPacket(void* thisptr, void* /*unused*/, CInPacket* a2) {
    
    oProcessPacket(thisptr, a2);
}

void __fastcall DetourSendPacket(void* thisptr, void* /*unused*/, const COutPacket* a2) {
    
    oSendPacket(thisptr, a2);
}

void InitializeHook() {
    Minerva::Form1::Instance->LogMessage("Initializing hooks...");

    if (MH_Initialize() != MH_OK) {
        Minerva::Form1::Instance->LogMessage("MinHook initialization failed!");
        return;
    }

    Minerva::Form1::Instance->LogMessage("Hooking ProcessPacket function...");
    if (MH_CreateHook((LPVOID)ProcessPacketAddress, &DetourProcessPacket, reinterpret_cast<LPVOID*>(&oProcessPacket)) != MH_OK) {
        Minerva::Form1::Instance->LogMessage("Failed to create ProcessPacket hook");
        return;
    }

    if (MH_EnableHook((LPVOID)ProcessPacketAddress) != MH_OK) {
        Minerva::Form1::Instance->LogMessage("Failed to enable ProcessPacket hook");
        return;
    }

    Minerva::Form1::Instance->LogMessage("Hooking SendPacket function...");
    if (MH_CreateHook((LPVOID)SendPacketAddress, &DetourSendPacket, reinterpret_cast<LPVOID*>(&oSendPacket)) != MH_OK) {
        Minerva::Form1::Instance->LogMessage("Failed to create SendPacket hook");
        return;
    }

    if (MH_EnableHook((LPVOID)SendPacketAddress) != MH_OK) {
        Minerva::Form1::Instance->LogMessage("Failed to enable SendPacket hook");
        return;
    }

    Minerva::Form1::Instance->LogMessage("ProcessPacket and SendPacket hooks created and enabled");
}

void CleanupHook() {
    MH_DisableHook((LPVOID)ProcessPacketAddress);
    MH_RemoveHook((LPVOID)ProcessPacketAddress);
    MH_DisableHook((LPVOID)SendPacketAddress);
    MH_RemoveHook((LPVOID)SendPacketAddress);
    MH_Uninitialize();
    Minerva::Form1::Instance->LogMessage("Hooks uninitialized and memory freed");
}

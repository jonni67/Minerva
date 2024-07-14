#include "Includes.h"

// Define the CInPacket structure
struct CInPacket {
    unsigned int    m_bLoopback;
    unsigned int    m_nState;
    unsigned char* m_aRecvBuff;
    unsigned short  m_uLength;
    unsigned short  m_uRawSeq;
    unsigned short  m_uDataLen;
    unsigned int    m_uOffset;
};

// Define the COutPacket structure
struct COutPacket {
    unsigned int    m_bLoopback;
    unsigned char* m_aSendBuff;
    unsigned short  m_uLength;
    unsigned short  m_uRawSeq;
    unsigned short  m_uDataLen;
};

// Function pointers for original functions
typedef void(__thiscall* ProcessPacket_t)(void* thisptr, struct CInPacket* a2);
typedef void(__thiscall* SendPacket_t)(void* thisptr, const struct COutPacket* a2);

// Function prototypes for detour functions
void __fastcall DetourProcessPacket(void* thisptr, void* /*unused*/, CInPacket* a2);
void __fastcall DetourSendPacket(void* thisptr, void* /*unused*/, const COutPacket* a2);

// Function prototypes for hook initialization and cleanup
void InitializeHook();
void CleanupHook();

// External function pointers for original functions
extern ProcessPacket_t oProcessPacket;
extern SendPacket_t oSendPacket;

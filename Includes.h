#pragma once

#include <windows.h>
#include <iostream>
#include <thread>
#include <string>
#include <MinHook.h>

// Include your project-specific headers
#include "MainForm1.h"
#include "PacketHook.h"
#include "Addresses.h"

#if _WIN64 
#pragma comment(lib, "libMinHook.x64.lib")
#else
#pragma comment(lib, "libMinHook.x86.lib")
#endif
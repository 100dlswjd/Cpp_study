// HookDLL.cpp : DLL을 위해 내보낸 함수를 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "HookDLL.h"

#pragma data_seg("SHARED")  // Begin the shared data segment.
// Define simple variables
// Integers, char[] arrays and pointers
// Do not define classes that require 'deep' copy constructors.
HWND g_hInstaller = NULL;
#pragma data_seg()          // End the shared data segment and default back to 
#pragma comment(linker, "/section:SHARED,RWS")

HMODULE g_hMod;
HHOOK g_hKeyHook;
HHOOK g_hMouseHook;

typedef BOOL (WINAPI*FP_PROCESS32NEXTW)(
    HANDLE           hSnapshot,
    LPPROCESSENTRY32W lppe
);

FP_PROCESS32NEXTW g_org_Process32Next;
BOOL HookedProcess32NextW(
    HANDLE            hSnapshot,
    LPPROCESSENTRY32W lppe
)
{
    BOOL bResult = g_org_Process32Next(hSnapshot, lppe);
    if (bResult == FALSE) return FALSE;
    if (lstrcmp(lppe->szExeFile, L"Notepad.exe") == 0)
    {
        OutputDebugString(L"큿 !\n");
        return g_org_Process32Next(hSnapshot, lppe);
    }
    return bResult;
}
typedef
struct _UNICODE_STRING
{
    USHORT  Length;
    USHORT  MaximumLength;
    PWSTR   Buffer;
}
UNICODE_STRING, * PUNICODE_STRING;
typedef enum _SYSTEM_INFORMATION_CLASS
{
    SystemBasicInformation = 0,
    SystemProcessorInformation = 1,             // obsolete...delete
    SystemPerformanceInformation = 2,
    SystemTimeOfDayInformation = 3,
    SystemPathInformation = 4,
    SystemProcessInformation = 5,
    SystemCallCountInformation = 6,
    SystemDeviceInformation = 7,
    SystemProcessorPerformanceInformation = 8,
    SystemFlagsInformation = 9,
    SystemCallTimeInformation = 10,
    SystemModuleInformation = 11,
    SystemLocksInformation = 12,
    SystemStackTraceInformation = 13,
    SystemPagedPoolInformation = 14,
    SystemNonPagedPoolInformation = 15,
    SystemHandleInformation = 16,
    SystemObjectInformation = 17,
    SystemPageFileInformation = 18,
    SystemVdmInstemulInformation = 19,
    SystemVdmBopInformation = 20,
    SystemFileCacheInformation = 21,
    SystemPoolTagInformation = 22,
    SystemInterruptInformation = 23,
    SystemDpcBehaviorInformation = 24,
    SystemFullMemoryInformation = 25,
    SystemLoadGdiDriverInformation = 26,
    SystemUnloadGdiDriverInformation = 27,
    SystemTimeAdjustmentInformation = 28,
    SystemSummaryMemoryInformation = 29,
    SystemMirrorMemoryInformation = 30,
    SystemPerformanceTraceInformation = 31,
    SystemObsolete0 = 32,
    SystemExceptionInformation = 33,
    SystemCrashDumpStateInformation = 34,
    SystemKernelDebuggerInformation = 35,
    SystemContextSwitchInformation = 36,
    SystemRegistryQuotaInformation = 37,
    SystemExtendServiceTableInformation = 38,
    SystemPrioritySeperation = 39,
    SystemVerifierAddDriverInformation = 40,
    SystemVerifierRemoveDriverInformation = 41,
    SystemProcessorIdleInformation = 42,
    SystemLegacyDriverInformation = 43,
    SystemCurrentTimeZoneInformation = 44,
    SystemLookasideInformation = 45,
    SystemTimeSlipNotification = 46,
    SystemSessionCreate = 47,
    SystemSessionDetach = 48,
    SystemSessionInformation = 49,
    SystemRangeStartInformation = 50,
    SystemVerifierInformation = 51,
    SystemVerifierThunkExtend = 52,
    SystemSessionProcessInformation = 53,
    SystemLoadGdiDriverInSystemSpace = 54,
    SystemNumaProcessorMap = 55,
    SystemPrefetcherInformation = 56,
    SystemExtendedProcessInformation = 57,
    SystemRecommendedSharedDataAlignment = 58,
    SystemComPlusPackage = 59,
    SystemNumaAvailableMemory = 60,
    SystemProcessorPowerInformation = 61,
    SystemEmulationBasicInformation = 62,
    SystemEmulationProcessorInformation = 63,
    SystemExtendedHandleInformation = 64,
    SystemLostDelayedWriteInformation = 65,
    SystemBigPoolInformation = 66,
    SystemSessionPoolTagInformation = 67,
    SystemSessionMappedViewInformation = 68,
    SystemHotpatchInformation = 69,
    SystemObjectSecurityMode = 70,
    SystemWatchdogTimerHandler = 71,
    SystemWatchdogTimerInformation = 72,
    SystemLogicalProcessorInformation = 73,
    SystemWow64SharedInformation = 74,
    SystemRegisterFirmwareTableInformationHandler = 75,
    SystemFirmwareTableInformation = 76,
    SystemModuleInformationEx = 77,
    SystemVerifierTriageInformation = 78,
    SystemSuperfetchInformation = 79,
    SystemMemoryListInformation = 80,
    SystemFileCacheInformationEx = 81,
    MaxSystemInfoClass = 82  // MaxSystemInfoClass should always be the last enum

} SYSTEM_INFORMATION_CLASS;
typedef struct __SYSTEM_PROCESS_INFORMATION {
    ULONG NextEntryOffset;
    ULONG NumberOfThreads;
    LARGE_INTEGER WorkingSetPrivateSize;
    ULONG HardFaultCount;
    ULONG NumberOfThreadsHighWatermark;
    ULONGLONG CycleTime;
    LARGE_INTEGER CreateTime;
    LARGE_INTEGER UserTime;
    LARGE_INTEGER KernelTime;
    UNICODE_STRING ImageName;
    LONG BasePriority;
    PVOID UniqueProcessId;
    PVOID InheritedFromUniqueProcessId;
    ULONG HandleCount;
    ULONG SessionId;
    ULONG_PTR UniqueProcessKey;
    ULONG_PTR PeakVirtualSize;
    ULONG_PTR VirtualSize;
    ULONG PageFaultCount;
    ULONG_PTR PeakWorkingSetSize;
    ULONG_PTR WorkingSetSize;
    ULONG_PTR QuotaPeakPagedPoolUsage;
    ULONG_PTR QuotaPagedPoolUsage;
    ULONG_PTR QuotaPeakNonPagedPoolUsage;
    ULONG_PTR QuotaNonPagedPoolUsage;
    ULONG_PTR PagefileUsage;
    ULONG_PTR PeakPagefileUsage;
    ULONG_PTR PrivatePageCount;
    LARGE_INTEGER ReadOperationCount;
    LARGE_INTEGER WriteOperationCount;
    LARGE_INTEGER OtherOperationCount;
    LARGE_INTEGER ReadTransferCount;
    LARGE_INTEGER WriteTransferCount;
    LARGE_INTEGER OtherTransferCount;
} S_SYSTEM_PROCESS_INFORMATION, * P_SYSTEM_PROCESS_INFORMATION;
// NtQuerySystemInformation
#define NTSTATUS ULONG
typedef NTSTATUS(NTAPI* FP_NTQUERSYSTEMINFORMATION)(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID               SystemInformation,
    ULONG                SystemInformationLength,
    PULONG              ReturnLength);

FP_NTQUERSYSTEMINFORMATION g_org_NtQuerySysteminformation = NULL;

#define NTSTATUS LONG
#define STATUS_SUCCESS ((NTSTATUS)0)

NTSTATUS HookedNtQuerySystemInformation(
    SYSTEM_INFORMATION_CLASS SystemInformationClass,
    PVOID               SystemInformation,
    ULONG                SystemInformationLength,
    PULONG              ReturnLength)
{
    NTSTATUS status = g_org_NtQuerySysteminformation(SystemInformationClass
                                                    , SystemInformation
                                                    , SystemInformationLength
                                                    , ReturnLength);
    if (status != STATUS_SUCCESS) return status;
    if (SystemInformationClass == SystemProcessInformation)
    {
        P_SYSTEM_PROCESS_INFORMATION prev = P_SYSTEM_PROCESS_INFORMATION(SystemInformation);
        P_SYSTEM_PROCESS_INFORMATION curr = P_SYSTEM_PROCESS_INFORMATION((PUCHAR)prev + prev->NextEntryOffset);

        while (prev->NextEntryOffset != NULL) {
            if (!lstrcmp(curr->ImageName.Buffer, L"Notepad.exe")) {
                if (curr->NextEntryOffset == 0) {
                    prev->NextEntryOffset = 0;      // if above process is at last
                }
                else {
                    prev->NextEntryOffset += curr->NextEntryOffset;
                }
                curr = prev;
            }
            prev = curr;
            curr = P_SYSTEM_PROCESS_INFORMATION((PUCHAR)curr + curr->NextEntryOffset);
        }
        std::cout << "cut !" << std::endl;
    }
    return g_org_NtQuerySysteminformation(SystemInformationClass
                                        , SystemInformation
                                        , SystemInformationLength
                                        , ReturnLength);
}



// 내보낸 변수의 예제입니다.
HOOKDLL_API int nHookDLL=0;

// 내보낸 함수의 예제입니다.
HOOKDLL_API int fnHookDLL(void)
{
    return 0;
}

LRESULT CALLBACK HookKeyboardProc(int code, WPARAM wParam, LPARAM lParam)
{
    if (code >= HC_ACTION)
    {
        PostMessage(g_hInstaller, WM_KEYHOOK, wParam, lParam);
    }
    return CallNextHookEx(NULL, code, wParam, lParam);
}
LRESULT CALLBACK HookMouseProc(int code, WPARAM wParam, LPARAM lParam)
{
    if (code >= HC_ACTION)
    {
        //PostMessage(g_hInstaller, WM_MOUSEHOOK, wParam, lParam);
        if (wParam == WM_MOUSEMOVE)
        {
            MOUSEHOOKSTRUCT* lpInfo = (MOUSEHOOKSTRUCT*)lParam;
            PostMessage(g_hInstaller, WM_MOUSEHOOK_PT, lpInfo->pt.x , lpInfo->pt.y);
        }
    }
    return CallNextHookEx(NULL, code, wParam, lParam);
}

BOOL InstallHook(HWND hInstaller, DWORD dwHookFlag)
{
    if (dwHookFlag & KEYBOARD_HOOK)
    {        
        HHOOK hKeyHook = SetWindowsHookEx(WH_KEYBOARD, HookKeyboardProc, g_hMod, 0);
        if (hKeyHook == NULL) return FALSE;
        g_hKeyHook = hKeyHook;

    }
    if (dwHookFlag & MOUSE_HOOK)
    {
        HHOOK hMouseHook = SetWindowsHookEx(WH_MOUSE, HookMouseProc, g_hMod, 0);
        if (hMouseHook == NULL) return FALSE;
        g_hMouseHook = hMouseHook;
    }
    g_hInstaller = hInstaller;
    return TRUE;
}

BOOL UnInstallHook(DWORD dwHookFlag)
{
    if (dwHookFlag & KEYBOARD_HOOK)
    {
        UnhookWindowsHookEx(g_hKeyHook);
        g_hKeyHook = NULL;
    }
    if (dwHookFlag & MOUSE_HOOK)
    {
        UnhookWindowsHookEx(g_hMouseHook);
        g_hMouseHook = NULL;
    }
    return TRUE;
}

BOOL InstallAPIHook()
{
    if (MH_Initialize() != MH_OK)
    {
        return FALSE;
    }
    // CreateSnapShot ... Process32Firest, Process32Next
    // 대상조사
    // 대상과 일치하는 함수 포인터 작성
    // 대상 대신 호출될 후킹 함수 작성
    // 훅 설치
    /*
    if (MH_CreateHook((LPVOID)&Process32NextW, (LPVOID)&HookedProcess32NextW, (LPVOID*)&g_org_Process32Next) != MH_OK)
    {
        return FALSE;
    }
    */
    if (MH_CreateHookApi(L"ntdll.dll", "NtQuerySystemInformation"
        , (LPVOID)&HookedNtQuerySystemInformation
        , (LPVOID*)&g_org_NtQuerySysteminformation) != MH_OK)
    {
        return FALSE;
    }
    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
    {
        return FALSE;
    }
    return 1;
}

BOOL UnInstallAPIHook()
{
    if (MH_DisableHook(MH_ALL_HOOKS) != MH_OK)
    {
        return FALSE;
    }
    if (MH_Uninitialize() != MH_OK)
    {
        return FALSE;
    }
    return TRUE;
}

// 내보낸 클래스의 생성자입니다.
CHookDLL::CHookDLL()
{
    return;
}

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
        PostMessage(g_hInstaller, WM_MOUSEHOOK, wParam, lParam);
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

// 내보낸 클래스의 생성자입니다.
CHookDLL::CHookDLL()
{
    return;
}

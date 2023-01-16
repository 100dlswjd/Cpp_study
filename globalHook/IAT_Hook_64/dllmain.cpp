// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include "pch.h"
#include <iostream>
#include <Windows.h>

BOOL g_hook_flag = FALSE;

// using PrototypeMessageBox = int (WINAPI*)(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType);
// PrototypeMessageBox originalMsgBox = MessageBoxA;
//int hookedMessageBox(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
//{
//	MessageBoxW(NULL, L"ddtag 'o' ", L"DDATG o/", 0);
//	return originalMsgBox(hWnd, lpText, lpCaption, uType);
//}

using PrototypeSetWindowTextW = int (WINAPI*)(HWND hWnd, LPCWSTR lpString);
PrototypeSetWindowTextW orignalSetWindowTextW = SetWindowTextW;

int hookedSetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
	//MessageBoxW(NULL, L"ddatg..", L"Hook!!!!!!!!!!!!!", MB_OK);
	
	if (lstrcmpW(lpString, L"durige~") == 0)
	{
		
		std::wstring mywstring = std::wstring(lpString) + L"~ddatG";

		return orignalSetWindowTextW(hWnd, (LPCWSTR)mywstring.c_str());
	}

	return orignalSetWindowTextW(hWnd, lpString);
}

BOOL IAT_Hook()
{
    LPVOID imageBase = GetModuleHandleA(NULL);
    PIMAGE_DOS_HEADER dosHeaders = (PIMAGE_DOS_HEADER)imageBase;
    PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((UINT_PTR)imageBase + dosHeaders->e_lfanew);
    PIMAGE_IMPORT_DESCRIPTOR importDescriptor = NULL;
    IMAGE_DATA_DIRECTORY importsDirectory = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(importsDirectory.VirtualAddress + (UINT_PTR)imageBase);

    LPCSTR libraryName = NULL;
    HMODULE library = NULL;
    PIMAGE_IMPORT_BY_NAME functionName = NULL;

	while (importDescriptor->Name != NULL)
	{
		libraryName = (LPCSTR)importDescriptor->Name + (UINT_PTR)imageBase;
		library = LoadLibraryA(libraryName);
		OutputDebugString(L"Hello ?");
		std::string name = libraryName;
		if (name == "USER32.dll")
		{
			OutputDebugString(L"Hello 0");
			if (library)
			{
				OutputDebugString(L"Hello 0-1");
				PIMAGE_THUNK_DATA originalFirstThunk = NULL, firstThunk = NULL;
				originalFirstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->OriginalFirstThunk);
				firstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->FirstThunk);

				while (originalFirstThunk->u1.AddressOfData != NULL)
				{
					functionName = (PIMAGE_IMPORT_BY_NAME)((UINT_PTR)imageBase + originalFirstThunk->u1.AddressOfData);

					OutputDebugString(L"Hello 1");
					if (std::string(functionName->Name).compare("SetWindowTextW") == 0)
					{
						SIZE_T bytesWritten = 0;
						DWORD oldProtect = 0;
						VirtualProtect((LPVOID)(&firstThunk->u1.Function), 8, PAGE_READWRITE, &oldProtect);

						firstThunk->u1.Function = (UINT_PTR)hookedSetWindowTextW;
						OutputDebugString(L"Hook Ok");
					}
					++originalFirstThunk;
					++firstThunk;
				}
			}
		}
		// 증가
		importDescriptor++;
	}
	return TRUE;
}

BOOL IAT_UnHook()
{
	LPVOID imageBase = GetModuleHandleA(NULL);
	PIMAGE_DOS_HEADER dosHeaders = (PIMAGE_DOS_HEADER)imageBase;
	PIMAGE_NT_HEADERS ntHeaders = (PIMAGE_NT_HEADERS)((UINT_PTR)imageBase + dosHeaders->e_lfanew);
	PIMAGE_IMPORT_DESCRIPTOR importDescriptor = NULL;
	IMAGE_DATA_DIRECTORY importsDirectory = ntHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	importDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)(importsDirectory.VirtualAddress + (UINT_PTR)imageBase);

	LPCSTR libraryName = NULL;
	HMODULE library = NULL;
	PIMAGE_IMPORT_BY_NAME functionName = NULL;

	while (importDescriptor->Name != NULL)
	{
		libraryName = (LPCSTR)importDescriptor->Name + (UINT_PTR)imageBase;
		library = LoadLibraryA(libraryName);
		
		std::string name = libraryName;
		if (name == "USER32.dll")
		{
			if (library)
			{
				PIMAGE_THUNK_DATA originalFirstThunk = NULL, firstThunk = NULL;
				originalFirstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->OriginalFirstThunk);
				firstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->FirstThunk);

				while (originalFirstThunk->u1.AddressOfData != NULL)
				{
					functionName = (PIMAGE_IMPORT_BY_NAME)((UINT_PTR)imageBase + originalFirstThunk->u1.AddressOfData);

					if (std::string(functionName->Name).compare("SetWindowTextW") == 0)
					{
						SIZE_T bytesWritten = 0;
						DWORD oldProtect = 0;
						VirtualProtect((LPVOID)(&firstThunk->u1.Function), 8, PAGE_EXECUTE_READWRITE, &oldProtect);

						firstThunk->u1.Function = (UINT_PTR)orignalSetWindowTextW;
					}
					++originalFirstThunk;
					++firstThunk;
				}
			}
		}
		// 증가
		importDescriptor++;
	}
	return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		IAT_Hook();
		MessageBoxW(NULL, L"Hook", L"HookingMessage!!", MB_OK);
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
		IAT_UnHook();
		MessageBoxW(NULL, L"Hook", L"HookingOut", MB_OK);
        break;
    }
    return TRUE;
}


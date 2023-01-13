#include<iostream>
#include<Windows.h>
#include<TlHelp32.h>

#define EJECT 0
#define INJECT 1

BOOL InjectDll(DWORD dwPID, std::wstring DllPath)
{
	HANDLE hProcess = NULL, hThread = NULL;
	HMODULE hMod = NULL;
	LPVOID pRemoteBuf = NULL;
	DWORD dwBufSize = (DWORD)DllPath.size() * sizeof(wchar_t);
	LPTHREAD_START_ROUTINE pThreadProc;

	if (!(hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID)))
		return FALSE;

	pRemoteBuf = VirtualAllocEx(hProcess, NULL, dwBufSize, MEM_COMMIT, PAGE_READWRITE);
	std::cout << pRemoteBuf << std::endl;
	WriteProcessMemory(hProcess, pRemoteBuf, (LPVOID)DllPath.c_str(), dwBufSize, NULL);

	hMod = GetModuleHandle(L"kernel32.dll");
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(hMod, "LoadLibraryW");

	hThread = CreateRemoteThread(hProcess, NULL, 0, pThreadProc, pRemoteBuf, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);

	CloseHandle(hThread);
	CloseHandle(hProcess);

	return TRUE;
}

BOOL EjectDll(DWORD dwPID, std::wstring DllPath)
{
	BOOL bMore = FALSE, bFound = FALSE;
	HANDLE hSnapShot, hProcess, hThread;
	HMODULE hModule = NULL;
	MODULEENTRY32 me = { sizeof(me) };
	LPTHREAD_START_ROUTINE pThreadProc;

	hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);

	bMore = Module32First(hSnapShot, &me);
	for (; bMore; bMore = Module32Next(hSnapShot, &me))
	{
		if ((me.szExePath == DllPath) || (me.szModule == DllPath))
		{
			std::wcout << DllPath << std::endl;
			std::wcout << "dll 찾음 " << me.szModule << std::endl;
			bFound = TRUE;
			break;
		}
	}
	if (!bFound)
	{
		CloseHandle(hSnapShot);
		return FALSE;
	}

	if (!(hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID)))
		return FALSE;
	
	hModule = GetModuleHandle(L"kernel32.dll");
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(hModule, "FreeLibrary");

	hThread = CreateRemoteThread(hProcess, NULL, 0, pThreadProc, me.modBaseAddr, 0, NULL);
	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	CloseHandle(hProcess);
	CloseHandle(hSnapShot);
	return TRUE;
}

BOOL Injector(std::wstring ProcessName, std::wstring szDllPath, int injectMode)
{
	DWORD PID = 0;
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (hSnapShot == INVALID_HANDLE_VALUE)
		return FALSE;

	PROCESSENTRY32 pe = { 0, };
	pe.dwSize = sizeof(pe);

	Process32First(hSnapShot, &pe);
	do
	{
		PID = pe.th32ProcessID;		
		int result = (pe.szExeFile == ProcessName);

		if (result)
		{
			std::cout << "PID : " << PID << std::endl;
			if (injectMode == INJECT)
			{
				InjectDll(PID, szDllPath);
				std::cout << "인젝션" << std::endl;
			}
			else
			{
				EjectDll(PID, szDllPath);
				std::cout << "이젝션 "<< std::endl;
			}
		}

	} while (Process32Next(hSnapShot, &pe));
	CloseHandle(hSnapShot);
	return TRUE;
}

int main()
{
	// Hook86, Hook64 
	// UnHook86, UnHook64

	std::wstring file = L"C:\\Users\\USER\\source\\repos\\globalHook\\x64\\Debug\\Hook64.dll";
	//file = L"Hook64.dll";
	std::cout << "Hello world" << std::endl;
	Injector(L"notepad.exe", file, EJECT);
	return 0;
}
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
			if (injectMode == INJECT)
			{
				InjectDll(PID, szDllPath);
				std::cout << "PID : " << PID << std::endl;
				std::cout << "인젝션" << std::endl;
			}
			else
			{
				std::cout << "이젝션" << std::endl;
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
	std::cout << "Hello durige" << std::endl;
	Injector(L"Taskmgr.exe", file, INJECT);
	return 0;
}
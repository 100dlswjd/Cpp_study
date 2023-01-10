#include<iostream>
#include<vector>
#include<Windows.h>
#include<TlHelp32.h>
#include<string>

struct proc_info
{
	std::wstring name;
	DWORD pid;
};

std::vector <proc_info> get_process_list()
{
	std::vector <proc_info> proc_list;
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 pe = { 0, };

	pe.dwSize = sizeof(pe);

	Process32First(hSnapShot, &pe);
	do
	{
		proc_info asd = proc_info{ pe.szExeFile, pe.th32ProcessID };
		proc_list.push_back(asd);

	} while (Process32Next(hSnapShot, &pe));

	CloseHandle(hSnapShot);

	return proc_list;
}

struct mod_info
{
	std::wstring mod_name;
};

std::vector <mod_info> get_module_list(DWORD pid)
{
	std::vector <mod_info> mod_list;
	MODULEENTRY32 me = { sizeof(me) };
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
	BOOL bMore = Module32First(hSnapShot, &me);

	for (; bMore; bMore = Module32Next(hSnapShot, &me))
	{
		mod_info a = mod_info{ me.szModule };
		mod_list.push_back(a);
	}
	return mod_list;
}

int find_process(std::wstring ProcessName)
{
	auto info = get_process_list();
	for (auto a : info)
	{
		if (a.name == ProcessName)
		{
			std::cout << "찾음 : " << a.pid << std::endl;
			return a.pid;
		}
	}
	std::cout << "못찾음! " << std::endl;
	return 0;
}
// 프로세스 이름과 모듈 이름을 받음
// 리턴 값은 해당 프로세스에 모듈이 있는지 없는지 검사함

BOOL proc_module_info(std::wstring ProcessName, std::wstring ModuleName)
{
	int pid = find_process(ProcessName);
	if (pid == 0)
	{
		std::cout << "해당 프로세스 없음" << std::endl;
		return FALSE;
	}
	std::vector<mod_info> mod_list = get_module_list((DWORD)pid);
	for (auto a : mod_list)
	{
		//std::wcout << a.mod_name << std::endl;
		if (a.mod_name == ModuleName)
			return TRUE;
	}
	return FALSE;
}


int main()
{
	BOOL check= proc_module_info(L"notepad.exe", L"KERNEL32.DLL");
	if (check== TRUE)
		std::cout << "굿 있음" << std::endl;
	return 0;
}
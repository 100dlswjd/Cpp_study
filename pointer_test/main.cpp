#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>


bool get_process_list(PROCESSENTRY32 *process_list, int size)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapShot == INVALID_HANDLE_VALUE)
		return FALSE;

	PROCESSENTRY32 pe = { 0, };
	pe.dwSize = sizeof(pe);
	
	Process32First(hSnapShot, &pe);
	int cur_count = 0;
	do
	{
		if (cur_count >= size)
			break;
		process_list[cur_count++] = pe;		

	} while (Process32Next(hSnapShot, &pe));
	CloseHandle(hSnapShot);
	return TRUE;
}

int main()
{
	setlocale(LC_ALL, "");
	PROCESSENTRY32 buf[20];
	int buf_len = sizeof(buf) / sizeof(PROCESSENTRY32);
	if (get_process_list(buf, buf_len))
	{
		for (int i = 0; i < buf_len; i++)
			printf("%ws", buf[i].szExeFile);
	}
	return 0;
}
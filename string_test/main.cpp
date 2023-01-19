#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>


int Mystrlen(const char* str)
{	
	int size = 0;
	char break_str = '\0';

	for (int i = 0; ; i++, size++)
	{
		if (str[i] == break_str)
			break;
	}	
	return size;
}

int MystrlenW(const wchar_t* str)
{
	int size = 0;
	wchar_t break_str = L'\0';

	for (int i = 0; ; i++, size++)
	{
		if (str[i] == break_str)
			break;
	}
	return size;
}

bool Mycmp(const char* str1, const char* str2)
{
	int str1_len = Mystrlen(str1);
	int str2_len = Mystrlen(str2);
	int loop_size = min(str1_len, str2_len);
	for (int i = 0; i < loop_size; i++)
	{
		if (str1[i] != str2[i])
			return FALSE;
	}
	return TRUE;
}


void my_strreplace(char* str, const char before, const char after)
{
	int str_len = Mystrlen(str);

	for (int i = 0; i < str_len; i++)
	{
		if (str[i] == before)
			str[i] = after;
	}
}

bool MycmpW(const wchar_t* str1, const wchar_t* str2)
{
	int str1_len = MystrlenW(str1);
	int str2_len = MystrlenW(str2);

	int loop_size = min(str1_len, str2_len);
	if (loop_size == 0)
		return FALSE;
	for (int idx = 0; idx < loop_size; idx++)
	{
		if (str1[idx] != str2[idx])
			return FALSE;
	}
	return TRUE;
}

bool ansi_to_wide(const char * str, wchar_t *dest, int size)
{	
	int result = MultiByteToWideChar(CP_ACP, 0, str, -1, dest, size);
	return result != 0;
}

bool find_process(const char* process_name)
{
	WCHAR wide_proc_name[255] = { 0, };
	if (ansi_to_wide(process_name, wide_proc_name, 255) == false)
		return FALSE;

	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapShot == INVALID_HANDLE_VALUE)
		return FALSE;

	PROCESSENTRY32 pe = { 0, };
	pe.dwSize = sizeof(pe);

	Process32First(hSnapShot, &pe);
	do
	{
		if (MycmpW(pe.szExeFile, wide_proc_name))
		{
			CloseHandle(hSnapShot);
			return TRUE;
		}

	} while (Process32Next(hSnapShot, &pe));
	CloseHandle(hSnapShot);
	return FALSE;
}

int main()
{
	setlocale(LC_ALL, "");
	const char* item = "사과1";
	//char item1[] = "사과";
	const char* item2 = "사3과";
	char item3[] = "teduri";
	const wchar_t* witem1 = L"사과";
	LPCWSTR witem2 = L"사과";

	// LPSTR item3 = "teduri";

	/*
	char item4[255] = {0,};

	for (int idx = 0; idx < Mystrlen(item); idx++)
	{
		item4[idx] = item[idx];
	}
	if (Mycmp(item, item2))
		printf("같음");

	my_strreplace(item3, 't', 'g');

	printf("%s", item3);

	memcpy(item4, item, Mystrlen(item));
	printf("%s", item4);

	if (MycmpW(witem1, L"사과"))
		printf("같음");
	*/

	if (find_process("notepad.exe"))
		printf("찾음");

	return 0;
}
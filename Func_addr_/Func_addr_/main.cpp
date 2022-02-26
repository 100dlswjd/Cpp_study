#include<iostream>
#include<windows.h>
#include<string>

typedef FARPROC (WINAPI* FP_GETPROCADDRESS)(HMODULE, LPCSTR);

int main()
{
	HMODULE hMod = GetModuleHandle(L"Kernel32.dll");
	if (hMod == NULL)
	{
		std::cout << "not module !" << std::endl;
		return 1;
	}

	std::cout << "good module : " << hMod << std::endl;

	FARPROC addr = GetProcAddress(hMod, "GetProcAddress");
	if (hMod == NULL)
	{
		std::cout << "not proc !" << std::endl;
		return 1;
	}
	std::cout << "addr1 : " << addr << std::endl;
	
	FP_GETPROCADDRESS test_func = (FP_GETPROCADDRESS)addr;

	FARPROC test_addr = test_func(hMod, "GetProcAddress");
	if (test_addr == NULL)
	{
		std::cout << "not test_addr !" << std::endl;
		return 1;
	}

	std::cout << "addr2 : " << test_addr << std::endl;
	return 0;
}
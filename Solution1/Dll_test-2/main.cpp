#include<iostream>
#include<windows.h>

typedef int(*DLL_ADD)(int a, int b);

int main()
{
	HMODULE hMod = LoadLibrary(L"C:\\Users\\in\\Desktop\\github\\100dlswjd\\Cpp_study\\Solution1\\x64\\Debug\\Dlltest.dll");
	if (hMod == NULL)
	{
		std::cout << "���� !" << std::endl;
		return 0;
	}
	else std::cout << "���� !" << std::endl;

	FARPROC addr = GetProcAddress(hMod, "add2");

	if (addr == NULL) std::cout << "add �Լ� ���� !" << std::endl;
	else std::cout << "add �Լ� �ּ� : " << addr << std::endl;

	return 1;
}
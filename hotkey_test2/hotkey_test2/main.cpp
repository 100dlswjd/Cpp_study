#include <iostream>
#include <windows.h>

int main()
{
	BOOL bResult = RegisterHotKey(NULL, 1, 0, VK_SPACE);
	if (bResult == FALSE)
	{
		std::cout << "RegisterHotkey Faill..." << std::endl;
		return 0;
	}
	MSG msg = { 0, };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (msg.message = WM_HOTKEY)
		{
			std::cout << "key press" << std::endl;
		}
	}
	
	UnregisterHotKey(NULL, 1);
	return 1;
}
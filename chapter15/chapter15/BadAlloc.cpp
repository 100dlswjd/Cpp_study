/*
#include <iostream>
#include <new>

int main(void)
{
	int num = 0;

	try
	{
		while (1)
		{
			num++;
			std::cout << num << "��° �Ҵ� �õ�" << std::endl;
			new int[10000][10000];
		}
	}
	catch (std::bad_alloc &bad)
	{
		std::cout << bad.what() << std::endl;
		std::cout << "stop!" << std::endl;
	}
	return 0;
}
*/
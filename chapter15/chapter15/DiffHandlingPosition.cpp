/*
#include <iostream>
#include <cstring>
#include <cmath>

int StoI(char* str)
{
	int len = strlen(str);
	int num = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] < '0' || str[i] >'9')
			throw str[i];
		num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
	}
	return num;
}

int main(void)
{
	char str1[100];
	char str2[200];

	while (1)
	{
		std::cout << "두개의 숫자 입력 : ";
		std::cin >> str1 >> str2;

		try
		{
			std::cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << std::endl;
			break;
		}
		catch (char ch)
		{
			std::cout << " 문자 " << ch << "가 입력되었습니다." << std::endl;
			std::cout << "재입력 진행합니다." << std::endl << std::endl;
		}
	}
	std::cout << "프로그램을 종료합니다." << std::endl;
	return 0;
}
*/
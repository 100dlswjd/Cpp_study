#include <iostream>

int main(void)
{
	int num1, num2;
	std::cout << "두개의 숫자 입력 : ";
	std::cin >> num1 >> num2;
	if (num2 == 0)
	{
		std::cout << "제수는 0이 될수 없습니다." << std::endl;
		std::cout << "프로그램을 다시 실행 하세요.," << std::endl;
	}
	else
	{
		std::cout << "나눗셈 몫 : " << num1 / num2 << std::endl;
		std::cout << "나눗셈의 나머지 : " << num1 % num2 << std::endl;
	}
	return 0;
}
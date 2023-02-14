#include <iostream>

void ShowString(char* str)
{
	std::cout << str << std::endl;
}

void ShowAddResult(int& n1, int& n2)
{
	std::cout << n1 + n2 << std::endl;
}

int main(void)
{
	const char* name = "Test ddat";	
	ShowString(const_cast<char*>(name));

	const int& num1 = 100;
	const int& num2 = 200;
	ShowAddResult(const_cast<int&>(num1), const_cast<int&>(num2));

	return 0;
}
#include <iostream>

template <typename T>

T Add(T num1, T num2)
{
	std::cout << "T Add(T num1, T num2)" << std::endl;
	return num1 + num2;
}

int Add(int num1, int num2)
{
	std::cout << "int Add(int num1, int num2)" << std::endl;
	return num1 + num2;
}

double Add(double num1, double num2)
{
	std::cout << "double Add(double num1, double num2)" << std::endl;
	return num1 + num2;
}

int main(void)
{
	std::cout << Add(5, 7) << std::endl;
	std::cout << Add(3.7, 7.5) << std::endl;
	std::cout << Add<int>(5, 7) << std::endl;
	std::cout << Add<double>(3.7, 7.5) << std::endl;
	return 0;
}
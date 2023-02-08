#include <iostream>

template <typename T>
T Add(T num1, T num2) {
	return num1 + num2;
}

int main(void)
{
	std::cout << Add(15, 20) << std::endl;
	std::cout << Add(2.9, 3.7) << std::endl;
	std::cout << Add(3.2, 3.2) << std::endl;
	std::cout << Add(3.14, 2.75) << std::endl;
}
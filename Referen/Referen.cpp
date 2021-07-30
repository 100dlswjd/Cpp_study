#include<iostream>

int main(void) {
	int num1 = 1020;
	int& num2 = num1;

	num2 = 3047;
	std::cout << "VAL : " << num1 << std::endl;
	std::cout << "REF : " << num2 << std::endl;

	std::cout << "VAL : " << &num1 << std::endl;
	std::cout << "REF : " << &num2 << std::endl;
	return 0;
}
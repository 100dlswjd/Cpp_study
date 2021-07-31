#include<iostream>

int& RefRetFunOne(int& ref) {
	ref++;
	return ref;
}

int main(void) {
	int num1 = 1;
	int& num2 = RefRetFunOne(num1);

	num1++;
	num2++;
	std::cout << "num1 : " << num1 << std::endl;
	std::cout << "num2 : " << num2 << std::endl;
	return 0;
}
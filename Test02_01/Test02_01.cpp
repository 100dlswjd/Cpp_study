#include<iostream>

void adder(int& num) {
	num += 1;
}

int main() {
	int number = 20;
	adder(number);

	std::cout << "number : " << number << std::endl;
}
#include<iostream>

int main(void){
	int arr[3] = { 1,3,5 };
	int& ref1 = arr[0];
	int& ref2 = arr[1];
	int& ref3 = arr[2];

	std::cout << ref1 << std::endl;
	std::cout << ref2 << std::endl;
	std::cout << ref3 << std::endl;
	return 0;
}
#include<iostream>

void SwapPointer(int &ptr1, int &ptr2) {
	int temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

int main() {
	int num1 = 5;
	int* ptr1 = &num1;
	int num2 = 10;
	int* ptr2 = &num2;

	std::cout << "-----바꾸기전-----" << std::endl;
	std::cout << "ptr1 : " << *ptr1 << std::endl;
	std::cout << "ptr2 : " << *ptr2 << std::endl; std::cout<<std::endl;

	SwapPointer(*ptr1,*ptr2);
	std::cout << "-----바꾸기후-----" << std::endl;
	std::cout << "ptr1 : " << *ptr1 << std::endl;
	std::cout << "ptr2 : " << *ptr2 << std::endl; std::cout << std::endl;
}
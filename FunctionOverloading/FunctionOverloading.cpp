#include<iostream>


void MyFunc(void) {
	std::cout << "MyFunc(void) Called" << std::endl;
}

void MyFunc(char c) {
	std::cout << "MyFunc(char c) Called" << std::endl;
}

void MyFunc(int a, int b) {
	std::cout << "MyFunc(int a, int b) Called" << std::endl;
}

int main(void) {
	MyFunc();
	MyFunc('A');
	MyFunc(12, 13);
	return 0;
}
#include<iostream>

int main(void) {
	int num = 10;
	int i = 0;

	std::cout << "true : " << true << std::endl;
	std::cout << "false : " << false << std::endl;

	while (true) {
		std::cout << i++ << ' ';
		if (i > num) {
			break;
		}
	}
	std::cout << std::endl;

	std::cout << "sizeof 1: " << sizeof(1) << std::endl;
	std::cout << "sizeof 0: " << sizeof(0) << std::endl;
	std::cout << "sizeof true: " << sizeof(true) << std::endl;
	std::cout << "sizeof false: " << sizeof(false) << std::endl;
	return 0;
}
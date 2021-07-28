#include<iostream>

int main(void) {
	int num = 0;
	int input;

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << "번째 정수 입력 : ";
		std::cin >> input;
		num += input;
	}

	std::cout << "합계 : " << num << std::endl;
	return 0;
}
#include<iostream>

int main(void) {
	int num = 0;
	int input;

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << "��° ���� �Է� : ";
		std::cin >> input;
		num += input;
	}

	std::cout << "�հ� : " << num << std::endl;
	return 0;
}
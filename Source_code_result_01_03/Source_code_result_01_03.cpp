#include<iostream>

int main(void) {
	int num;
	std::cout << "������ ���� �Է� :";
	std::cin >> num;

	for (int i = 1; i < num; i++) {
		std::cout << num << "x" << i << " = " << num * i << std::endl;
	}
	return 0;
}
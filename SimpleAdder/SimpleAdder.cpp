#include<iostream>

int main() {
	double val1;
	std::cout << "ù ��° ���� �Է� : ";
	std::cin >> val1;

	double val2;
	std::cout << "�� ��° ���� �Է� : ";
	std::cin >> val2;
	
	double result = val1 + val2;
	std::cout << "������� : " << result << std::endl;
	return 0;
}
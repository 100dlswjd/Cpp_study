// ����ڷκ��� �� 5���� ������ �Է� �޾Ƽ� �� ���� ����ϴ� ���α׷��� �ۼ��غ���
// �� ���α׷��� ������ ���������� �̷����� �Ѵ�.
#include<iostream>

int main(void) {
	int val1, val2, val3, val4, val5, result;
	std::cout << "1��° ���� �Է�: ";
	std::cin >> val1;

	std::cout << "2��° ���� �Է�: ";
	std::cin >> val2;

	std::cout << "3��° ���� �Է�: ";
	std::cin >> val3;

	std::cout << "4��° ���� �Է�: ";
	std::cin >> val4;

	std::cout << "5��° ���� �Է�: ";
	std::cin >> val5;

	result = val1 + val2 + val3 + val4 + val5;
	std::cout << "�հ� :" << result;
}
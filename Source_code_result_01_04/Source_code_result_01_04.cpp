#include<iostream>

int CalSalary(int sales) {
	return (int)(50 + sales * 0.12);
}

int main(void) {
	int sales;

	while (1) {
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է� (-1 to end) : ";
		std::cin >> sales;
		if (sales == -1) {
			break;
		}

		std::cout << "�̹� �� �޿� : ";
		std::cout << CalSalary(sales) << "����" << std::endl;
	}
	std::cout << "���α׷��� �����մϴ�." << std::endl;

	return 0;
}
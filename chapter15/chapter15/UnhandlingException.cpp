#include <iostream>

int main(void)
{
	int num1, num2;
	std::cout << "�ΰ��� ���� �Է� : ";
	std::cin >> num1 >> num2;
	if (num2 == 0)
	{
		std::cout << "������ 0�� �ɼ� �����ϴ�." << std::endl;
		std::cout << "���α׷��� �ٽ� ���� �ϼ���.," << std::endl;
	}
	else
	{
		std::cout << "������ �� : " << num1 / num2 << std::endl;
		std::cout << "�������� ������ : " << num1 % num2 << std::endl;
	}
	return 0;
}
#include <iostream>

void Divide(int num1, int num2)
{
	if (num2 == 0)
		throw num2;
	std::cout << " �������� �� : " << num1 / num2 << std::endl;
	std::cout << " �������� ������ : " << num1 % num2 << std::endl;
}

int main(void)
{
	int num1, num2;
	std::cout << " �� ���� ���� �Է� : ";
	std::cin >> num1 >> num2;

	try
	{
		Divide(num1, num2);
		std::cout << "�������� ���ƽ��ϴ�." << std::endl;
	}
	catch (int expn)
	{
		std::cout << "������ " << expn << "�� �ɼ� �����ϴ�." << std::endl;
		std::cout << "program re start plz ! " << std::endl;
	}
	return 0;
}
#include<iostream>


// ���ڷ� ���޵� int �� ������ ���� 1�� ������Ű�� �Լ�
void add_(int& ref) 
{
	ref = ref + 1; 
}

// ���ڷ� ���޵� int �� ������ ��ȣ�� �ٲٴ� �Լ�
void R_(int& ref)
{
	ref = ref * -1;
}

// �����Լ�
int main()
{
	int num1 = 10;
	int num2 = -20;

	add_(num1);
	R_(num2);
	std::cout << "add_(num1) : " << num1 << std::endl;
	std::cout << "R_(num2)   : " << num2 << std::endl;
}
// ���α׷� ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� ���·� �Է¹޾Ƽ�
// �Է¹��� �����͸� �״�� ����ϴ� ���α׷��� �ۼ��� ����.
#include<iostream>

int main(void) {
	char name[7];
	char phone[14];

	std::cout << "�̸��� �Է����ּ���(�ִ� 3����) : ";
	std::cin >> name;

	std::cout << "��ȭ��ȣ�� �Է����ּ���(010-1234-5678) : ";
	std::cin >> phone;

	std::cout << "�̸� : " << name << std::endl;
	std::cout << "��ȭ��ȣ : " << phone;
}
#include<iostream>

int main(void) {
	char name[100];
	char lang[200];

	std::cout << "�̸��� �����Դϱ� ? :";
	std::cin >> name;

	std::cout << "�����ϴ� ���α׷��� ���� �����Դϱ� ? :";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�." << std::endl;
	std::cout << "���� �����ϴ� ���α׷��� ���� " << lang << "�Դϴ�. " << std::endl;
	return 0;
}
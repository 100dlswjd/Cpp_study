#include <iostream>
#include <string>

int main(void)
{

	std::string str1 = "I like";
	std::string str2 = "string class";
	std::string str3 = str1 + str2;

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;

	str1 += str2;
	if (str1 == str3)
		std::cout << "���� ���ڿ� ! " << std::endl;
	else
		std::cout << "�������� ���� ���ڿ�" << std::endl;

	std::string str4;
	std::cout << "���ڿ� �Է� : ";
	std::cin >> str4;
	std::cout << "���� �Է��� ���ڿ� : " << str4 << std::endl;

	return 0;
}
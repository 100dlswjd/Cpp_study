#include<cstring>
#include<iostream>

int main(void) {
	char str1[25] = "test str1";
	char str2[25];
	std::cout << str1 << " : ";
	std::cout << strlen(str1) << "��" << std::endl; std::cout << std::endl;
	
	strcat_s(str1, " strpuls");

	std::cout << str1 << " : ";
	std::cout << strlen(str1) << std::endl; std::cout << std::endl;
	
	strcpy_s(str2, str1);
	
	strcat_s(str2, "aa");
	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;

	if (strcmp(str1, str2) == 0) {
		std::cout << "���������Դϴ�." << std::endl;
	}
	else {
		std::cout << "�ٸ������Դϴ�." << std::endl;
	}

}
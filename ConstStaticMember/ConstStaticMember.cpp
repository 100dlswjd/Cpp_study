#include<iostream>

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998467;
	const static int CHINA = 957290;
	const static int SQUTH_KOREA = 9922;
};

int main(void)
{
	std::cout << "���þ� ���� : " << CountryArea::RUSSIA << "km" << std::endl;
	std::cout << "ĳ���� ���� : " << CountryArea::CANADA << "km" << std::endl;
	std::cout << "�߱� ���� : " << CountryArea::CHINA << "km" << std::endl;
	std::cout << "�ѱ� ���� : " << CountryArea::SQUTH_KOREA << "km" << std::endl;
	return 0;
}
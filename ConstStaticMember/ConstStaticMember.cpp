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
	std::cout << "러시아 면적 : " << CountryArea::RUSSIA << "km" << std::endl;
	std::cout << "캐나다 면적 : " << CountryArea::CANADA << "km" << std::endl;
	std::cout << "중국 면적 : " << CountryArea::CHINA << "km" << std::endl;
	std::cout << "한국 면적 : " << CountryArea::SQUTH_KOREA << "km" << std::endl;
	return 0;
}
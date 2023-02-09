#include <iostream>

template <typename T>
void ShowStaticValue(void)
{
	static T num = 0;
	num += 1;
	std::cout << num << " ";
}

int main(void)
{
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	ShowStaticValue<int>();
	std::cout << std:: endl;
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	ShowStaticValue<long>();
	std::cout << std::endl;
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	ShowStaticValue<double>();
	std::cout << std::endl;
	return 0;
}
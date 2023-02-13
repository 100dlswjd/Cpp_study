#include <iostream>

void Divide(int num1, int num2)
{
	try
	{
		if (num2 == 0)
		{
			throw 0;
		}
		std::cout << "¸ò : " << num1 / num2 << std::endl;
		std::cout << "³ª¸ÓÁö : " << num1 % num2 << std::endl;
	}
	catch (int expn)
	{
		std::cout << "first catch" << std::endl;
		throw;
	}
}

int main(void)
{
	try
	{
		Divide(9, 2);
		Divide(9, 0);
	}
	catch (int expn)
	{
		std::cout << "second catch" << std::endl;
	}
	return 0;
}
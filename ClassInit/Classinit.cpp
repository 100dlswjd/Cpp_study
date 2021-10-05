#include<iostream>

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2)
	{
		// empty
	}
	SoSimple(SoSimple& copy)
		: num1(copy.num1), num2(copy.num2)
	{
		std::cout << "Called SoSimple(SoSimple &copy)" << std::endl;
	}
	void ShowSimpleData()
	{
		std::cout << num1 << std::endl;
		std::cout << num2 << std::endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 30);
	std::cout << "생성 및 초기화 직전" << std::endl;
	SoSimple sim2 = sim1; // SoSimple sim2(sim1);
	std::cout << "생성 및 초기화 직후" << std::endl;
	sim2.ShowSimpleData();
	return 0;
}
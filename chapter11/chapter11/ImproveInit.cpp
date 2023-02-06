/*
#include <iostream>

class AAA
{
private:
	int num;
public:
	AAA(int n = 0) : num(n)
	{ 
		std::cout << "AAA(int n = 0)" << std::endl;
	}
	AAA(const AAA& ref) : num(ref.num)
	{
		std::cout << "AAA(const AAA& ref)" << std::endl;
	}
	AAA& operator=(const AAA& ref)
	{
		num = ref.num;
		std::cout << "operator = (const AAA& ref)" << std::endl;
		return *this;
	}
};

class BBB
{
private:
	AAA mem;
public:
	BBB(const AAA& ref) : mem(ref) { }
};

class CCC
{
private:
	AAA mem;
public:
	CCC(const AAA& ref)
	{
		mem = ref;
	}
};

int main(void)
{
	AAA obj1(12);
	std::cout << "****************************" << std::endl;
	BBB obj2(obj1);
	std::cout << "****************************" << std::endl;
	CCC obj3(obj1);
	return 0;
}
*/
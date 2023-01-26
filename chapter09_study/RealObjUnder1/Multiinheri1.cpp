#include <iostream>

class BaseOne
{
public:
	void SimpleFuncOne() { std::cout << "BaseOne" << std::endl; }
};

class BaseTwo
{
public:
	void SimpleFuncTwo() { std::cout << "BaseTwo" << std::endl; }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
	void ComplexFunc()
	{
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};
/*
int main()
{
	MultiDerived mdr;
	mdr.ComplexFunc();

	return 0;
}*/
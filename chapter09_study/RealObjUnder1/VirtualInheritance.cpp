#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor" << std::endl; }
	void SimpleFunc() { std::cout << "BaseOne" << std::endl; }
};

class MiddleDerivedOne : virtual public Base
{
public:
	MiddleDerivedOne() : Base()
	{
		std::cout << "MiddleDerivedOne Constructor" << std::endl;
	}
	void MiddleFuncOne() 
	{
		SimpleFunc();
		std::cout << "MiddleDerivedOne" << std::endl;
	}
};

class MiddleDerivedTwo : virtual public Base
{
public:
	MiddleDerivedTwo() : Base()
	{
		std::cout << "MiddleDerivedTwo Constructor" << std::endl;
	}
	void MiddleFuncTwo()
	{
		SimpleFunc();
		std::cout << "MiddleDerivedTwo" << std::endl;
	}
};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
	LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
	{
		std::cout << "LastDerived Constructor" << std::endl;
	}
	void ComplexFunc()
	{
		MiddleFuncOne();
		MiddleFuncTwo();
		SimpleFunc();
	}
};

int main()
{
	std::cout << "按眉 积己傈 : " << std::endl;
	LastDerived ldr;
	std::cout << "按眉 积己饶 " << std::endl;
	ldr.ComplexFunc();
	return 0;
}
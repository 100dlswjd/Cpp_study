/*
#include <iostream>

class SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		std::cout << "SoSimple Base Class" << std::endl;
	}
};

class SoComplex : public SoSimple
{
public:
	virtual void ShowSimpleInfo()
	{
		std::cout << "SoComples Derived Class" << std::endl;
	}
};


int main(void)
{
	SoSimple* simPtr = new SoComplex;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	comPtr->ShowSimpleInfo();
	return 0;
}
*/
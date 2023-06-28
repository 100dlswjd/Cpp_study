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
	SoSimple* simPtr = new SoSimple;
	SoComplex* comPtr = dynamic_cast<SoComplex*>(simPtr);
	if (comPtr == NULL)
		std::cout << "형 변환 실패" << std::endl;
	else
		comPtr->ShowSimpleInfo();
	return 0;
}
*/
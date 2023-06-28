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
	void ShowSimpleInfo()
	{
		std::cout << "SoSimplex Derived Class" << std::endl;
	}
};

int main(void)
{
	SoSimple simObj;
	SoSimple& ref = simObj;

	try
	{
		SoComplex& comRef = dynamic_cast<SoSimple&>(ref);
		comRef.ShowSimpleInfo();
	}
	catch (std::bad_cast expt)
	{
		std::cout << expt.what() << std::endl;
	}
	return 0;
}
*/
#include<iostream>

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		std::cout << simObjCnt << "��° SoSimple ��ü" << std::endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		std::cout << cmxObjCnt << " ��° SoComplex ��ü" << std::endl;		
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		std::cout << cmxObjCnt << "��° SoComplex ��ü" << std::endl;
	}
};

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();
	return 0;
}
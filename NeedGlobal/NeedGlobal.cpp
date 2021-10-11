#include<iostream>

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
	SoSimple()
	{
		simObjCnt++;
		std::cout << simObjCnt << "¹øÂ° SoSimple °´Ã¼" << std::endl;
	}
};

class SoComplex
{
public:
	SoComplex()
	{
		cmxObjCnt++;
		std::cout << cmxObjCnt << " ¹øÂ° SoComplex °´Ã¼" << std::endl;		
	}
	SoComplex(SoComplex &copy)
	{
		cmxObjCnt++;
		std::cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << std::endl;
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
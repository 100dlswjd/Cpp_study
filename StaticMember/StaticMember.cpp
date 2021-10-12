#include<iostream>

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		std::cout << simObjCnt << "¹øÂ° SoSimple °´Ã¼" << std::endl;
	}
};

int SoSimple::simObjCnt = 0;

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex()
	{
		cmxObjCnt++;
		std::cout << cmxObjCnt << "¹øÂ°  SoComplex °´Ã¼ " << std::endl;
	}
	SoComplex(SoComplex& copy)
	{
		cmxObjCnt++;
		std::cout << cmxObjCnt << "¹øÂ° SoComplex °´Ã¼" << std::endl;
	}
};

int SoComplex::cmxObjCnt = 0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex cmx1;
	SoComplex cmx2=cmx1;
	SoComplex();
	return 0;
}
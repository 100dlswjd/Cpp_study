#include<iostream>

class SoSimple
{
public:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
	}
};

int SoSimple::simObjCnt = 0;

int main(void)
{
	std::cout << SoSimple::simObjCnt << "��° SoSimple ��ü" << std::endl;
	SoSimple sim1;
	SoSimple sim2;

	std::cout << SoSimple::simObjCnt << "��° SoSimple��ü" << std::endl;
	std::cout << sim1.simObjCnt << "��° SoSimple ��ü " << std::endl;
	std::cout << sim2.simObjCnt << "���� SoSimple ��ü " << std::endl;
	return 0;
}
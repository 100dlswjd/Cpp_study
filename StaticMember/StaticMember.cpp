#include<iostream>

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple()
	{
		simObjCnt++;
		std::cout << simObjCnt << "��° SoSimple ��ü" << std::endl;
	}
};

int SoSimple::sim
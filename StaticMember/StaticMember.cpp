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

int SoSimple::sim
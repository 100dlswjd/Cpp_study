#include<iostream>
#include<cstring>

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{
		std::cout << "num" << ", ";
		std::cout << "address=" << this << std::endl;
	}
	void ShowSimpleData()
	{
		std::cout << num << std::endl;
	}
	SoSimple* GetThisPointer()
	{
		return this;
	}
};

int main(void)
{
	SoSimple sim1(100);
	SoSimple* ptr1 = sim1.GetThisPointer();  //sim1 按眉狼 林家 蔼 历厘
	std::cout << ptr1 << ",";
	ptr1->ShowSimpleData();

	SoSimple sim2(200);
	SoSimple* ptr2 = sim2.GetThisPointer(); // sim2 按眉狼 林家 蔼 历厘
	std::cout << ptr2 << ", ";
	ptr2->ShowSimpleData();
	return 0;
}
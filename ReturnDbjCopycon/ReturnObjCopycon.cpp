#include<iostream>

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{	}
	SoSimple(const SoSimple& copy) :num(copy.num)
	{
		std::cout << "Called SoSimple(const SoSimple & copy)" << std::endl;
	}
	SoSimple& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData()
	{
		std::cout << "num : " << num << std::endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	std::cout << "return ÀÌÀü " << std::endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();
	return 0;
}
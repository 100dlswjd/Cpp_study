#include<iostream>

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) : num(n)
	{
		std::cout << "°´Ã¼»ý¼º" << std::endl;
	}
	SelfRef& Adder(int n)
	{
		std::cout << num << std::endl;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		std::cout << num << std::endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);
	SelfRef& ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(1).ShowTwoNumber();
	return 0;
}
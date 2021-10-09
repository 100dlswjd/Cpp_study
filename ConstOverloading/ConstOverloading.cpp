#include<iostream>

class SoSimple
{
private:
	int num;
public:
	SoSimple(int n) : num(n)
	{ }
	SoSimple& Addnum(int n)
	{
		num += n;
		return *this;
	}
	void SimpleFunc()
	{
		std::cout << "SimpleFunc : " << num << std::endl;
	}
	void SimpleFunc() const
	{
		std::cout << "const SimpleFunc :" << num << std::endl;
	}
};

void YourFunc(const SoSimple& obj)
{
	obj.SimpleFunc();
}

int main(void)
{
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);
	return 0;
}
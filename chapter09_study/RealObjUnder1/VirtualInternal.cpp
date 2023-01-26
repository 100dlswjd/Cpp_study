#include <iostream>

class AAA
{
private:
	int num1 = 0;
public:
	virtual void Func1() { std::cout << "Func1" << std::endl; }
	virtual void Func2() { std::cout << "Func2" << std::endl; }
};

class BBB : public AAA
{
private:
	int num2 = 0;
public:
	virtual void Func1() { std::cout << "BBB::Func1" << std::endl; }
	void Func3() { std::cout << "Func3" << std::endl; }
};
/*
int main()
{
	AAA* aptr = new AAA();
	aptr->Func1();

	BBB* bptr = new BBB();
	bptr->Func1();
	return 0;
}
*/
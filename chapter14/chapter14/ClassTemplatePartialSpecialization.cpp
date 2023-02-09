#include <iostream>

template <typename T1, typename T2>
class MySimple
{
public:
	void WhoAreYou()
	{
		std::cout << "size of T1 : " << sizeof(T1) << std::endl;
		std::cout << "size of T2 : " << sizeof(T2) << std::endl;
		std::cout << "<typename T1, typename T2>" << std::endl;
	}
};

template <>
class MySimple<int, double>
{
public:
	void WhoAreYou()
	{
		std::cout << "size of int : " << sizeof(int) << std::endl;
		std::cout << "size of double : " << sizeof(double) << std::endl;
		std::cout << "<int, double>" << std::endl;
	}
};
template <typename T1>
class MySimple<T1, double>
{
public:
	void WhoAreYou()
	{
		std::cout << "size of T1 : " << sizeof(T1) << std::endl;
		std::cout << "size of double : " << sizeof(double) << std::endl;
		std::cout << "<T1, double>" << std::endl;
	}
};

int main(void)
{
	MySimple<char, double> obj1;
	MySimple<int, long> obj2;
	MySimple<int, double> obj3;
	obj1.WhoAreYou();
	obj2.WhoAreYou();
	obj3.WhoAreYou();
	return 0;
}
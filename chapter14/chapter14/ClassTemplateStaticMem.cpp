#include <iostream>

template <typename T>
class SimpleSaticMem
{
private:
	static T mem;
public:
	void AddMem(T num) { mem += num; }
	void ShowMem() { std::cout << mem << std::endl; }
};

template <typename T>
T SimpleSaticMem<T>::mem = 0; 

int main(void)
{
	SimpleSaticMem<int> obj1;
	SimpleSaticMem<int> obj2;
	obj1.AddMem(2);
	obj2.AddMem(3);
	obj1.ShowMem();
	SimpleSaticMem<long> obj3;
	SimpleSaticMem<long> obj4;
	obj3.AddMem(100);
	obj4.ShowMem();
	return 0;
}
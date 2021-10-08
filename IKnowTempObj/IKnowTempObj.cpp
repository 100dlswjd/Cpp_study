#include<iostream>

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		std::cout << "create obj : " << num << std::endl;
	}
	~Temporary()
	{
		std::cout << "destroy obj : " << num << std::endl;
	}
	void ShowTempInfo()
	{
		std::cout << "My num is " << num << std::endl;
	}
};

int main(void)
{
	Temporary(100);
	std::cout << "********** after make!" << std::endl << std::endl;

	Temporary(200).ShowTempInfo();
	std::cout << "*********** after make!" << std::endl << std::endl;

	const Temporary& ref = Temporary(300);
	std::cout << "************* end of main!" << std::endl << std::endl;
	return 0;
}
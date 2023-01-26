#include<iostream>

class Data
{
private:
	int data;
public:
	Data(int num): data(num)
	{ }
	void ShowData() { std::cout << "data : " << this->data << std::endl; }
	void Add(int num) { this->data += num; }
};
/*
int main(void)
{
	Data obj(15);
	obj.Add(17);
	obj.ShowData();
	return 0;
}*/
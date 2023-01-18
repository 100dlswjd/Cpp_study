#include<iostream>

// ���簢��
class Rectangle
{
private:
	int area;
public:
	Rectangle(int n1, int n2)
	{
		area = n1 * n2;
	}
	void ShowAreaInfo()
	{
		std::cout << "���� : " << area << std::endl;
	}
};

// ���簢��
class Square : public Rectangle
{
private:
public:
	Square(int n)
		: Rectangle(n , n)
	{

	}

};

int main()
{
	Rectangle a(10,10);
	Square b(15);
	a.ShowAreaInfo();
	b.ShowAreaInfo();
	return 0;
}
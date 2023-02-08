/*
#include <iostream>

template <typename T>

void SwapData(T &num1, T &num2)
{
	T temp = num1;
	num1 = num2;
	num2 = temp;
}

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) : 
		xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}

	void Swap()
	{
		SwapData(xpos, ypos);
	}
};

int main(void)
{
	Point A(10, 20);
	Point B(20, 30);
	A.ShowPosition();
	B.ShowPosition();

	SwapData(A, B);
	A.ShowPosition();
	B.ShowPosition();

	return 0;
}
*/
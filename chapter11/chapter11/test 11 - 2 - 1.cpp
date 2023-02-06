/*
#include <iostream>
#include <cstdlib>


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	friend std::ostream& operator<<(std::ostream& os, const Point& pos);
	friend std::ostream& operator<<(std::ostream& os, const Point* pos);
};

std::ostream& operator<<(std::ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}
std::ostream& operator<<(std::ostream& os, const Point* pos)
{
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << std::endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray
{
private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray & arr){}
	BoundCheckPointPtrArray&operator=(const BoundCheckPointPtrArray & arr) { }

public:
	BoundCheckPointPtrArray(int len) : arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	POINT_PTR& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR& operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			std::cout << "Array index out of bound exception" << std::endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() { return arrlen; }
	~BoundCheckPointPtrArray() { delete[]arr; }
};

int main(void)
{
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);


	for (int i = 0; i < arr.GetArrLen(); i++)
		std::cout << arr[i];

	for (int i = 0; i < arr.GetArrLen(); i++)
		delete arr[i];
	return 0;
}
*/
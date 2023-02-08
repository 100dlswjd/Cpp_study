#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{ }
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
};

template <typename T>
class SmartPtr
{
private:
	T* posptr;
public:
	SmartPtr(T* ptr) : posptr(ptr) { }
	T& operator*() const { return *posptr; }
	T* operator->() const { return posptr; }
	~SmartPtr() { delete posptr; }
};

int main(void)
{
	SmartPtr<Point>sptr1(new Point(1, 2));
	SmartPtr<Point>sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	return 0;
}
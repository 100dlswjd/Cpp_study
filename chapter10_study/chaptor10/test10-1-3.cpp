#include <iostream>

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << "," << ypos << ']' << std::endl;
	}
	Point operator+=(const Point& pos)
	{
		xpos += pos.xpos;
		ypos += pos.ypos;
		return *this;
	}
	Point operator-=(const Point& pos)
	{
		xpos -= pos.xpos;
		ypos -= pos.ypos;
		return *this;
	}
	friend bool operator==(const Point& pos1, const Point& pos2);
	friend bool operator!=(const Point& pos1, const Point& pos2);
};
bool operator==(const Point&pos1, const Point &pos2)
{
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos)
		return true;
	return false;
}
bool operator!=(const Point& pos1, const Point& pos2)
{
	return !(pos1 == pos2);
}
/*
int main()
{
	Point pos1(10, 10);
	Point pos2(10, 10);
	pos1 -= pos2;
	pos1.ShowPosition();

	if (pos1 != pos2)
		std::cout << "True" << std::endl;
	else
		std::cout << "False" << std::endl;

	return 0;
}
*/
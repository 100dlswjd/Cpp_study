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

};

/*
int main()
{
	Point pos1(10, 10);
	Point pos2(7, 3);

	
	(pos1 += pos2).ShowPosition();

	return 0;
}
*/
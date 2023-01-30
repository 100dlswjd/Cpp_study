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
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}
	Point operator*(int times)
	{
		Point pos(xpos * times, ypos * times);
		return pos;
	}
};
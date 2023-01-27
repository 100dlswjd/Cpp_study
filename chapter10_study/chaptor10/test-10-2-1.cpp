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

	Point operator-()
	{
		Point pos(-xpos, -ypos);
		return pos;
	}

};
/*
int main()
{
	Point pos1(10, 20);
	Point pos2 = -pos1;

	pos1.ShowPosition();

	pos2.ShowPosition();

	return 0;
}*/
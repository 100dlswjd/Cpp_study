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
	friend Point operator-(Point & pos1, Point & pos2);
	
};

Point operator-(Point & pos1, Point & pos2)
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}
/*
int main()
{
	Point pos1(10, 10);
	Point pos2(7, 3);
	Point pos3 = pos1 - pos2;

	pos3.ShowPosition();
	return 0;
}*/
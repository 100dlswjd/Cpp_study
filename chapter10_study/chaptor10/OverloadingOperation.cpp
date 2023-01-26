#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator+(const Point &ref)
	{
		Point pos(xpos+ref.xpos, ypos+ref.ypos);
		return pos;
	}
};
/*
int main()
{
	Point pos1(3, 4);
	Point pos2(30, 40);
	Point pos3 = pos1+pos2;

	pos3.ShowPosition();
}*/
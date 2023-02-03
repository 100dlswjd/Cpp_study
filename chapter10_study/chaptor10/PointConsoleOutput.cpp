#include <iostream>
using namespace std;
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition()
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	ostream& operator<<(ostream& os, const Point&)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}

};

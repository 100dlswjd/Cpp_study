#include <iostream>

class Point
{
private:
	int posx, posy;
public:
	Point(int x, int y) : posx(x), posy(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << posx << ", " << posy << ']' << std::endl;
	}

	Point operator~()
	{
		Point pos(~posy, ~posx);
		return pos;
	};
};
/*
int main()
{
	Point pos(1, 0);

	pos.ShowPosition();

	Point pos2 = ~pos;

	pos2.ShowPosition();
	return 0;
}
*/
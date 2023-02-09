/*

#include <iostream>

template <typename T>

class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
	}

	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend std::ostream& operator<<(std::ostream& os, const Point<int>& pos);
};

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
{
	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

std::ostream& operator<<(std::ostream& os, const Point<int>& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
	return os;
}

int main(void)
{
	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3 = pos1 + pos2;
	std::cout << pos1 << pos2 << pos3;
	return 0;
}

*/
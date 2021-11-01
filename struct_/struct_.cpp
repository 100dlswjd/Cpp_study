#include<iostream>

struct Point
{
	int x;
	int y;
};

void ShowPosition(const Point &Point)
{
	std::cout << "[ " << Point.x << ", " << Point.y << " ]" << std::endl;
}

void MovePos(int x,int y)
{

}
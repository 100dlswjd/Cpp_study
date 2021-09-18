#include<iostream>

class Point {
	int x;
	int y;
};

class Rectangle {
public:
	Point upLeft;
	Point lowRight;

public:
	void ShowRecInfo() {
		std::cout << "좌상단 :" << '[' << upLeft.x << ",";
		std::cout << upLeft.y << ']' << std::endl;
		std::cout << "우하단" << lowRight.x << ",";
		std::cout << lowRight.y << ']' << std::endl << std::endl;
	}	
};

int main() {
	Point pos1 = { -2, 4 };
	Point pos2 = { 5, 9 };
	Rectangle rec = { pos2,pos1 };
	rec.ShowRecInfo();
	return 0;
}
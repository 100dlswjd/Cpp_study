// 구조체 내에 함수 정의하기
#include<iostream>

struct Point {
	int xpos;
	int ypos;
	
	void MovePos(int x, int y);       //
	void AddPoint(const Point& pos);  // 점의 좌표증가
	void ShowPosition();
};
void Point::MovePos(int x, int y) {
	xpos += x;
	ypos += y;
	if (xpos <= 0)
		xpos = 0;
	if (ypos <= 0)
		ypos = 0;
}

void Point::AddPoint(const Point&pos) {
	xpos += pos.xpos;
	ypos += pos.ypos;
}

void Point::ShowPosition() {
	std::cout << "[" << xpos << "," << ypos << "]" << std::endl << std::endl;
}

int main(void) {
	Point pos1 = { 12,4 };
	Point pos2 = { 20,30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();

	pos1.AddPoint(pos2);
	pos1.ShowPosition();

	return 0;
}
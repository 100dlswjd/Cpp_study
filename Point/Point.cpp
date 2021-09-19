#include<iostream>
#include"Point.h"

bool Point::InitMembers(int xpos, int ypos) {
	if (xpos < 0 || ypos < 0) {
		std::cout << "��� ������ �� ����" << std::endl;
		return false;
	}

	x = xpos;
	y = ypos;
	return true;
}

int Point::GetX() const {
	return x;
}

int Point::GetY() const {
	return y;
}

bool Point::SetX(int xpos) {
	if (x > xpos || xpos > 100) {
		std::cout << "��� ������ �� ����" << std::endl;
		return false;
	}
	x = xpos;
	return true;
}
bool Point::SetY(int ypos) {
	if (0 > ypos || ypos > 100) {
		std::cout << "��� ������ �� ����" << std::endl;
		return false;
	}
	y = ypos;
	return true;
}
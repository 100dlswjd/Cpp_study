#include<iostream>

namespace BestComImp1 {
	void SimpleFunc(void) {
		std::cout << "BestCom �� ������ �Լ�" << std::endl;
	}
}

namespace ProgComImp1 {
	void SimpleFunc(void) {
		std::cout << "ProgCom �� ������ �Լ�" << std::endl;
	}
}

int main() {
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();
}
#include<iostream>

namespace BestComImp1 {
	void SimpleFunc(void);
}

namespace BestComImp1 {
	void PrettyFunc(void);
}

namespace ProgComImp1 {
	void SimpleFunc(void);
}

int main() {
	BestComImp1::SimpleFunc();
}

void BestComImp1::SimpleFunc(void) {
	std::cout << "BestCom이 정의한 함수" << std::endl;
	PrettyFunc();
	ProgComImp1::SimpleFunc();
}

void BestComImp1::PrettyFunc(void) {
	std::cout << "So Pretty!!" << std::endl;
}

void ProgComImp1::SimpleFunc(void) {
	std::cout << "ProgCom이 정의한 함수" << std::endl;
}
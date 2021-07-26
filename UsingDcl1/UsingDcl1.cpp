#include<iostream>

namespace Hybrid {
	void HyFunc(void) {
		std::cout << "So simple function!" << std::endl;
		std::cout << "In namespace Hybrid!" << std::endl;
	}
}

int main() {
	using Hybrid::HyFunc;
	HyFunc();
	return 0;
}
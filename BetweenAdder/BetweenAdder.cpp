#include<iostream>

int main(void) {
	int val1, val2;
	int result = 0;
	std::cout << "두개의 숫자 입력 : ";
	std::cin >> val1 >> val2;

	if (val1 < val2) {
		for (int i = val1+1; i < val2; i++) {
			result += i;
		}
	}
	else {
		for (int i = val2+1; i < val1; i++) {
			result += i;
		}
	}
	std::cout <<"두사이 정수의 합 : " << result << std::endl;
	return 0;
}
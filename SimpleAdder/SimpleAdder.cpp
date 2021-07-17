#include<iostream>

int main() {
	double val1;
	std::cout << "첫 번째 숫자 입력 : ";
	std::cin >> val1;

	double val2;
	std::cout << "두 번째 숫자 입력 : ";
	std::cin >> val2;
	
	double result = val1 + val2;
	std::cout << "덧셈결과 : " << result << std::endl;
	return 0;
}
// 사용자로부터 총 5개의 정수를 입력 받아서 그 합을 출력하는 프로그램을 작성해보자
// 단 프로그램의 실행은 다음과같이 이뤄져야 한다.
#include<iostream>

int main(void) {
	int val1, val2, val3, val4, val5, result;
	std::cout << "1번째 정수 입력: ";
	std::cin >> val1;

	std::cout << "2번째 정수 입력: ";
	std::cin >> val2;

	std::cout << "3번째 정수 입력: ";
	std::cin >> val3;

	std::cout << "4번째 정수 입력: ";
	std::cin >> val4;

	std::cout << "5번째 정수 입력: ";
	std::cin >> val5;

	result = val1 + val2 + val3 + val4 + val5;
	std::cout << "합계 :" << result;
}
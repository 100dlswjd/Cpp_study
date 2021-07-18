// 숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해보자
// 예를 들어서 사용자가 5를 입력한다면 구구단에서 5단을 출력 해야 한다.
#include<iostream>

int main(void) {
	int num;

	std::cout << "몇단을 출력할까요? : ";
	std::cin >> num;

	for (int i = 1; i < 10; i++) {
		std::cout << num << "*" << i << "=" << num * i << std::endl;
	}
}
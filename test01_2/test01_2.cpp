// 프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력받아서
// 입력받은 데이터를 그대로 출력하는 프로그램을 작성해 보자.
#include<iostream>

int main(void) {
	char name[7];
	char phone[14];

	std::cout << "이름을 입력해주세요(최대 3글자) : ";
	std::cin >> name;

	std::cout << "전화번호를 입력해주세요(010-1234-5678) : ";
	std::cin >> phone;

	std::cout << "이름 : " << name << std::endl;
	std::cout << "전화번호 : " << phone;
}
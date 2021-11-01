#include<iostream>


// 인자로 전달된 int 형 변수의 값을 1씩 증가시키는 함수
void add_(int& ref) 
{
	ref = ref + 1; 
}

// 인자로 전달된 int 형 변수의 부호를 바꾸는 함수
void R_(int& ref)
{
	ref = ref * -1;
}

// 메인함수
int main()
{
	int num1 = 10;
	int num2 = -20;

	add_(num1);
	R_(num2);
	std::cout << "add_(num1) : " << num1 << std::endl;
	std::cout << "R_(num2)   : " << num2 << std::endl;
}
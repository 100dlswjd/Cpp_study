// 판매원들의 급여 계산 프로그램을 작성해 보자. 이회사는 모든 판매원에게 매달 50만원의 기본급여와
// 물품 판매 가격의 ㅣ12%에 해당하는 돈을 지급한다. 예를 들어서 민수라는 친구의 이번달 물품 판매 
// 금액이 100만원 이라면 50+100*0.12 = 62, 따라서 62만원을 급여로 지급 받는다. 단. 아래의 실행의
//  예에서 보듯이 이러한 급여 계산은 -1 이 입력ㄷ괼 때까지 계속 되어야 한다. 

#include<iostream>

int main(void) {
	int sell=0;
	int money;
	while (true) {
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		if (sell == -1) {
			std::cout << "프로그램을 종료합니다.";
			break;
		}
		else {
			std::cin >> sell;
			money = 50 + sell * 0.12;
			std::cout << "이번달 급여 : " << money << std::endl;
		}
	}
}
#include<iostream>

class FruitSeller {
private:
	int APPLE_PRICE;
	int num0fApples;
	int myMoney;

public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		num0fApples = num;
		myMoney = money;
	}
	int SaleApples(int money) {
		int num = money / APPLE_PRICE;
		num0fApples = num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() {
		std::cout << "남은 사과 :" << num0fApples << std::endl;
		std::cout << "판매 수익 :" << num0fApples << std::endl;
	}
};

class FruitBuyer {
	int myMoney;       // pribate
	int num0fApples;    // pribate

public:
	void InitMembers(int money) {
		myMoney = money;
		num0fApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money) {
		num0fApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() {
		std::cout << "현재 잔액 : " << myMoney << std::endl;
		std::cout << "사과 개수 : " << num0fApples << std::endl << std::endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); // 과일의 구매!

	std::cout << "과일 판매자의 현황" << std::endl;
	seller.ShowSalesResult();
	std::cout << "과일 구매자의 현황" << std::endl;
	buyer.ShowBuyResult();
	return 0;
}
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
		std::cout << "���� ��� :" << num0fApples << std::endl;
		std::cout << "�Ǹ� ���� :" << num0fApples << std::endl;
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
		std::cout << "���� �ܾ� : " << myMoney << std::endl;
		std::cout << "��� ���� : " << num0fApples << std::endl << std::endl;
	}
};

int main(void) {
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000); // ������ ����!

	std::cout << "���� �Ǹ����� ��Ȳ" << std::endl;
	seller.ShowSalesResult();
	std::cout << "���� �������� ��Ȳ" << std::endl;
	buyer.ShowBuyResult();
	return 0;
}
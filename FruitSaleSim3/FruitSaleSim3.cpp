#include<iostream>

class FruitSeller
{
private:
	const int APPLE_PRICE;
	int numOfApples;
	int myMoney;
public:
	FruitSeller(int price, int num, int money)
		: APPLE_PRICE(price), numOfApples(num), myMoney(money)
	{
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		std::cout << "남은 사과 : " << numOfApples << std::endl;
		std::cout << "판매 수익 : " << myMoney << std::endl << std::endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	FruitBuyer(int money)
		: myMoney(money), numOfApples(0)
	{
	}
	void BuyApples(FruitSeller& Seller, int money)
	{
		numOfApples += Seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult() const
	{
		std::cout << "현재 잔액 : " << myMoney << std::endl;
		std::cout << "사과 개수 : " << numOfApples << std::endl << std::endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	std::cout << "과일 판매자의 현황" << std::endl;
	seller.ShowSalesResult();
	std::cout << "과일 구매자의 현황" << std::endl;
	buyer.ShowBuyResult();
	return	0;
}
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
		std::cout << "���� ��� : " << numOfApples << std::endl;
		std::cout << "�Ǹ� ���� : " << myMoney << std::endl << std::endl;
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
		std::cout << "���� �ܾ� : " << myMoney << std::endl;
		std::cout << "��� ���� : " << numOfApples << std::endl << std::endl;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);

	std::cout << "���� �Ǹ����� ��Ȳ" << std::endl;
	seller.ShowSalesResult();
	std::cout << "���� �������� ��Ȳ" << std::endl;
	buyer.ShowBuyResult();
	return	0;
}
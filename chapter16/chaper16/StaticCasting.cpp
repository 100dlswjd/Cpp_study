#include <iostream>

class Car
{
private:
	int fuelGauge;
public:
	Car(int fuel) : fuelGauge(fuel)
	{  }
	void ShowCarState() { std::cout << "잔여 연료량 : " << fuelGauge << std::endl; }
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck(int fuel, int weight) : Car(fuel), freightWeight(weight)
	{ }
	void ShowTruckState()
	{
		ShowCarState();
		std::cout << "화물의 무게 : " << freightWeight << std::endl;
	}
};

int main(void)
{
	Car* pcar1 = new Truck(80, 120);
	Truck* ptruck1 = static_cast<Truck*>(pcar1);
	ptruck1->ShowTruckState();
	std::cout << std::endl;

	Car* pcar2 = new Car(120);
	Truck* ptruck2 = static_cast<Truck*>(pcar2);
	ptruck2->ShowTruckState();
	return 0;
}
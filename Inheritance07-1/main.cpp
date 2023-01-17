#include<iostream>

class Car
{
private:
	int gasolineGauge;
public:
	Car() : gasolineGauge(50)
	{

	}
	Car(int n) : gasolineGauge(n)
	{

	}

	int GetGasGauige()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar() : electricGauge(50)
	{

	}
	HybridCar(int n) : electricGauge(n)
	{

	}
	HybridCar(int n1, int n2) : Car(n1), electricGauge(n2)
	{

	}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar() : waterGauge(50)
	{

	}
	HybridWaterCar(int n1) : waterGauge(n1)
	{

	}
	HybridWaterCar(int n1, int n2) : HybridCar(n1), waterGauge(n2)
	{

	}

	HybridWaterCar(int n1, int n2, int n3) : HybridCar(n1, n2), waterGauge(n3)
	{

	}

	void showCurrentGauge()
	{
		std::cout << "ÀÜ¿© °¡¼Ö¸° : " << GetGasGauige() << std::endl;
		std::cout << "ÀÜ¿© Àü±â·® : " << GetElecGauge() << std::endl;
		std::cout << "ÀÜ¿© ¿öÅÍ·® : " << waterGauge << std::endl;
	}
};


int main()
{
	HybridWaterCar HWC(100,75,50);
	HWC.showCurrentGauge();
	return 0;
}
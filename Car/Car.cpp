#include<iostream>
#include<cstring>
#include "Car.h"

void Car::InitMembers(const char* ID, int fuel) {
	strcpy_s(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::Accel() {
	if (fuelGauge <= 0)
		return;
	if (curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
		curSpeed = CAR_CONST::MAX_SPD;

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::ShowCarState() {
	std::cout << "사용자 ID : " << gamerID << std::endl;
	std::cout << "연료량 : " << fuelGauge << " %" << std::endl;
	std::cout << "현재속도 : " << curSpeed << " km/h" << std::endl << std::endl;
}

void Car::Break() {
	if (curSpeed <= 0) {
		curSpeed = 0;
		return;
	}
	curSpeed -= CAR_CONST::BRK_STEP;
}
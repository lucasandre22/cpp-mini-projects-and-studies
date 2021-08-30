#include "Builder.h"
#pragma once
class Director
{
private:
	//Builder* builder;
public:
	void buildSportCar(Builder* b) {
		b->reset();
		b->setAirConditioner(true);
		b->setCarType("Sports Car");
		b->setDoors(3);
		b->setHorsePower(300);
		b->setSpoiler(true);
		b->setTurbo(true);
		b->setWheels(4);
	}

	void buildCommonCar(Builder* b) {
		b->reset();
		b->setAirConditioner(true);
		b->setCarType("Commom car");
		b->setDoors(5);
		b->setHorsePower(110);
		b->setSpoiler(false);
		b->setTurbo(false);
		b->setWheels(4);
	}
};


#include "Builder.h"
#include "Car.h"
#pragma once
class CarBuilder : 
	public Builder
{
private:
	Car* car;
public:
	CarBuilder() { car = nullptr; }
	~CarBuilder() { car = nullptr; }
	void setDoors(unsigned int d) { car->setDoors(d); }
	void setWheels(unsigned int w) { car->setWheels(w); }
	void setHorsePower(unsigned int p) { car->setHorsePower(p); }
	void setCarType(std::string s) { car->setCarType(s); }
	void setSpoiler(const bool s) { car->setSpoiler(s); }
	void setTurbo(const bool s) { car->setTurbo(s); }
	void setAirConditioner(const bool s) { car->setAirConditioner(s); }
	void reset() { this->car = new Car(); }
	Car* getProduct() { Car* product = car; car = nullptr; return product; }
};


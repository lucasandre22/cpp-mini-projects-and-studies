#include <string>
#pragma once
class Car //usually this class has a lot of other class, so it became easier to build without a lot of different constructors
{
private:
	unsigned int doors;
	unsigned int wheels;
	unsigned int horsePower;
	std::string carType;
	bool spoiler;
	bool turbo;
	bool airConditioner;
public:
	Car(unsigned int doors = 0, unsigned int wheels = 0, unsigned int horsePower = 0) {
		this->doors = doors;
		this->wheels = wheels;
		this->horsePower = horsePower;
		carType = "";
		spoiler = false;
		turbo = false;
		airConditioner = false;
	}
	~Car() {}
	void setDoors(unsigned int d) { doors = d; }
	void setWheels(unsigned int w) { wheels = w; }
	void setHorsePower(unsigned int p) { horsePower = p; }
	void setCarType(std::string s) { carType = s; }
	void setSpoiler(const bool s) { spoiler = s; }
	void setTurbo(const bool s) { turbo = s; }
	void setAirConditioner(const bool s) { airConditioner = s; }
	bool hasSpoiler() const { return spoiler; }
	bool hasTurbo() const { return turbo; }
	bool hasAirConditioner() const { return airConditioner; }
	std::string getCarType() const { return carType; }
};


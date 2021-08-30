#include <string>
#pragma once
class Builder
{
public:
	virtual void setDoors(unsigned int d) = 0;
	virtual void setWheels(unsigned int w) = 0;
	virtual void setHorsePower(unsigned int p) = 0;
	virtual void setCarType(std::string s) = 0;
	virtual void setSpoiler(const bool s) = 0;
	virtual void setTurbo(const bool s) = 0;
	virtual void setAirConditioner(const bool s) = 0;
	virtual void reset() = 0;
};


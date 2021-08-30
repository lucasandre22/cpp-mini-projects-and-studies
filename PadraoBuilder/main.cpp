#include <iostream>
#include "Director.h"
#include "CarBuilder.h"



int main() {
	Director d;
	CarBuilder builder;
	d.buildSportCar(&builder);
	Car *car = builder.getProduct();
	std::cout << car->getCarType() << std::endl;
}
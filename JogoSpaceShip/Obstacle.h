#include "Entity.h"
#pragma once
class Obstacle : public Entity
{
public:
	Obstacle(int x, int y) : Entity(x,y) {}
	~Obstacle() {}
	void update() { this->y++; }
};


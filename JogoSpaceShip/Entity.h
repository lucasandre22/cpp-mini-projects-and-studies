#pragma once
class Entity
{
protected:
	int x;
	int y;
public:
	Entity(int x, int y) { this->x = x; this->y = 0; }
	virtual ~Entity() {}
	int getX() const { return this->x; }
	int getY() const { return this->y; }
};


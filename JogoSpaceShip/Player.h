#pragma once
class Player
{
private:
	int x;
	int y;
	bool alive;
public:
	Player() { this->y = 11; this->alive = true; this->x = 10; }
	~Player() {}
	int getX() { return this->x; }
	int getY() { return this->y; }
	void moverEsquerda() { this->x--; }
	void moverDireita() { this->x++; }
	bool getAlive() { return this->alive; }
	void setAlive(bool a) { this->alive = a; }
};


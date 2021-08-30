#pragma once
class Matriz
{
private:
	int sizeX;
	int sizeY;
	int** matriz;
public:
	Matriz(int x, int y) { this->sizeX = x; this->sizeY = y; matriz = new int* [sizeX]; for (int i = 0; i < sizeX; i++) matriz[i] = new int[y]; }
	~Matriz() { for (int i = 0; i < sizeX; i++) delete[]matriz[i]; }

};


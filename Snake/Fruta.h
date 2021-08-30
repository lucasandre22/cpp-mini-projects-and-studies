#pragma once

class Snake;

class Fruta
{
private:
	int posicaoX;
	int posicaoY;
	Snake* cobra;
public:
	Fruta(Snake* cobra) { this->cobra = cobra; GeraFruta(); }
	~Fruta() { }
	int GetX() { return this->posicaoX; }
	int GetY() { return this->posicaoY; }
	void GeraFruta();
	void VerificaFrutaComida();
	
};


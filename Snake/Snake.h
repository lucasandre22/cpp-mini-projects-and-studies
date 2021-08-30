#include "ListaTemplate.h"
#pragma once
class Snake
{
private:
	int posicaoX[375];
	int posicaoY[375];
	int velocidadeX;
	int velocidadeY;
	int tamanho;
	bool viva;
public:
	Snake() { this->posicaoX[0] = 2; this->posicaoY[0] = 2; this->posicaoX[1] = 1; this->posicaoY[1] = 2; this->viva = true;
				this->velocidadeX = 1; this->velocidadeY = 0; this->tamanho = 2; }
	~Snake() { }
	int GetX() { return this->posicaoX[0]; }
	int GetY() { return this->posicaoY[0]; }
	int GetVelocidadeX() { return this->velocidadeX; }
	int GetVelocidadeY() { return this->velocidadeY; }
	int GetTamanho() { return this->tamanho; }
	void SetVelocidade(int velocidadeX, int velocidadeY) { this->velocidadeX = velocidadeX; this->velocidadeY = velocidadeY; }
	bool Viva() { return this->viva; }
	void SetViva(bool viva) { this->viva = viva; }
	void SetX(int x) { this->posicaoX[0] = x; }
	void SetY(int y) { this->posicaoY[0] = y; }
	void AtualizaMovimento();
	void AumentaTamanho();
	bool VerificaDesenhaCorpo(int i, int j);
	bool VerificaColisaoCorpo(int i, int j);

};


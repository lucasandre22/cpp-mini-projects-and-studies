#include "Snake.h"
#include <windows.h>
void Snake::AtualizaMovimento()
{
	for (int i = tamanho; i > 0; i--)
	{
		posicaoX[i] = posicaoX[i - 1];
		posicaoY[i] = posicaoY[i - 1];
	}
	this->posicaoX[0] += this->velocidadeX;
	this->posicaoY[0] += this->velocidadeY;
}

void Snake::AumentaTamanho()
{
	this->tamanho++;
	if (tamanho == 375)
		this->viva = false;
	AtualizaMovimento();
}

bool Snake::VerificaDesenhaCorpo(int i, int j)
{
	for (int k = 0; k < tamanho; k++)
	{
		if (i == posicaoX[k] && j == posicaoY[k])
			return true;
	}
	return false;
}

bool Snake::VerificaColisaoCorpo(int i, int j)
{
	for (int k = 2; k <= tamanho; k++)
	{
		if (i == posicaoX[k] && j == posicaoY[k])
			return true;
	}
	return false;
}

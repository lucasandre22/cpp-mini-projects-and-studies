#include "Snake.h"
#include "Fruta.h"
#include "Input.h"
#pragma once
class Jogo
{
private:
	Snake cobra;
	Input input;
	Fruta fruta;
	int sizeX;
	int sizeY;
	int pontuacao;
public:
	Jogo(int x, int y) : cobra(), input(&cobra) , fruta(&cobra) { this->sizeX = x; this->sizeY = y; this->pontuacao = 0; }
	~Jogo() {}
	void MostraJogo();
	void Executar();
	void AtualizaMovimentoCobra();
	void VerificaCobraForaTabuleiro();
	void VerificaFrutaComida();
	void VerificaBateuCorpo();
	void MostraPontuacao();
	

};


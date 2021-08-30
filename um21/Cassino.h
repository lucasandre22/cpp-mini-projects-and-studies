#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include "Truco.h"
using namespace std;

#pragma once
class Cassino
{
private:
	unsigned int quantidadeJogadores;
	Jogador JogadorBot;
	
	Baralho baralho;
	ListaJogadores* listaJogadores;
	Truco truco;
public:
	Cassino();
	~Cassino();
	int menuCassino();
	void setQuantidadeJogadores(unsigned int quantidadeJogadores) { this->quantidadeJogadores = quantidadeJogadores; }
	void criaJogadoresBlackjack();
	void jogarBlackjack();
	void rodadaJogadoresJogaremBlackjack();
	void verificaGanhadoresEPerdedoresBlackjack();
	void jogarTruco();
	void criaJogadoresTruco();
};


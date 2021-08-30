#include "ListaJogadores.h"

#pragma once
class Truco
{
private:
	Baralho baralhoTruco;
	vector<Carta*> cartasNaMesa;
	ListaJogadores* listaJogadores;
	unsigned int pontosRodadaTime1;
	unsigned int pontosRodadaTime2;
	unsigned int pontosTotalTime1;
	unsigned int pontosTotalTime2;
public:
	Truco();
	~Truco();
	void iniciarTruco();
	void jogadoresRecebemCartasTruco();
	void jogadorBotJoga();
};


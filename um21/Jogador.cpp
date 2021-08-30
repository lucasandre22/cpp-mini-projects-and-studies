#include "Jogador.h"

Jogador::Jogador()
{
	this->quantidadeCartasJogador = 0;
	this->pontosAcumulados = 0;
	this->nome = ' ';
}

Jogador::~Jogador()
{
	cartasDoJogador.clear();
}

void Jogador::receberCartas(Baralho* b, int quantidade)
{
	for (int i = 0; i < quantidade; i++)
	{
		this->cartasDoJogador.push_back(b->getCartaBaralho());
		this->quantidadeCartasJogador++;
		incrementaPontosAcumulados(cartasDoJogador.back()->getPontosCarta());
	}
	
}

void Jogador::escreveCartasJogador()
{
	for (auto& elemento : cartasDoJogador)
		cout << elemento->getNomeCarta() << endl;
	cout << endl;
}

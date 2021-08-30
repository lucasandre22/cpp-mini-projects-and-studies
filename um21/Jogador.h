#include "Baralho.h"
#include <vector>
#include <iostream>
using namespace std;

#pragma once

class Jogador
{
protected:
	string nome;
	unsigned int quantidadeCartasJogador;
	unsigned int pontosAcumulados;
	vector<Carta*> cartasDoJogador;
	bool jogadorComecaRodada;
public:
	Jogador();
	~Jogador();
	void receberCartas(Baralho* b, int quantidade);
	void incrementaPontosAcumulados(unsigned int pontos) { this->pontosAcumulados += pontos; }
	unsigned int getPontosAcumulados() { return pontosAcumulados; }
	void escreveCartasJogador();
	void setNome() { cin >> this->nome; }
	string getNome() { return this->nome; }
	Carta* getPrimeiraCarta() { return cartasDoJogador.back(); }
	vector<Carta*> getCartasJogador() { return this->cartasDoJogador; }
	void devolveCartas() { cartasDoJogador.clear(); }
	bool jogadorTemCartas() { return cartasDoJogador.empty() ? true : false; }
	void setJogadorComecaRodada(bool comeca) { this->jogadorComecaRodada = comeca; }
	bool getJogadorComecaRodada() { return this->jogadorComecaRodada; }
};


#include "Jogador.h"
#pragma once
class ListaJogadores
{
private:
	vector<Jogador*> listaJogadores;
	static ListaJogadores* instance;
	ListaJogadores();
public:
	static ListaJogadores* getInstance();
	~ListaJogadores() { listaJogadores.clear(); }
	void criaJogadoresBlackjack(int quantidade);
	void criaJogadoresTruco();
	unsigned int getNumeroJogadores() { return listaJogadores.size(); }
	Jogador* at(int i) { return listaJogadores.at(i); }
	void limpaListaJogadores() { listaJogadores.clear(); }
};


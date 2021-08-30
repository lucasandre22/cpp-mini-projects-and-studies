#include "ListaJogadores.h"

ListaJogadores* ListaJogadores::instance = 0;
ListaJogadores::ListaJogadores()
{
}

ListaJogadores* ListaJogadores::getInstance()
{
	if (instance == 0) {
		instance = new ListaJogadores;
	}
	return instance;
}

void ListaJogadores::criaJogadoresBlackjack(int quantidade)
{
	for (int i = 0; i < quantidade; i++) //cria jogadores e atribui para cada, um índice.
	{
		listaJogadores.push_back(new Jogador());
		cout << "Jogador " << i + 1 << " por favor, digite seu nome:" << endl;
		listaJogadores.at(i)->setNome();
	}
}

void ListaJogadores::criaJogadoresTruco()
{
	listaJogadores.push_back(new Jogador());
	cout << "Por favor, digite seu nome" << endl;
	listaJogadores.at(0)->setNome();
	for (int i = 0; i < 3; i++) //cria jogadores e atribui para cada, um índice.
	{
		listaJogadores.push_back(new Jogador());
	}
}

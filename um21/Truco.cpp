#include "Truco.h"

Truco::Truco()
{
	this->listaJogadores = ListaJogadores::getInstance();
	baralhoTruco.iniciaNovoBaralho();
	baralhoTruco.adequaBaralhoTruco();
	this->pontosRodadaTime1 = 0;
	this->pontosRodadaTime2 = 0;
	this->pontosTotalTime1 = 0;
	this->pontosTotalTime2 = 0;
}

Truco::~Truco()
{
}

void Truco::jogadoresRecebemCartasTruco()
{
	for (int i = 0; i < listaJogadores->getNumeroJogadores(); i++)
	{
		if (listaJogadores->at(i)->jogadorTemCartas())
			listaJogadores->at(i)->devolveCartas();
		listaJogadores->at(i)->receberCartas(&baralhoTruco, 3);
	}
}

void Truco::jogadorBotJoga()
{
}

void Truco::iniciarTruco()
{
	jogadoresRecebemCartasTruco();
	//baralhoTruco.devolveCartas();
	for (int i = 0; i < 4; i++)
	{
		listaJogadores->at(i)->escreveCartasJogador();
		cout << "--------" << endl;
	}
}
#include "Baralho.h"
#include <string>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

Baralho::Baralho()
{
}

Baralho::~Baralho()
{
	cartas.insert(cartas.end(), cartasRetiradas.begin(), cartasRetiradas.end()); //coloca todas as cartas retiradas do baralho no baralho
	cartasRetiradas.clear();
	for (int i = 0; i < cartas.size(); i++)
		delete cartas.at(0);
	cartas.clear();
	//função erase nao deleta nada!!
	//nem a função clear, elas só tiram os elementos do vetor, porem se foram alocados dinamicamente, ele não deleta!
}

void Baralho::iniciaNovoBaralho()
{
	unsigned int pontos = 0;
	string naipe, nomeCarta;
	bool cartaNumerica = false;

	if (!cartas.empty())
	{
		cartas.clear();
		cartasRetiradas.clear();
	}

	for (int i = 0; i < 4; i++) // Cria baralho.
	{
		if (i == 0)
			naipe = "Ouros";
		else if (i == 1)
			naipe = "Copas";
		else if (i == 2)
			naipe = "Espadas";
		else
			naipe = "Paus";
		for (int j = 0; j < 13; j++)
		{
			cartaNumerica = false;
			if (j < 10)
				pontos = j + 1;
			else
				pontos = 10;
			if (j == 0)
				nomeCarta = "As";
			else if (j == 10)
				nomeCarta = "Valete";
			else if (j == 11)
				nomeCarta = "Dama";
			else if (j == 12)
				nomeCarta = "Rei";
			else
			{
				cartaNumerica = true;
				nomeCarta = to_string(j + 1); // Nome da carta recebe o numero correspondente a ela
			}
			nomeCarta += " de ";
			nomeCarta += naipe;
			cartas.push_back(new Carta(nomeCarta, pontos, naipe, cartaNumerica));
		}
	}
	misturaBaralho();
}

void Baralho::adequaBaralhoTruco()
{
	for (int i = 0; i < cartas.size(); i++)
	{
		if (cartas.at(i)->getPontosCarta() > 7 && cartas.at(i)->getCartaNumerica())
		{
			cartas.erase(cartas.begin() + i);
			i--;
		}
	}
}

Carta* Baralho::getCartaBaralho()
{
	Carta* aux;
	srand(time(NULL));
	int indiceCarta = ((rand() % cartas.size()));
	//cout << "size do baralho: " << cartas.size() << " indice carta sorteada: " << indiceCarta << endl;
	aux = cartas.at(indiceCarta);
	cartas.erase(cartas.begin()+indiceCarta);
	this->cartasRetiradas.push_back(aux);
	return aux;
}

void Baralho::printBaralho()
{
	for (auto& elemento : cartas)
		cout << elemento->getNomeCarta() << endl;
}

void Baralho::devolveCartas()
{
	cartas.insert(cartas.end(), cartasRetiradas.begin(), cartasRetiradas.end());
	cartasRetiradas.clear();
	misturaBaralho();
}


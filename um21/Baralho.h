#include "Carta.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

#pragma once

class Baralho
{
private:
	vector<Carta*> cartas;
	vector<Carta*> cartasRetiradas;
public:
	Baralho();
	~Baralho();
	void iniciaNovoBaralho();
	void adequaBaralhoTruco();
	void misturaBaralho() { srand(time(NULL)); random_shuffle(cartas.begin(), cartas.end()); }
	Carta* getCartaBaralho();
	int getSizeBaralho() { return cartas.size(); }
	void printBaralho();
	void devolveCartas();
	
};


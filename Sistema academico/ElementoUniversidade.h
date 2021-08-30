#include "Universidade.h"
#pragma once
class ElementoUniversidade
{
private:
	Universidade* universidade;
public:
	ElementoUniversidade(Universidade* univ = nullptr);
	~ElementoUniversidade();
	Universidade* getUniversidade() { return this->universidade; }
	ElementoUniversidade* proximo;
	ElementoUniversidade* anterior;
};


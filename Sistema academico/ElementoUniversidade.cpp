#include "ElementoUniversidade.h"

ElementoUniversidade::ElementoUniversidade(Universidade* univ)
{
	this->proximo = nullptr;
	this->anterior = nullptr;
	this->universidade = univ;
}

ElementoUniversidade::~ElementoUniversidade()
{
	this->proximo = nullptr;
	this->anterior = nullptr;
	this->universidade = nullptr;
}

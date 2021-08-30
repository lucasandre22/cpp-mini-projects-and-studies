#include "Universidade.h"

Universidade::Universidade(string nome) : lista_departamentos(this)
{
	this->nome = nome; 
	this->id = -1;
}

Universidade::~Universidade()
{
}

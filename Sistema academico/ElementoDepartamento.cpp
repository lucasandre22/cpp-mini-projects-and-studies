#include "ElementoDepartamento.h"

ElementoDepartamento::ElementoDepartamento(Departamento* dep)
{
	this->departamento = dep;
	this->proximo = nullptr;
	this->anterior = nullptr;
}

ElementoDepartamento::~ElementoDepartamento()
{
	this->departamento = nullptr;
	this->proximo = nullptr;
	this->anterior = nullptr;
}


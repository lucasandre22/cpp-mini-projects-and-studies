#include "ElementoDisciplina.h"

ElementoDisciplina::ElementoDisciplina(Disciplina* disciplina)
{
	this->disciplina = disciplina;
	this->anterior = nullptr;
	this->proximo = nullptr;
}

ElementoDisciplina::~ElementoDisciplina()
{
	this->disciplina = nullptr;
	this->anterior = nullptr;
	this->proximo = nullptr;
}


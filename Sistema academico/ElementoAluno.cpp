#include "ElementoAluno.h"

ElementoAluno::ElementoAluno(Aluno* alun)
{
	this->aluno = alun;
	this->proximo = nullptr;
	this->anterior = nullptr;
	this->notaPrimeiraParcial = 0;
	this->notaSegundaParcial = 0;
	this->faltas = 0;
}

ElementoAluno::~ElementoAluno()
{
	this->proximo = nullptr;
	this->anterior = nullptr;
	this->aluno = nullptr;
}




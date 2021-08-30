#include "Disciplina.h"
#include "ElementoAluno.h"
#pragma once
class ElementoDisciplina
{
private:
    Disciplina* disciplina;
public:
	ElementoDisciplina(Disciplina* disciplina = nullptr);
	~ElementoDisciplina();
    Disciplina* getDisciplina() { return this->disciplina; }
    ElementoDisciplina* proximo;
    ElementoDisciplina* anterior;
};


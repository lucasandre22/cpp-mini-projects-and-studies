#pragma once
#include "Departamento.h"
class ElementoDepartamento
{
private:
    Departamento* departamento;
public:
    ElementoDepartamento(Departamento* dep = nullptr);
    ~ElementoDepartamento();
    Departamento* getDepartamento() { return this->departamento; }

    ElementoDepartamento* proximo;
    ElementoDepartamento* anterior;
};


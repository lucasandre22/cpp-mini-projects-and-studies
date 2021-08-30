#include "Departamento.h"

Departamento::Departamento(Universidade* univ, string nome) : lista_disciplina(this)
{
	this->universidadeDepartamento = univ;
	this->nome = nome;
	this->id = -1;
}

Departamento::~Departamento()
{
	
}

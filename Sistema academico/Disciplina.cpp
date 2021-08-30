#include "Disciplina.h"
#include "Aluno.h"

Disciplina::Disciplina(Departamento* dep, string nome, int id) : lista_alunos(this,id)
{
	this->nome = nome;
	this->departamentoDisciplina = dep;
	this->id = id;
}

Disciplina::~Disciplina()
{
	this->departamentoDisciplina = nullptr;
}

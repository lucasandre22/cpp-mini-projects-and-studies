#include "ListaTemplate.h"
#include "stdafx.h"
#pragma once

class Disciplina;

class Departamento;

class ListaDisciplinas
{
private:
	Departamento* departamento_lista_disciplinas;
	List::List<Disciplina*> lista_departamentos;
	List::Iterator<Disciplina*> iterator;
public:
	ListaDisciplinas(Departamento* dep = nullptr);
	virtual ~ListaDisciplinas();

	int getTamanhoListaDisciplinas() { return this->lista_departamentos.GetSize(); }
	void incluirDisciplina(Disciplina* disc) { this->lista_departamentos.Include(disc); }
	void removerDisciplina(Disciplina* disc) { this->lista_departamentos.Remove(disc); }
	void mostraDisciplinas();
	Disciplina* localizaDisciplina(string nome);
	void gravaDisciplinas();
};


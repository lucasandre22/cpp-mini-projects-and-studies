#include "stdafx.h"
#include "ListaDisciplinas.h"
#pragma once

class Universidade;

class Departamento
{
private:
	string nome;
	Universidade* universidadeDepartamento;
	ListaDisciplinas lista_disciplina;
	int id;
public:
	Departamento(Universidade* univ = NULL, string nome = "");
	~Departamento();
	string getNomeDepartamento() { return this->nome; }
	void setNomeDepartamento(string nome) { this->nome = nome; }
	void setUniversidade(Universidade* univ) { this->universidadeDepartamento = univ; }

	//funcoes pertencentes a lista
	void incluirDisciplina(Disciplina* disc) { this->lista_disciplina.incluirDisciplina(disc); }
	void removerDisciplina(Disciplina* disc) { this->lista_disciplina.removerDisciplina(disc); }
	void mostraDisciplinas() { cout << "Departamento " << this->nome << " possui as Disciplinas : " << endl; this->lista_disciplina.mostraDisciplinas(); }
	Disciplina* localizaDisciplina(string nome) { lista_disciplina.localizaDisciplina(nome); }
	int getId() { return this->id; }
	void setId(int id) { this->id = id; }
};


#include "stdafx.h"
#include "ListaAlunos.h"
class Departamento;
#pragma once
class Disciplina
{
private:
	string nome;
	Departamento* departamentoDisciplina;
	ListaAlunos lista_alunos;
	int id;
public:
	Disciplina(Departamento* dep = nullptr, string nome = "", int id = 0);
	~Disciplina();
	string getNomeDisciplina() { return nome; }
	void setNomeDisciplina(string nome) { this->nome = nome; }
	void setDepartamentoDisciplina(Departamento* dep) { this->departamentoDisciplina = dep; }
	Departamento* getDepartamento() { return this->departamentoDisciplina; }

	//funcoes pertencentes a lista
	int getQuantidadeAlunos() { return this->lista_alunos.getQuantidadeAlunos(); }
	void incluirAluno(Aluno* alun) { lista_alunos.incluirAluno(alun); }
	void removerAluno(Aluno* alun) { lista_alunos.removerAluno(alun); }
	void mostraListaAlunos() { cout << "Disciplina " << this->nome << " possui os alunos : " << endl; this->lista_alunos.mostraListaAlunos(); }
	void setDadosAlunoDisciplina(Aluno* alun) { this->lista_alunos.setDadosAluno(alun); }
	int getId() { return this->id; }
	void setId(int id) { this->id = id; }

};


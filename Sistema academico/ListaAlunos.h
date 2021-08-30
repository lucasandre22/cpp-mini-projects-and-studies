#include "ListaTemplate.h"
#include "stdafx.h"
#pragma once

class Disciplina;

class Aluno;

class ListaAlunos
{
private:
	int quantidade_maxima_alunos;
	int id;
	Disciplina* disciplina_lista_alunos;
	List::List<Aluno*> lista_alunos;
	List::Iterator<Aluno*> iterator;
public:
	ListaAlunos(Disciplina* disciplina = nullptr, int id = 0, int quantidade_maxima_alunos = 45);
	virtual ~ListaAlunos();
	int getQuantidadeAlunos() { return this->lista_alunos.GetSize(); }
	int getQuantidadeMaximaAlunos() { return this->quantidade_maxima_alunos; }
	void incluirAluno(Aluno* aluno) { this->lista_alunos.Include(aluno); }
	void removerAluno(Aluno* aluno) { this->lista_alunos.Remove(aluno); }
	void mostraListaAlunos();
	void setDadosAluno(Aluno* aluno);
	Aluno* localizarAluno(string nome);
	void gravaAlunos();
};


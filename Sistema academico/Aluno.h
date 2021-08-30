#include "stdafx.h"
#include "Pessoa.h"
#include "Disciplina.h"
#pragma once

class Aluno : public Pessoa
{
private:
	Disciplina* disciplinaCursando;
	int RA;
public:
	Aluno(int diaNas = 0, int mesNas = 0, int anoNas = 0, string nome = "",int RA = -1);
	~Aluno();
	void setRA(int RA) { this->RA = RA; }
	int getRA() { return this->RA; }
	void InformaNomeDepartamentoEstudou();
	void InformaNomeUniversidadeAluno();
	void Print() { std::cout << this->nome << std::endl; }
	void setDisciplina(Disciplina* disc) { this->disciplinaCursando = disc; }
	Disciplina* getDisciplina() { return this->disciplinaCursando; }
	void mostraDisciplinaCursando() { cout << "Aluno " << this->nome << " cursa a disciplina " << endl << disciplinaCursando->getNomeDisciplina() << endl;  }

};


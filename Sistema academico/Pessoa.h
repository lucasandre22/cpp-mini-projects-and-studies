#include "stdafx.h"
#include "Universidade.h"
#pragma once
class Pessoa
{
protected:
	string nome;
	int idade;
	int diaNas;
	int mesNas;
	int anoNas;
	Universidade* universidadePessoa;
	Departamento* departamentoPessoa;
	int id;
	static int quantidadePessoas;
public:
	Pessoa(int diaNas = 0, int mesNas = 0, int anoNas = 0, string nome = " ", int id = -1);
	~Pessoa();
	void CalculaIdade(int diaAtual, int mesAtual, int anoAtual);
	void InformaNome();
	void InformaNomeEIdade();
	void CalculaIdadeImprime(int diaAtual, int mesAtual, int anoAtual);
	string getNome() { return this->nome; }
	void SetNome(string nome) { this->nome = nome; }
	void setUniversidade(Universidade* universidade) { this->universidadePessoa = universidade; }
	void setDepartamento(Departamento* dep) { this->departamentoPessoa = dep; }
	int getId() { return this->id; }
	void setId(int id) { this->id = id; }
	virtual void InformaProventos() {}
	
};


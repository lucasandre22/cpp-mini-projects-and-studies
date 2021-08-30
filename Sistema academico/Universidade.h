#include "stdafx.h"
#include "ListaDepartamentos.h"
#pragma once
class Universidade
{
private:
	string nome;
	ListaDepartamentos lista_departamentos;
	int id;
public:
	Universidade(string nome = "");
	~Universidade();
	string getNome() { return this->nome; }
	void setNome(string nome) { this->nome = nome; }
	int getId() { return this->id; }
	void setId(int id) { this->id = id; }

	//funcoes pertercentes a lista
	void mostraListaDepartamentos() { cout << this->nome << " possui os departamentos : " << endl; lista_departamentos.mostraListaDepartamentos(); }
	int getQuantidadeDepartamentos() { return lista_departamentos.getQuantidadeDepartamentos(); }
	void incluirDepartamento(Departamento* departamento) { lista_departamentos.incluirDepartamento(departamento); }
	void removerDepartamento(Departamento* departamento) { lista_departamentos.removerDepartamento(departamento); }

};

//vector< Departamento* > departamentos;
//FUNÇõES USADAS QUANDO ERA VECTOR
//void setDepartamento(Departamento* departamento); //departamentos.emplace(departamentos.begin(), departamento);
//Departamento* getDepartamento(int i) { return this->departamentos[i]; }
//int getQuantidadeDepartamentos() { return this->departamentos.size(); }
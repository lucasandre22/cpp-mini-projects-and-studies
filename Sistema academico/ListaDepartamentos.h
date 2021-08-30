#include "ListaTemplate.h"
#include "stdafx.h"
#pragma once
class Universidade;
class Departamento;

class ListaDepartamentos
{
private:
	Universidade* universidade_lista_departamentos;
	List::List<Departamento*> lista_departamentos;
	List::Iterator<Departamento*> iterator;
public:
	ListaDepartamentos(Universidade* universidade = nullptr);
	virtual ~ListaDepartamentos();

	int getQuantidadeDepartamentos() { return this->lista_departamentos.GetSize(); }
	void mostraListaDepartamentos();
	void incluirDepartamento(Departamento* departamento) { this->lista_departamentos.Include(departamento); }
	void removerDepartamento(Departamento* departamento) { this->lista_departamentos.Remove(departamento); }
	Departamento* localizaDepartamento(string nome);
	void gravaDepartamentos();
};


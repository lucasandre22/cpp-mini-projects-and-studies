#include "ListaTemplate.h"
#include "stdafx.h"
#pragma once

class Universidade;

class ListaUniversidades
{
private:
	List::List<Universidade*> lista_universidades;
	List::Iterator<Universidade*> iterator;
public:
	ListaUniversidades();
	virtual ~ListaUniversidades();

	int getTamanhoListaUniversidades() { return this->lista_universidades.GetSize(); }
	void incluirUniversidade(Universidade* univ) { this->lista_universidades.Include(univ); }
	void removerUniversidade(Universidade* univ) { this->lista_universidades.Remove(univ); }
	void mostraUniversidades();
	Universidade* localizaUniversidade(string nome);
	void gravaUniversidades();
};


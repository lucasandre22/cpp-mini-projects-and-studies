#include "ListaTemplate.h"
#include "Pessoa.h"
#pragma once
class ListaPessoas
{
private:
	List::List<Pessoa*> lista_pessoas;
	List::Iterator<Pessoa*> iterator;
public:
	ListaPessoas() : iterator(&lista_pessoas) {}
	virtual ~ListaPessoas() {}
	
	int GetTamanho() { return this->lista_pessoas.GetSize(); }
	void IncluirPessoa(Pessoa* pessoa) { this->lista_pessoas.Include(pessoa); }
	void RemoverPessoa(Pessoa* pessoa) { this->lista_pessoas.Remove(pessoa); }
	void MostraPessoas();
	void push_back(Pessoa* pessoa) { this->lista_pessoas.push_back(pessoa); }
	void Delete() { lista_pessoas.Delete(); }
	Pessoa* LocalizaPessoa(string nome);
	void GravaPessoas();
	List::List<Pessoa*>& GetLista() { return this->lista_pessoas; }
};


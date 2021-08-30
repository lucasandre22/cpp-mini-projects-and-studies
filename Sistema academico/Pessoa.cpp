#include "Pessoa.h"
#include <iostream>

int Pessoa::quantidadePessoas = 0; //static

Pessoa::Pessoa(int diaNas, int mesNas, int anoNas, string nome, int id)
{
	this->diaNas = diaNas;
	this->mesNas = mesNas;
	this->anoNas = anoNas;
	this->idade = 0;
	this->nome = nome;
	this->universidadePessoa = nullptr;
	this->departamentoPessoa = nullptr;
	this->id = id;
	this->quantidadePessoas++;
}

Pessoa::~Pessoa() 
{

}

void Pessoa::CalculaIdade(int diaAtual, int mesAtual, int anoAtual)
{
	this->idade = anoAtual - this->anoNas;
	if (mesAtual < this->mesNas || mesAtual == mesNas && this->diaNas > diaAtual)
		this->idade--;
}

void Pessoa::InformaNome()
{
	if(nome != "")
		cout << "Pessoa " << this->nome;
}

void Pessoa::InformaNomeEIdade()
{
	InformaNome();
	this->idade < 120 ? cout << " possui " : cout << " possuiria ";
	cout << this->idade << " anos." << endl;
}

void Pessoa::CalculaIdadeImprime(int diaAtual, int mesAtual, int anoAtual)
{
	CalculaIdade(diaAtual, mesAtual, anoAtual);
	InformaNomeEIdade();
}
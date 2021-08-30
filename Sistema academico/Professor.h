#pragma once
#include "Pessoa.h"


class Professor : public Pessoa
{
private:
	float salario;
	float bolsa_projeto;
public:
	Professor(int diaNas = 0, int mesNas = 0, int anoNas = 0, string nome = "", float salario = 0.0f, float bolsa = 0.0f);
	~Professor();
	void InformaNomeDepartamentoTrabalhou();
	void InformaNomeUniversidadeProfessor() { cout << "Trabalha/trabalhou na " << this->universidadePessoa->getNome() << endl; }
	void InformaProventos() { std::cout << this->nome << " tem salario de " << salario+bolsa_projeto << std::endl; }
	void SetSalario(float salario) { this->salario = salario; }
	void SetBolsaProjeto(float bolsa) { this->bolsa_projeto = bolsa; }
	float GetSalario() { return this->salario; }
	float GetBolsa() { return this->bolsa_projeto; }


};
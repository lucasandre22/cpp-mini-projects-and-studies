#include "Professor.h"
#include "Departamento.h"

Professor::Professor(int diaNas, int mesNas, int anoNas, string nome, float salario, float bolsa) :
	Pessoa(diaNas, mesNas, anoNas, nome)
{
	this->salario = 0;
	this->bolsa_projeto = 0;
}

Professor::~Professor()
{

}

void Professor::InformaNomeDepartamentoTrabalhou()
{
	cout << "Trabalhou no departamento " << this->departamentoPessoa->getNomeDepartamento() << endl;
}
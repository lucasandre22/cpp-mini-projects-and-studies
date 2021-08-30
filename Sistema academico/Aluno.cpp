#include "Aluno.h"
#include "Departamento.h"

Aluno::Aluno(int diaNas, int mesNas, int anoNas, string nome, int RA) : Pessoa(diaNas, mesNas, anoNas, nome)
{
	this->RA = RA;
	this->disciplinaCursando = nullptr;
}

Aluno::~Aluno()
{

}

void Aluno::InformaNomeDepartamentoEstudou()
{
	cout << "Estuda no departamento " << this->departamentoPessoa->getNomeDepartamento() << endl;
}
void Aluno::InformaNomeUniversidadeAluno()
{
	cout << "Estuda na " << this->universidadePessoa->getNome() << endl;
}
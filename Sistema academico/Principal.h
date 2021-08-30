#include "Aluno.h"
#include "Departamento.h"
#include "stdafx.h"
#include "Professor.h"
#include "Disciplina.h"
#include "ListaUniversidades.h"
#include "ListaTemplate.h"
#include "ListaPessoas.h"
#include "Estagiario.h"
#pragma once
class Principal
{
private:
	int diaAtual;
	int mesAtual;
	int anoAtual;
	int idAlunos;
	int idUniversidades;
	int idDisciplinas;
	int idDepartamentos;
	int idPessoas;

	Aluno Lucas; //as construtoras desses objetos instanciados aqui são chamadas explicitamente na construtora da classe principal!
	Aluno Pedro;
	Professor Einstein;
	Professor Simao;

	Estagiario Monitor;
	
	Universidade UTFPR;
	Universidade PUCPR;
	Universidade PRINCETON;

	Departamento DAINF;
	Departamento FISICA;
	Departamento DAEL;
	Departamento LETRAS;

	Disciplina Tecnicas;
	Disciplina Estrutura2;
	Disciplina FundamentosDeProg;

	ListaUniversidades lista_universidades;
	ListaDepartamentos lista_departamentos;
	ListaDisciplinas lista_disciplinas;
	ListaPessoas lista_pessoas;


public:
	Principal();
	~Principal();

	void executar();

	void inicializaUniversidades();
	void inicializaDepartamentos();
	void inicializaDisciplinas();
	void inicializaPessoas();

	void menu();
	void menuCadastrar();
	void menuMostraListas();
	void gravaListas();
	void recuperaListas();

	void cadastraUniversidade();
	void cadastraDepartamento(); //pesquisa nome universidade dentro da lista de universidades
	void cadastraDisciplina();

	void testarLista();
	void listaProventosPessoas();

};


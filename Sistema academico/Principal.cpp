#include "Principal.h"
#include <Windows.h>

Principal::Principal() : Lucas(22, 8, 2000, "Lucas Andre", 2137070), Pedro(21, 11, 1993, "Pedro Henrique"), Einstein(14, 3, 1879, "Albert Einstein"), Simao(3,10,1976, "Jean Simao")
//quando é preciso chamar a construtora de um objeto instanciado na classe, chama-se explicitamente na construtora da classe com essa sintaxe
{
	SYSTEMTIME st;
	GetSystemTime(&st);
	diaAtual = st.wDay;
	mesAtual = st.wMonth;
	anoAtual = st.wYear;
	this->idAlunos = 0;
	this->idUniversidades = 0;
	this->idDisciplinas = 0;
	this->idDepartamentos = 0;
	this->idPessoas = 0;
	inicializaUniversidades();
	inicializaDepartamentos();
	inicializaDisciplinas();
	inicializaPessoas();
}

Principal::~Principal()
{

}

void Principal::executar()
{
	Lucas.CalculaIdadeImprime(diaAtual, mesAtual, anoAtual);
	Lucas.InformaNomeUniversidadeAluno();
	Lucas.InformaNomeDepartamentoEstudou();
	Pedro.CalculaIdadeImprime(diaAtual, mesAtual, anoAtual);
	Pedro.InformaNomeUniversidadeAluno();
	Pedro.InformaNomeDepartamentoEstudou();
	Einstein.CalculaIdadeImprime(diaAtual, mesAtual, anoAtual);
	Einstein.InformaNomeUniversidadeProfessor();
	Einstein.InformaNomeDepartamentoTrabalhou();

	cout << "-------------" << endl;
	UTFPR.mostraListaDepartamentos();
	PUCPR.mostraListaDepartamentos();
	PUCPR.removerDepartamento(&DAINF);
	PUCPR.mostraListaDepartamentos();
	PRINCETON.mostraListaDepartamentos();

	cout << "-------------" << endl;
	DAINF.mostraDisciplinas();

	cout << "-------------" << endl;
	Tecnicas.mostraListaAlunos();
	Estrutura2.mostraListaAlunos();
	FundamentosDeProg.mostraListaAlunos();
	Tecnicas.removerAluno(&Lucas);
	cout << "-------------" << endl;
	Tecnicas.mostraListaAlunos();
}

void Principal::inicializaUniversidades()
{
	//set nome universidades
	UTFPR.setNome("Universidade Tecnologica Federal do Parana");
	PUCPR.setNome("Pontificia Universidade Catolica do Parana");
	PRINCETON.setNome("Universidade de Princeton");

	//set id
	UTFPR.setId(idUniversidades++);
	PUCPR.setId(idUniversidades++);
	PRINCETON.setId(idUniversidades++);

	//inclui departamentos
	UTFPR.incluirDepartamento(&DAINF);
	UTFPR.incluirDepartamento(&DAEL);
	PUCPR.incluirDepartamento(&DAINF);
	PUCPR.incluirDepartamento(&LETRAS);
	PRINCETON.incluirDepartamento(&FISICA);

	lista_universidades.incluirUniversidade(&UTFPR);
	lista_universidades.incluirUniversidade(&PUCPR);
	lista_universidades.incluirUniversidade(&PRINCETON);
}

void Principal::inicializaDepartamentos()
{
	//set nome departamentos
	DAINF.setNomeDepartamento("Departamento Academico de Informatica");
	FISICA.setNomeDepartamento("Departamento de Fisica");
	DAEL.setNomeDepartamento("Departamento de Eletronica");
	LETRAS.setNomeDepartamento("Departamento de Letras");

	//set id
	DAINF.setId(idDepartamentos++);
	FISICA.setId(idDepartamentos++);
	DAEL.setId(idDepartamentos++);
	LETRAS.setId(idDepartamentos++);

	//set universidade dos departamentos
	DAINF.setUniversidade(&UTFPR);
	FISICA.setUniversidade(&PRINCETON);
	DAEL.setUniversidade(&UTFPR);
	LETRAS.setUniversidade(&PUCPR);

	//inclui disciplinas nos departamentos
	DAINF.incluirDisciplina(&Tecnicas);
	DAINF.incluirDisciplina(&Estrutura2);
	DAINF.incluirDisciplina(&FundamentosDeProg);

	//adiciona na lista
	lista_departamentos.incluirDepartamento(&DAINF);
	lista_departamentos.incluirDepartamento(&FISICA);
	lista_departamentos.incluirDepartamento(&DAEL);
	lista_departamentos.incluirDepartamento(&LETRAS);
}

void Principal::inicializaDisciplinas()
{
	//inicializa nome disciplinas
	Tecnicas.setNomeDisciplina("Tecnicas de programacao");
	Estrutura2.setNomeDisciplina("Estrutura de dados 2");
	FundamentosDeProg.setNomeDisciplina("Fundamentos de programacao");

	//set id
	Tecnicas.setId(idDisciplinas++);
	Estrutura2.setId(idDisciplinas++);
	FundamentosDeProg.setId(idDisciplinas++);

	//inclui alunos em disciplinas
	Tecnicas.incluirAluno(&Lucas);
	Tecnicas.incluirAluno(&Pedro);
	Estrutura2.incluirAluno(&Pedro);
	FundamentosDeProg.incluirAluno(&Lucas);

	//adiciona na lista
	lista_disciplinas.incluirDisciplina(&Tecnicas);
	lista_disciplinas.incluirDisciplina(&Estrutura2);
	lista_disciplinas.incluirDisciplina(&FundamentosDeProg);
}

void Principal::inicializaPessoas()
{
	Lucas.setUniversidade(&UTFPR);
	Pedro.setUniversidade(&PUCPR);
	Einstein.setUniversidade(&PRINCETON);
	Simao.setUniversidade(&UTFPR);

	Lucas.setDepartamento(&DAINF);
	Pedro.setDepartamento(&DAINF);
	Einstein.setDepartamento(&FISICA);
	Simao.setDepartamento(&DAINF);

	lista_pessoas.IncluirPessoa(static_cast<Pessoa*> (&Lucas));
	lista_pessoas.IncluirPessoa(&Pedro); //conversão automática, perde a segurança de um static_cast
	lista_pessoas.IncluirPessoa(static_cast<Pessoa*> (&Einstein)); 
	lista_pessoas.IncluirPessoa(static_cast<Pessoa*> (&Simao));
	lista_pessoas.IncluirPessoa(static_cast<Pessoa*> (&Monitor));

	Simao.SetBolsaProjeto(4000);
	Einstein.SetBolsaProjeto(4000);
	Monitor.SetBolsa(300);
	Monitor.SetNome("Luquinhas");

	Lucas.setId(idPessoas++);
	Pedro.setId(idPessoas++);
	Einstein.setId(idPessoas++);
	Simao.setId(idPessoas++);
	Monitor.setId(idPessoas++);
}

void Principal::menu()
{
	int opcao = -1;
	while (opcao != -5)
	{
		system("cls");
		cout << "1 - Executar" << endl;
		cout << "2 - Cadastrar" << endl;
		cout << "3 - Mostrar Listas" << endl;
		cout << "4 - Gravar Listas" << endl;
		cout << "5 - Recuperar Listas" << endl;
		cout << "6 - Testar Lista" << endl;
		cout << "7 - Sair" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case 1:
		{
			system("cls");
			executar();
			fflush(stdin);
			opcao = -5;
			break;
		}
		case 2:
		{
			system("cls");
			menuCadastrar();
			fflush(stdin);
			break;
		}
		case 3:
		{
			system("cls");
			menuMostraListas();
			fflush(stdin);
			break;
		}
		case 4:
		{
			system("cls");
			gravaListas();
			break;
		}
		case 5:
		{
			system("cls");
			recuperaListas();
			break;
		}
		case 6:
		{
			system("cls");
			testarLista();
			break;
		}
		case 7:
		{
			system("cls");
			fflush(stdin);
			opcao = -5;
			break;
		}
		default :
			cout << "Opcao invalida" << endl;
		}
	}
}

void Principal::menuCadastrar()
{
	int opcao = -1;
	while (opcao != -5)
	{
		system("cls");
		cout << "1 - Cadastrar Universidade" << endl;
		cout << "2 - Cadastrar Departamento" << endl;
		cout << "3 - Cadastrar Disciplina" << endl;
		cout << "4 - Sair" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case 1:
		{
			system("cls");
			cadastraUniversidade();			
			getchar();
			fflush(stdin);
			break;
		}
		case 2:
		{
			system("cls");
			cadastraDepartamento();
			getchar();
			fflush(stdin);
			break;
		}
		case 3:
		{
			system("cls");
			cadastraDisciplina();
			getchar();
			fflush(stdin);
			break;
		}
		case 4:
		{
			system("cls");
			getchar();
			fflush(stdin);
			opcao = -5;
			break;
		}
		default:
			cout << "Opcao invalida" << endl;
		}
	}
}

void Principal::menuMostraListas()
{
	int opcao = -1;
	while (opcao != -5)
	{
		system("cls");
		cout << "1 - Mostra lista Universidades" << endl;
		cout << "2 - Mostra lista Departamentos" << endl;
		cout << "3 - Mostra lista Disciplinas" << endl;
		cout << "4 - Mostra lista Alunos" << endl;
		cout << "5 - Mostra lista Pessoas" << endl;
		cout << "6 - Sair" << endl;
		cin >> opcao;
		switch (opcao)
		{
		case 1:
		{
			system("cls");
			lista_universidades.mostraUniversidades();
			getchar();
			getchar();
			fflush(stdin);
			break;
		}
		case 2:
		{
			system("cls");
			lista_departamentos.mostraListaDepartamentos();
			getchar();
			getchar();
			fflush(stdin);
			break;
		}
		case 3:
		{
			system("cls");
			lista_disciplinas.mostraDisciplinas();
			getchar();
			getchar();
			fflush(stdin);
			break;
		}
		case 4:
		{
			system("cls");
			lista_disciplinas.mostraDisciplinas();
			getchar();
			getchar();
			fflush(stdin);
			break;
		}
		case 5:
		{
			system("cls");
			lista_pessoas.MostraPessoas();
			getchar();
			getchar();
			fflush(stdin);
			break;
		}
		case 6:
		{
			system("cls");
			getchar();
			fflush(stdin);
			opcao = -5;
			break;
		}
		default:
			cout << "Opcao invalida" << endl;
		}
	}
}

void Principal::gravaListas()
{
	lista_universidades.gravaUniversidades();
	lista_departamentos.gravaDepartamentos();
	lista_disciplinas.gravaDisciplinas();
	lista_pessoas.GravaPessoas();
}

void Principal::recuperaListas()
{
	//lista_universidades.recuperaUniversidades();
	//lista_departamentos.recuperaDepartamentos();
	//lista_disciplinas.recuperaDisciplinas();
}

void Principal::cadastraUniversidade()
{
	string nome;
	cout << "Digite o nome da universidade : " << endl;
	cin >> nome;
	if (lista_universidades.localizaUniversidade(nome) == nullptr)
	{
		Universidade* univ = new Universidade;
		univ->setNome(nome);
		lista_universidades.incluirUniversidade(univ);
	}
}

void Principal::cadastraDepartamento()
{
	string nome;
	Universidade* univ;
	cout << "Digite o nome da universidade que queria cadastrar um departamento : " << endl;
	cin >> nome;
	univ = lista_universidades.localizaUniversidade(nome);
	if (univ)
	{
		Departamento* dep = new Departamento;
		cout << "Digite o nome do departamento : " << endl;
		cin >> nome;
		dep->setNomeDepartamento(nome);
		lista_departamentos.incluirDepartamento(dep);
		dep->setUniversidade(univ);
		
	}
	else
		cout << "Universidade nao existente!" << endl;
}

void Principal::cadastraDisciplina()
{
	string nome;
	Departamento* dep;
	cout << "Digite o nome do departamento que queira cadastrar uma disciplina : " << endl;
	cin >> nome;
	dep = lista_departamentos.localizaDepartamento(nome);
	if (dep)
	{
		Disciplina* disc = new Disciplina;
		cout << "Digite o nome do departamento : " << endl;
		cin >> nome;
		disc->setNomeDisciplina(nome);
		lista_disciplinas.incluirDisciplina(disc);
		disc->setDepartamentoDisciplina(dep);
	}
	else
		cout << "Universidade nao existente!" << endl;
}

void Principal::testarLista()
{
	/*List::List<Aluno*> lista;
	List::Iterator<Aluno*> iterator;
	Aluno* aux;
	//iterator.SetIteratorHead();
	//aux = iterator.GetIterator();
	lista.Include(&Lucas);
	lista.Include(&Pedro);
	lista.Include(&Lucas);
	iterator = lista;
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		aux = iterator.GetValue();
		std::cout << aux->getNome() << std::endl;
	}
	lista.Remove(&Lucas);
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		aux = iterator.GetValue();
		std::cout << aux->getNome() << std::endl;
	}
	lista_pessoas.MostraPessoas();
	std::cout << std::endl;
	lista_pessoas.push_back(&Pedro);
	lista_pessoas.MostraPessoas();
	std::cout << std::endl;
	lista_pessoas.Delete();
	lista_pessoas.MostraPessoas();
	lista_pessoas.push_back(&Pedro);
	lista_pessoas.IncluirPessoa(&Lucas);
	lista_pessoas.RemoverPessoa(&Pedro);
	lista_pessoas.MostraPessoas();
	lista_pessoas.push_back(&Einstein);
	std::cout << std::endl;
	lista_pessoas.MostraPessoas();*/
	//listaProventosPessoas();
	ListaAlunos lista_alunos;
	lista_alunos.incluirAluno(&Lucas);
	lista_alunos.incluirAluno(&Pedro);
	lista_alunos.mostraListaAlunos();
	std::cin.get();
	std::cin.get();

}

void Principal::listaProventosPessoas()
{
	List::Iterator<Pessoa*> iterator(&lista_pessoas.GetLista());
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
		iterator.GetValue()->InformaProventos();
}

#include "ListaAlunos.h"
#include "Aluno.h"
#include "Disciplina.h"

ListaAlunos::ListaAlunos(Disciplina* disciplina, int id, int quantidade_maxima_alunos)
{
	this->disciplina_lista_alunos = disciplina;
	this->quantidade_maxima_alunos = quantidade_maxima_alunos;
	this->id = id;
	this->iterator = this->lista_alunos;
}

ListaAlunos::~ListaAlunos()
{
}

void ListaAlunos::mostraListaAlunos()
{
	/*iterator = lista_alunos.GetFront();
	while (iterator != lista_alunos.GetBack())
	{
		std::cout << iterator.GetValue()->getNome() << std::endl;
		iterator++;
	}*/

	iterator.ForEach(([](Aluno* aluno) { cout << aluno->getNome() << endl; })); //utilizando ponteiro pra função (lambda)

	/*for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
		cout << iterator.GetValue()->getNome() << endl;*/
}

void ListaAlunos::setDadosAluno(Aluno* aluno)
{
	Aluno* aux = localizarAluno(aluno->getNome());
	if (aux == nullptr)
	{
		std::cout << "Aluno nao encontrado!" << std::endl;
		return;
	}
	else
	{
		int n;
		std::cout << "Aluno " << aux->getNome() << " na disciplina " << this->disciplina_lista_alunos->getNomeDisciplina() << endl;
		std::cout << "Digite a primeira nota parcial : ";
		std::cin >> n;
		//aux->setNotaPrimeiraParcial(n);
		std::cout << "Digite a segunda nota parcial : ";
		std::cin >> n;
		//aux->setNotaSegundaParcial(n);
		std::cout << "Digite o total de faltas : ";
		std::cin >> n;
		//aux->setFaltas(n);
	}
}

Aluno* ListaAlunos::localizarAluno(string aluno)
{
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator) {}
	if (iterator.IteratorNull())
		return nullptr;
	return iterator.GetValue();
}

void ListaAlunos::gravaAlunos()
{
	ofstream GravadorAlunos("alunos.dat", ios::out);
	if (!GravadorAlunos)
	{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush(stdin);
		getchar();
		return;
	}
	for(iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		Aluno* pauxAluno;
		pauxAluno = iterator.GetValue();
		GravadorAlunos << pauxAluno->getId() << ' '
			<< pauxAluno->getRA() << ' '
			<< pauxAluno->getNome() << endl;
	}
	GravadorAlunos.close();
}
#include "ListaDisciplinas.h"
#include "Disciplina.h"

ListaDisciplinas::ListaDisciplinas(Departamento* dep)
{
	this->iterator = this->lista_departamentos; //this->iterator.SetList(this->lista_departamentos);
	this->departamento_lista_disciplinas = dep;
}

ListaDisciplinas::~ListaDisciplinas()
{
	
}

void ListaDisciplinas::mostraDisciplinas()
{
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
		cout << iterator.GetValue()->getNomeDisciplina() << endl;
}

Disciplina* ListaDisciplinas::localizaDisciplina(string nome)
{
	for (iterator.SetIteratorHead(); !iterator.IteratorNull() && iterator.GetValue()->getNomeDisciplina() != nome; ++iterator) {}
	if (iterator.IteratorNull())
		return nullptr;
	return iterator.GetValue();
}

void ListaDisciplinas::gravaDisciplinas()
{
	ofstream GravadorDisciplinas("disciplinas.dat", ios::out);
	if (!GravadorDisciplinas)
	{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush(stdin);
		std::cin.get();
		return;
	}
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		Disciplina* disc;
		disc = iterator.GetValue();
		GravadorDisciplinas << disc->getId() << ' '
			<< disc->getNomeDisciplina() << ' '
			<< disc->getQuantidadeAlunos() << endl;
	}
	GravadorDisciplinas.close();
}



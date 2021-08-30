#include "ListaDepartamentos.h"
#include "Universidade.h"
#include "Departamento.h"

ListaDepartamentos::ListaDepartamentos(Universidade* universidade)
{
	this->universidade_lista_departamentos = universidade;
	iterator.SetList(this->lista_departamentos);
}

ListaDepartamentos::~ListaDepartamentos()
{
	
}

Departamento* ListaDepartamentos::localizaDepartamento(string nome)
{
	for (this->iterator.SetIteratorHead(); !iterator.IteratorNull() && iterator.GetValue()->getNomeDepartamento() != nome; ++iterator) {}
	if (iterator.IteratorNull())
		return nullptr;
	return iterator.GetValue();
}

void ListaDepartamentos::mostraListaDepartamentos()
{
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
		cout << iterator.GetValue()->getNomeDepartamento() << endl;
}

void ListaDepartamentos::gravaDepartamentos()
{
	ofstream GravadorDepartamentos("departamentos.dat", ios::out);
	if (!GravadorDepartamentos)
	{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush(stdin);
		std::cin.get();
		return;
	}
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		Departamento* dep;
		dep = iterator.GetValue();
		GravadorDepartamentos << dep->getId() << ' '
			<< dep->getNomeDepartamento() << endl;
	}
	GravadorDepartamentos.close();
}
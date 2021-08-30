#include "ListaUniversidades.h"
#include "Universidade.h"

ListaUniversidades::ListaUniversidades()
{
	this->iterator = this->lista_universidades;
}

ListaUniversidades::~ListaUniversidades()
{
}

void ListaUniversidades::mostraUniversidades()
{
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
		cout << iterator.GetValue()->getNome() << endl;
}

Universidade* ListaUniversidades::localizaUniversidade(string nome)
{
	for (iterator.SetIteratorHead(); !iterator.IteratorNull() && iterator.GetValue()->getNome() != nome; ++iterator) { }
	if (iterator.IteratorNull())
		return nullptr;
	return iterator.GetValue();
}

void ListaUniversidades::gravaUniversidades()
{
	ofstream GravadorUniversidades("universidades.dat", ios::out);
	if (!GravadorUniversidades)
	{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush(stdin);
		std::cin.get();
		return;
	}
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		Universidade* univ;
		univ = iterator.GetValue();
		GravadorUniversidades << univ->getId() << ' '
			<< univ->getNome() << endl;
	}
	GravadorUniversidades.close();
}



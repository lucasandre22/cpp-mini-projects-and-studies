#include "ListaPessoas.h"
#include "stdafx.h"

void ListaPessoas::MostraPessoas()
{
    for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator) {
        std::cout << iterator.GetValue()->getNome() << std::endl;
    }
}

Pessoa* ListaPessoas::LocalizaPessoa(string nome)
{
    for (iterator.SetIteratorHead(); !iterator.IteratorNull() && iterator.GetValue()->getNome() != nome; ++iterator) {}
    if(iterator.IteratorNull())
        return nullptr;
    return iterator.GetValue();
}

void ListaPessoas::GravaPessoas()
{
	ofstream GravadorPessoas("pessoas.dat", ios::out);
	if (!GravadorPessoas)
	{
		cerr << " Arquivo não pode ser aberto " << endl;
		fflush(stdin);
		std::cin.get();
		return;
	}
	for (iterator.SetIteratorHead(); !iterator.IteratorNull(); ++iterator)
	{
		Pessoa* pessoa;
		pessoa = iterator.GetValue();
		GravadorPessoas << pessoa->getId() << ' '
			<< pessoa->getNome() << ' ' << endl;
	}
	GravadorPessoas.close();
}

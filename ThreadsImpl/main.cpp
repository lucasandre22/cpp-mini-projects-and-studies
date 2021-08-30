#include "Thread.h"
#include <Windows.h>
#include <iostream>
#include <string>


class Piloto : public Thread{
private:
	std::string nome;
	int voltaAtual;
	Piloto* irmao;
public:
	Piloto(std::string nome) { this->nome = nome; voltaAtual = 1; irmao = nullptr; }
	~Piloto() {}
	void run() override {

		for (voltaAtual; voltaAtual <= 100; voltaAtual++)
		{
			if (voltaAtual % 10 == 0 && voltaAtual > irmao->voltaAtual)
			{
				lock();
				std::cout << nome << " esperando o irmao!" << std::endl;
				unlock();
				yield(); //informa ao programa que está oferecendo os recursos dessa thread para outra
			}
			lock();
			std::cout << nome << " esta na volta " << voltaAtual << std::endl;
			unlock();
		}
	}
	void setIrmao(Piloto* a) { this->irmao = a; }
};


int main()
{
	Piloto Michael("Michael");
	Piloto Ralf("Ralf");
	Michael.setIrmao(&Ralf);
	Ralf.setIrmao(&Michael);
	Michael.start();
	Ralf.start();
	Michael.join();
	Ralf.join();
}
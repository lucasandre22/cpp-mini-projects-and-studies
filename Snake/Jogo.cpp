#include "Jogo.h"
#include <conio.h>
#include <windows.h>
#include <iostream>

void Jogo::MostraJogo()
{
	system("CLS"); 
	for (int i = -1; i < sizeX + 1; i++) 
	{ 
		for (int j = -1; j < sizeY + 1; j++)
		{
			if (cobra.VerificaDesenhaCorpo(i, j))
				std::cout << 0;
			else if (i == -1 || j == -1 || i == sizeX || j == sizeY)
				std::cout << '#';
			else if (this->fruta.GetX() == i && this->fruta.GetY() == j)
				std::cout << 'X';
			else
				std::cout << ' ';
		}
		std::cout << '\n'; 
	}
}

void Jogo::Executar()
{
	while (cobra.Viva())
	{
		Sleep(30);
		AtualizaMovimentoCobra();
		VerificaFrutaComida();
		VerificaBateuCorpo();
		MostraJogo();
	}
	MostraPontuacao();
}

void Jogo::AtualizaMovimentoCobra()
{
	input.AtualizaMovimentoCobra();
	VerificaCobraForaTabuleiro();
}

void Jogo::VerificaCobraForaTabuleiro()
{
	if (cobra.GetX() >= this->sizeX || cobra.GetX() < 0
		|| cobra.GetY() >= this->sizeY || cobra.GetY() < 0)
		cobra.SetViva(false);
}


void Jogo::VerificaFrutaComida()
{
	fruta.VerificaFrutaComida();
}

void Jogo::VerificaBateuCorpo()
{
	if (cobra.VerificaColisaoCorpo(cobra.GetX(), cobra.GetY()))
		cobra.SetViva(false);
}

void Jogo::MostraPontuacao()
{
	this->pontuacao = cobra.GetTamanho() - 2;
	std::cout << std::endl;
	std::cout << "------- FIM DE JOGO -------" << std::endl;
	std::cout << "PONTUACAO : " << this->pontuacao << std::endl;
	std::cin.get();
}



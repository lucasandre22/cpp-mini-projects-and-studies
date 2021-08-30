#include "Input.h"
#include <conio.h>

void Input::InputTeclado()
{
	if (_kbhit())
	{
		switch (_getch()) {
		case 'a': //esquerda
		{
			if(cobra->GetVelocidadeX() != 0 && cobra->GetVelocidadeY() != 1)
				Esquerda();
			break;
		}
		case 'd': //direita
		{
			if (cobra->GetVelocidadeX() != 0 && cobra->GetVelocidadeY() != -1)
				Direita();
			break;
		}
		case 's': //baixo
		{
			if (cobra->GetVelocidadeX() != -1 && cobra->GetVelocidadeY() != 0)
				Baixo();
			break;
		}
		case 'w': //cima
		{
			if (cobra->GetVelocidadeX() != 1 && cobra->GetVelocidadeY() != 0)
				Cima();
			break;
		}
		default:
		{
			break;
		}
		}
	}
}

void Input::AtualizaMovimentoCobra()
{
	InputTeclado();
	cobra->AtualizaMovimento();
}



#include "Player.h"
#include <conio.h>
#pragma once

class Input
{
private:
	Player* player;
public:
	Input(Player* p) { this->player = p; }
	~Input() {}
	void input()
	{
		if (_kbhit())
		{
			switch (_getch()) {
			case 'a': //esquerda
			{
				if (player->getX() != 1)
					player->moverEsquerda();
				break;
			}
			case 'd': //direita
			{
				if (player->getX() != 20)
					player->moverDireita();
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
};


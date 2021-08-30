#include "Jogo.h"

void Jogo::desenhaTela()
{
	system("CLS");
	iterator = obstacles.begin();
	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 22; x++)
		{
			//std::cout << (*iterator)->getX() << ' ' << (*iterator)->getY() << std::endl;
			if (x == 0 || x == 21 || y == 12 || y == 0)
				std::cout << '@';
			else if (iterator != obstacles.end() && x == (*iterator)->getX() && y == (*iterator)->getY())
				std::cout << '#';
			else if (x == player.getX() && y == player.getY())
				std::cout << 'X';
			else
				std::cout << ' ';
		}
		if(iterator != obstacles.end())
			iterator++;
		//std::cout << (*iterator)->getX() << ' ' << (*iterator)->getY();
		std::cout << '\n';
	}
}

void Jogo::executar()
{
	while (player.getAlive())
	{
		input.input();
		atualizaObstaculos();
		desenhaTela();
		verificaColisao();
		Sleep(50);
	}
	gameOver();
}

void Jogo::verificaColisao()
{
	if ((*obstacles.crbegin())->getX() == player.getX() && (*obstacles.crbegin())->getY() == player.getY())
		player.setAlive(false);
}

void Jogo::atualizaObstaculos()
{
	std::list<Obstacle*>::iterator it;
	for (it = obstacles.begin(); it != obstacles.end(); it++)
		(*it)->update();
	if (obstacles.size() == 12)
	{
		std::cout << "Popou!" << std::endl;
		popObstaculo();
		criaObstaculo();
	}
	else
	{
		criaObstaculo();
	}
}

void Jogo::gameOver()
{
	std::cout << "GAME OVER" << std::endl;
	std::cin.get();
}

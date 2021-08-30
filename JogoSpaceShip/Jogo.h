#include "Player.h"
#include "Obstacle.h"
#include "Input.h"
#include <ctime>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <list>
#pragma once
class Jogo
{
private:
	Player player;
	std::list<Obstacle*> obstacles;
	std::list<Obstacle*>::iterator iterator;
	Input input;
public:
	Jogo() : player(), input(&player) {
	}
	~Jogo() {}
	void criaObstaculo() {
		srand(static_cast <unsigned> (time(0)));
		obstacles.emplace_front(new Obstacle((rand() % 19) + 1, 1));
	} //de 1 até 10
	void popObstaculo() { obstacles.erase(std::prev(obstacles.end())); }
	void desenhaTela();
	void executar();
	void verificaColisao();
	void atualizaObstaculos();
	void gameOver();
};


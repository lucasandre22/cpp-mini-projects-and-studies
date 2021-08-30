#include "Snake.h"
#pragma once
class Input
{
private:
	Snake* cobra;
public:
	Input(Snake* cobra) { this->cobra = cobra; }
	~Input() { this->cobra = nullptr; }
	void AtualizaMovimentoCobra();
	void InputTeclado();
	void Direita() { cobra->SetVelocidade(0, 1); }
	void Esquerda() { cobra->SetVelocidade(0, -1); }
	void Cima() { cobra->SetVelocidade(-1, 0); }
	void Baixo() { cobra->SetVelocidade(1, 0); }
};


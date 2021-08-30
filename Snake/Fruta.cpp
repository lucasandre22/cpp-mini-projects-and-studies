#include "Fruta.h"
#include "Snake.h"
#include <stdlib.h>
#include <time.h>

void Fruta::GeraFruta()
{
    srand(time(NULL));
    this->posicaoX = rand() % 15;
    this->posicaoY = rand() % 25;
}

void Fruta::VerificaFrutaComida()
{
    if (this->cobra->GetX() == posicaoX && this->cobra->GetY() == posicaoY)
    {
        GeraFruta();
        cobra->AumentaTamanho();
    }
        
}

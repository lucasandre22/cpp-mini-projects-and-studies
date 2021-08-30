#include <string>
using namespace std;

#pragma once

class Carta
{
private:
    string nomeCarta;
    string naipe;
    bool cartaNumerica;
    unsigned int pontosCarta;
public:
    Carta(string nome = " ", unsigned int pontos = 0, string naipe = " ", bool numerica = false) { this->nomeCarta = nome; this->pontosCarta = pontos; this->naipe = naipe; this->cartaNumerica = numerica; }
    ~Carta() { delete this; }
    string getNomeCarta() { return this->nomeCarta; }
    string getNaipeCarta() { return this->naipe; }
    void setNomeCarta(string nome) { this->nomeCarta = nome; }
    void setPontosCarta(unsigned int pontos) { this->pontosCarta = pontos; }
    unsigned int getPontosCarta() { return this->pontosCarta; }
    bool getCartaNumerica() { return this->cartaNumerica; }
};


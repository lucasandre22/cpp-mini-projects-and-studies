#pragma once
#include "Aluno.h"
class Estagiario :
    public Aluno
{
private:
    float BolsaEstudo;
public:
    Estagiario(int diaNas = 0, int mesNas = 0, int anoNas = 0, 
        string nome = "", int RA = -1, float BolsaEstudo = 0.0f) : Aluno(diaNas, mesNas, anoNas, nome, RA) { this->BolsaEstudo = BolsaEstudo; }
    ~Estagiario() {}
    void InformaProventos() { std::cout << this->nome << " recebe " << this->BolsaEstudo << " de bolsa estudo." << std::endl; }
    float GetBolsa() { return this->BolsaEstudo; }
    void SetBolsa(float bolsa) { this->BolsaEstudo = bolsa; }
};


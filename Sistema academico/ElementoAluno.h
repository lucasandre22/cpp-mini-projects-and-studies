class Aluno;
#pragma once
class ElementoAluno
{
private:
	Aluno* aluno;
	int notaPrimeiraParcial;
	int notaSegundaParcial;
	int faltas;
public:
	ElementoAluno(Aluno* alun = nullptr);
	~ElementoAluno();
	Aluno* getAluno() { return this->aluno; }
	void setAluno(Aluno* alun) { this->aluno = alun; }
	int getNotaPrimeiraParcial() { return this->notaPrimeiraParcial; }
	int getNotaSegundaParcial() { return this->notaSegundaParcial; }
	int getFaltas() { return this->faltas; }
	void setNotaPrimeiraParcial(int nota) { this->notaPrimeiraParcial = nota; }
	void setNotaSegundaParcial(int nota) { this->notaSegundaParcial = nota; }
	void setFaltas(int faltas) { this->faltas = faltas; }
	ElementoAluno* proximo;
	ElementoAluno* anterior;
};


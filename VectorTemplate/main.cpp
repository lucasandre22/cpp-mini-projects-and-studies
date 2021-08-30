#include <iostream>
#include <string>
#include "VetorTemplate.h"

template <typename T>
void Print(Vetor<T>& vetor) 
{
	for (int i = 0; i < vetor.GetSize(); i++)
		std::cout << vetor[i] << std::endl;
}

int main()
{
	Vetor<int> vetor;
	Vetor<std::string> vetor1;
	int* aa = new int[5];
	int* b;
	b = aa;
	for (int i = 0; i < 5; i++)
	{
		aa[i] = i;
		std::cout << b[i] << std::endl;
	}
	vetor.push_back(4);
	vetor.push_back(4);
	vetor.push_back(4);
	vetor.push_back(4);
	vetor.push_back(4);
	vetor.push_back(4);
	vetor.push_back(4);
	vetor1.push_back("Lucas");
	Print(vetor);
	Print(vetor1);
		
}
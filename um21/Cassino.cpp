#include "Cassino.h"

Cassino::Cassino()
{
	this->listaJogadores = ListaJogadores::getInstance();
	this->quantidadeJogadores = 0;
}

Cassino::~Cassino()
{
	
}

int Cassino::menuCassino()
{

	int option = 0;
	do {
		cout << "BEM-VINDOS AO CASSINO LUCKY PLACE" << endl;
		cout << "********* MENU DO CASSINO, POR FAVOR ESCOLHA UM JOGO *********" << endl;
		cout << "1 - Jogar Blackjack" << endl << "2 - Jogar Truco" << endl << "3 - Sair" << endl;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			system("CLS");
			jogarBlackjack();
			Sleep(10000);
			break;
		}
		case 2:
		{
			system("CLS");
			jogarTruco();
			Sleep(1000);
			break;
		}
		case 3:
		{
			system("CLS");
			cout << "Obrigado, volte sempre!" << endl;
			Sleep(3000);
			break;
		}
		default:
		{
			system("CLS");
			cout << "Por favor, digite um numero contido no menu." << endl;
			break;
		}
		}
	} while (option != 3);
	if (option != 3)
	{
		system("CLS");
		cout << "Jogo terminado, obrigado por jogar!" << endl;
	}
	return 0;
}

void Cassino::criaJogadoresBlackjack()
{
	cout << "Digite a quantidade de jogadores:" << endl;
	cin >> quantidadeJogadores;
	system("CLS");
	listaJogadores->criaJogadoresBlackjack(quantidadeJogadores);
	system("CLS");
}

void Cassino::jogarBlackjack()
{
	criaJogadoresBlackjack();
	baralho.iniciaNovoBaralho();

	cout << "Sejam bem vindos ao BlackJack, sua sorte sera testada!" << endl;

	JogadorBot.receberCartas(&baralho, 2);

	cout << "Foram distribuidas 1 carta para cada jogador" << endl;
	cout << "A casa possui um " << JogadorBot.getPrimeiraCarta()->getNomeCarta() << " virado na mesa." << endl;

	rodadaJogadoresJogaremBlackjack();

	system("CLS");
	cout << "...PROCESSANDO..." << endl;
	Sleep(3000);
	system("CLS");
	cout << "********** JOGO TERMINADO! **********" << endl;
	cout << "A casa virou as cartas " << endl;
	JogadorBot.escreveCartasJogador();
	cout << "Possuindo no total " << JogadorBot.getPontosAcumulados() << " pontos. " << endl << endl;
	verificaGanhadoresEPerdedoresBlackjack();
	listaJogadores->limpaListaJogadores();
}

void Cassino::rodadaJogadoresJogaremBlackjack()
{
	int option = 0;
	for (int i = 0; i < this->quantidadeJogadores; i++)
	{
		listaJogadores->at(i)->receberCartas(&baralho, 1);
		cout << "Jogador " << listaJogadores->at(i)->getNome() << " recebeu a carta ";
		listaJogadores->at(i)->escreveCartasJogador();
		do
		{
			cout << "O que deseja fazer?" << endl << "1 - Receber mais uma carta" << endl << "2 - Parar " << endl << "3 - Ver minhas cartas " << endl;
			cin >> option;
			switch (option)
			{
			case 1:
			{
				system("CLS");
				listaJogadores->at(i)->receberCartas(&baralho, 1);
				cout << "Voce virou a carta: " << endl;
				cout << listaJogadores->at(i)->getPrimeiraCarta()->getNomeCarta() << endl;
				Sleep(2000);
				if (listaJogadores->at(i)->getPontosAcumulados() > 21)
				{
					system("CLS");
					cout << "Seus pontos ultrapassaram 21";
					Sleep(3000);
					system("CLS");
					option = 2;
					break;
				}
				else if (listaJogadores->at(i)->getPontosAcumulados() == 21)
				{
					cout << "Seus pontos são exatamente 21, PARABENS!";
					Sleep(3000);
					system("CLS");
					option = 2;
					break;
				}
				break;
			}
			case 2:
			{
				cout << "Muito obrigado!" << endl;
				Sleep(3000);
				system("CLS");
				break;
			}
			case 3:
			{
				system("CLS");
				cout << "Essas sao suas cartas " << endl;
				listaJogadores->at(i)->escreveCartasJogador();
				break;
			}
			default:
			{
				cout << "Por favor digite um numero contido no menu." << endl;
			}
			}
		} while (option != 2);
	}
}

void Cassino::verificaGanhadoresEPerdedoresBlackjack()
{
	for (int i = 0; i < this->quantidadeJogadores; i++)
	{
		cout << "Jogador " << listaJogadores->at(i)->getNome() << " possuia as cartas: " << endl;
		listaJogadores->at(i)->escreveCartasJogador();
		cout << "Somando ao total " << listaJogadores->at(i)->getPontosAcumulados() << " pontos" << endl;
		if (listaJogadores->at(i)->getPontosAcumulados() > 21 || JogadorBot.getPontosAcumulados() >= listaJogadores->at(i)->getPontosAcumulados() &&
			JogadorBot.getPontosAcumulados() <= 21)
			cout << "Perdendo o jogo e sua aposta!" << endl;
		else
			cout << "Ganhando o jogo e dobrando sua aposta!" << endl;
		cout << endl;
	}
}

void Cassino::jogarTruco()
{
	baralho.iniciaNovoBaralho();
	baralho.adequaBaralhoTruco();
	criaJogadoresTruco();
	truco.iniciarTruco();
	listaJogadores->limpaListaJogadores();
	/*
	baralho.adequaBaralhoTruco();
	JogadorBot.receberCartas(baralho, 3);

	system("CLS");

	if (quantidadeJogadores > 1)
		cout << "Sejam bem vindos ao Truco!" << endl;
	else
		cout << "Seja bem vindo ao Truco!" << endl;


		while (cartasNaMesa.size() != 9)
		{

		}
		if (truco == 0)
			truco = 1;
		if (pontuacaoRodadaAzul > pontuacaoRodadaVerm)
			pontuacaoTotalAzul += truco;
		else
			pontuacaoTotalVerm += truco;*/
}

void Cassino::criaJogadoresTruco()
{
	listaJogadores->criaJogadoresTruco();
}



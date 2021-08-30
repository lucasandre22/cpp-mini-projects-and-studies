#include <iostream>
#include <map>
using namespace std;

static double MIN(3.1f);

class Inseto {
protected:
	int energia;
public:
	Inseto() { energia = 10; }
	virtual ~Inseto() {}
	virtual void executar() = 0;
	virtual void locomover() const = 0; //informa voa ou nao voa e energia
	const int getEnergia() const { return energia; }
	void setEnergia(int e) { energia = e; }
	void mostraEnergia() const { cout << this->energia << endl; }
};

class Abelha : public Inseto {
private:
	bool ferrao;
public:
	Abelha() : Inseto() { ferrao = true; }
	~Abelha() {}
	void executar() { locomover(); }
	void locomover() const { cout << "abelha voa " << "energia : "; mostraEnergia(); }
	const bool getFerrao() const { return ferrao; }
	void setFerrao(bool f) { ferrao = f; }
};

class Formiga : public Inseto {
protected:
	Abelha* abelha;
public:
	Formiga() : Inseto() { abelha = nullptr; }
	~Formiga() {}
	virtual void executar() {
		atacar(); 
		locomover();
	}
		void atacar() {
			if (abelha != nullptr && abelha->getFerrao() == false)
			{
				int energia = 0;

				energia = abelha->getEnergia();

				energia--;

				abelha->setEnergia(energia);

				cout << "ataquei!" << endl;
			}
		}
		void locomover() const { cout << "formiga nao voa " << "energia : "; mostraEnergia(); }
		const Abelha* getAbelha() const { return abelha; }
		void setAbelha(Abelha * a) { abelha = a; }
	};

	class ForAmiga : public Formiga {
	private:
		double amigavel;
	public:
		ForAmiga() : Formiga() { amigavel = 0; }
		~ForAmiga() {}
		void ajudar() {
			if (abelha != nullptr && amigavel > MIN) {
				int energia = 0;

				energia = abelha->getEnergia();

				energia++;

				abelha->setEnergia(energia);

				cout << "Ajudei!" << endl;
			}
		}
		void executar() { ajudar(); locomover(); }
		bool operator>(ForAmiga& f) { return amigavel > f.getAmigavel(); } 				// is this correct?? sim!
		void setAmigavel(double a) { amigavel = a; }
		const double getAmigavel() const { return amigavel; }
	};

	class Colonia {
	private:
		map<int, Inseto*> mapa_insetos;
		static int quantidade_insetos;
	public:
		Colonia() {}
		~Colonia() {}
		void incluir(Inseto* i) { mapa_insetos[quantidade_insetos++] = i; }
		void percorrer() {
			for (int i = 0; i < quantidade_insetos; i++) {
				mapa_insetos[i]->executar();
			}
		}
	};
	int Colonia::quantidade_insetos(0);									//certo?? sim!

	class Habitat {
	private:
		Abelha abelha1;
		Abelha abelha2;
		Formiga formiga1;
		Formiga formiga2;
		ForAmiga foramiga1;
		ForAmiga foramiga2;
		Colonia colonia;
	public:
		Habitat() : abelha1(), abelha2(), formiga1(), formiga2(), foramiga1(), foramiga2() {
			abelha1.setFerrao(true);
			abelha2.setFerrao(false);

			formiga1.setAbelha(&abelha2);
			formiga2.setAbelha(&abelha1);

			foramiga1.setAbelha(&abelha2);
			foramiga2.setAbelha(&abelha1);

			foramiga1.setAmigavel(1.3);
			foramiga2.setAmigavel(7.3);

			colonia.incluir(static_cast<Inseto*>(&abelha1));
			colonia.incluir(static_cast<Inseto*>(&abelha2));
			colonia.incluir(static_cast<Inseto*>(&formiga1));
			colonia.incluir(static_cast<Inseto*>(&formiga2));
			colonia.incluir(static_cast<Inseto*>(&foramiga1));
			colonia.incluir(static_cast<Inseto*>(&foramiga2));
		}

		void executar() {
			for (int i = 0; i < 20; i++)
				colonia.percorrer();
			cout << "ForAmiga mais amigavel tem " << verificaMaisAmigavel().getAmigavel() <<
				" valor de amigavel" << endl;
		}

		ForAmiga verificaMaisAmigavel() {
			return foramiga1 > foramiga2 ? foramiga1 : foramiga2;
		}
	};

	int main()
	{
		Habitat habitat;
		habitat.executar();
		return 0;
	}

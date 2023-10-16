#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

namespace nmsp {
	class Przedmiot
	{
	private:
		string nazwa;
		int atak;
		int obrona;
	public:
		
		Przedmiot()
		{
			;
		}

		Przedmiot(string name)
		{
			nazwa = name;
			srand(time(NULL));
			atak = (std::rand() % 101) + 100;
			obrona = (std::rand() % 101);
		}

		string getName()
		{
			return nazwa;
		}

		int getAtak()
		{
			return atak;
		}

		int getObrona()
		{
			return obrona;
		}
	};

	class Bohater
	{
	private:
		string pseudo;
		string klasa;
		int hp;
		Przedmiot eq[4];
	public:
		Bohater()
		{
			pseudo = "gruby";
			klasa = "lekarz";
			hp = 1200;
			Przedmiot p0("0");
			Przedmiot p1("1");
			Przedmiot p2("2");
			Przedmiot p3("3");
			eq[0] = p0;
			eq[1] = p1;
			eq[2] = p2;
			eq[3] = p3;
			cout<<"stworzono bohatera"<<endl;
		}

		Bohater(string ps, string kl, int hp)
		{
			pseudo = ps;
			klasa = kl;
			this->hp = hp;
			Przedmiot p0("0");
			Przedmiot p1("1");
			Przedmiot p2("2");
			Przedmiot p3("3");
			eq[0] = p0;
			eq[1] = p1;
			eq[2] = p2;
			eq[3] = p3;
			cout << "Stworzono bohatera" << endl;
		}

		void PiszBoh()
		{
			cout<<"pseudonim: " << pseudo << endl 
				<<"klasa: " << klasa << endl 
				<<"hp: " << hp << endl;
			for(int i = 0; i < 0; i++)
				cout<<"przedmiot nr "<<i<<": " << eq[i].getName() << endl;
		}

		void hit(int pts)
		{
			hp = hp - pts;
		}

		int getHp()
		{
			return hp;
		}

		int getAt(int i)
		{
			return eq[i].getAtak();
		}

		int getOb(int i)
		{
			return eq[i].getObrona();
		}

		string getName()
		{
			return pseudo;
		}
	};
}

void Pojedynek(nmsp::Bohater b1, nmsp::Bohater b2)
{
	int s1atak = 0, s2atak = 0, s1obrona = 0, s2obrona = 0;
	for (int i = 0; i < 4; i++)
	{
		s1atak += b1.getAt(i);
		s2atak += b2.getAt(i);
		s1obrona += b1.getOb(i);
		s2obrona += b2.getOb(i);
	}
	int obr1 = s1atak - s2obrona, obr2 = s2atak - s1obrona;
	b1.hit(obr2);
	b2.hit(obr1);
	if(b1.getHp() > b2.getHp())
		cout<<"pojedynek wygrywa: " << endl << b1.getName() << endl <<"pozostało mu "<<b1.getHp() << " punktów życia" << endl;
	else if(b1.getHp() < b2.getHp())
		cout << "pojedynek wygrywa: " << endl << b2.getName() << endl << "pozostało mu " << b2.getHp() << " punktów życia" << endl;
	else
		cout<< "remis" << endl;
	return;
}

int main()
{
	nmsp::Bohater boh1;
	nmsp::Bohater boh2("lysy", "wojownik", 1000);
	cout << endl;
	boh1.PiszBoh();
	boh2.PiszBoh();
	cout << endl;
	Pojedynek(boh1, boh2);
	cout << endl;
}


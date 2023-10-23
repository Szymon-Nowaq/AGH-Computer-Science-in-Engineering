#include <iostream>
using namespace std; 

namespace nmscp
{
	class Pasażer
	{
	private:
		string imie;
		string nazwisko;
		int rokUr;
		static int counter;
	public:
		Pasażer()
		{
			imie = "";
			nazwisko = "";
			rokUr = 0;
			counter++;
		}

		Pasażer(string im, string nz, int du)
		{
			imie = im;
			nazwisko = nz;
			rokUr = du;
			counter++;
		}

		Pasażer(const Pasażer &p1)
		{
			imie = p1.imie;
			nazwisko = p1.nazwisko;
			rokUr = p1.rokUr;
			counter++;
		}

		void Pisz()
		{
			cout<<"imie: "<< imie << endl 
				<< "nazwisko: " << nazwisko << endl
				<< "rok urodzenia: " << rokUr << endl;
		}

		static int getCounter()
		{
			return counter;
		}

		static void decLicznik()
		{
			counter--;
		}
	};

	int Pasażer::counter = 0;


	class Autokar
	{
	private:
		string cel;
		int vmax;
		const int miejsca = 20;
		Pasażer* tab[20];
		int dodani = 0;
	public:
		Autokar()
		{
			cel = "Zabierzów";
			vmax = 237;
		}

		Autokar(const Autokar& a)
		{
			cel = a.cel;
			vmax = a.vmax;
			for (int i = 0; i < 20; i++)
			{ 
				tab[i] = a.tab[i];
			}
		}

		void dodajPasazera(Pasażer p)
		{
			if(dodani < 20)
			{
				tab[dodani] = &p;
				dodani++;
			}
			else
			{
				cout<<"limit miejsc";
			}
			
		}

		void usunPasazera(int i)
		{
			tab[i] = nullptr;
			Pasażer::decLicznik();
		}

		void Pisz()
		{
			cout << "cel: "<< cel <<endl
				<< "predkosc makszymalna: " << vmax << endl;
			for (int i = 0; i < dodani; i++)
			{
				cout<<"pasazer nr "<<i <<": " << endl; 
				tab[i]->Pisz();	
			}
		}

	};
}



int main()
{
	nmscp::Pasażer p1;
	nmscp::Pasażer *p2 = new nmscp::Pasażer("Grzegorz", "Floryda", 1990);
	nmscp::Pasażer p3(*p2);
	p1.Pisz();
	cout<<endl;
	(* p2).Pisz();
	cout << endl;
	p3.Pisz();
	cout << endl;
	nmscp::Pasażer *Pasazerowie = new nmscp::Pasażer[100];
	cout<< nmscp::Pasażer::getCounter()<<endl;
	nmscp::Autokar *mpk248 = new nmscp::Autokar;
	(*mpk248).dodajPasazera(p1);
	(*mpk248).dodajPasazera((*p2));
	(*mpk248).dodajPasazera(p3);
	for (int i = 0; i < 18; i++)
		(*mpk248).dodajPasazera(Pasazerowie[i]);
	(*mpk248).Pisz();
	nmscp::Autokar mpk238(( * mpk248));
	mpk238.usunPasazera(1);
	mpk238.usunPasazera(2);
	mpk238.usunPasazera(3);
	cout << endl;
	mpk238.Pisz();
	delete p2;
	delete mpk248;
	delete [] Pasazerowie;
	cout << endl;
	cout << nmscp::Pasażer::getCounter() << endl;
}

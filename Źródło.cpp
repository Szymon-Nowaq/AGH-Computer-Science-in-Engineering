#include <iostream>
using namespace std;

class Student {
	public:
	string imie, nazwisko, kierunek; 
	int rokStudiow, semestr;
};

void main()
{
	Student tabStd[3];
	tabStd[0].imie = "Szymon";
	tabStd[0].nazwisko = "Nowak";
	tabStd[0].kierunek = "ITE";
	tabStd[0].rokStudiow = 1;
	tabStd[0].semestr = 2;
	cout<< tabStd[0].imie << endl
		<< tabStd[0].nazwisko << endl
		<< tabStd[0].kierunek << endl
		<< tabStd[0].rokStudiow << endl
		<< tabStd[0].semestr << endl;
}
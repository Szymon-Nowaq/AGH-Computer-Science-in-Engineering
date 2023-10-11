#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

double convPa(double );
bool LiczbyPitagorejskie(double, double, double);
void zapisz_wypiszCA(double, double, double[][2]);
void zapisz_wypiszCG(double, double, double[][2]);

int main()
{
    int u = 1, a;
    while (u)
    {
        srand(time(NULL));
        cout << "wybierz nr zadania (od 1 do 6), wpisz 0 aby zakonczyc program: " << endl;
        cin >> a;
        switch (a)
        {
            case 0:
            {
                u = 0;
                break;
            }
            case 1:
            {
                cout << "totolotek stratuje:" << endl;
                for (int i = 0; i < 6; i++)
                {
                    Sleep(1000);
                    cout << ((rand() % 49) + 1) << endl;
                }
                break;
            }
            case 2:
            {
                double press;
                cout << "podaj cisnienie w Pascalach: " << endl;
                cin >> press;
                double convValue = convPa(press);
                cout << "przekonwertowana wartosc: " << convValue << endl;            
                break;
            }
            case 3:
            {
                double a = 0, b = 0, c = 0;
                do
                {
                    cout << "podaj 3 liczby, od najmniejszej do najwiekszej: ";
                    cin >> a >> b >> c;
                } while (!((0 < a) && (a <= b) && (b <= c)));
                if (LiczbyPitagorejskie(a, b, c))
                    cout << "Podane liczby sa Pitagorejskie" << endl;
                else
                    cout << "Podane liczby nie sa Pitagorejskie" << endl;
                break;
            }
            case 4:
            {
                double a1, r;
                double tab[100][2];
                cout << "podaj 1 wyraz i roznice ciagu arytmetycznego: " << endl;
                cin >> a1 >> r;
                zapisz_wypiszCA(a1, r, tab);
                break;
            }
            case 5:
            {
                double a1, q;
                double tab[100][2];
                cout << "podaj 1 wyraz i iloczyn ciagu geometrycznego: " << endl;
                cin >> a1 >> q;
                zapisz_wypiszCG(a1, q, tab);
                break;
            }
            case 6:
            {
                int fib;
                long unsigned int before1 = 1, before2 = 0, pom1;
                cout << "ile wyrazow fibbonacciego wypisac: ";
                cin >> fib;
                if (fib != 0)
                {
                    cout << "1 wyraz ciagu fibonacciego: 0" << endl;
                    if (fib != 1)
                        cout << "2 wyraz ciagu fibonacciego: 1" << endl;
                }
                for (int i = 3; i <= fib; i++)
                {
                    cout << i << " wyraz ciagu fibonacciego: "<< before1 + before2 <<endl;
                    pom1 = before2;
                    before2 = before1;
                    before1 = before1 + pom1;
                }
                break;
            }
        }
    }
}


    double convPa(double p)
    {
        int sw = 0, val;
        while (sw <= 0 || sw >= 4)
        {
            cout << "na jaka jednostke chcesz przekonwertowac Pascale? Wybierz odpowiednia liczbe \n 1 - bar (atmosfery) \n 2 - tor \n 3 - psi \n";
            cin >> sw;
        }
        switch (sw)
        {
        case 1:
            return p / (100000);
            break;
        case 2:
            return p * 0.0075;
            break;
        case 3:
            return (p * 145.038) / 1000000;
            break;
        }
    }

    bool LiczbyPitagorejskie(double a, double b, double c)
    {
        if ((a * a) + (b * b) == (c * c))
            return true;
        return false;
    }

    void zapisz_wypiszCA(double a1, double r, double tab[][2])
    {
        for (int i = 0; i < 100; i++)
        {
            tab[i][0] = i + 1;
            tab[i][1] = a1 + (r * i);
            cout << tab[i][0] << " wyraz ciagu: " << tab[i][1] << endl;
        }
    }

    void zapisz_wypiszCG(double a1, double q, double tab[][2])
    {
        tab[0][0] = 1;
        tab[0][1] = a1;
        for (int i = 1; i < 100; i++)
        {
            tab[i][0] = i + 1;
            tab[i][1] = tab[i-1][1] * q;
            cout << tab[i][0] << " wyraz ciagu: " << tab[i][1] << endl;
        }
    }
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <algorithm>

using namespace std;

double robot(double, double);
void zapisz_wypiszTab(double, double, double[][2]);
bool czyZgadles(int, int&);
double convPa(double);
bool LiczbyPitagorejskie(double, double, double);
int farma(int, int, int);
int kpn(int, int);
void przestepnosc();
void sumujLiczby();
void maxminroz();
void sredniaLiczb();

int main()
{
    int u = 1, a;
    while (u)
    {
        srand(time(NULL));
        cout << "wybierz nr zadania (od 1 do 9), wpisz 0 aby zakonczyc program: " << endl;
        cin >> a;
        switch (a)
        {
        case 0:
            u = 0;
            break;
        case 1:
        {
            int kr, sw, kur;
            cout << "podaj kolejno liczbe krow swin i kur";
            cin >> kr >> sw >> kur;
            cout << "po farmie biega " << farma(kr, sw, kur) << " nog" << endl;
            break;
        }
        case 2:
        {
            int d, e = 1;
            while (e)
            {
                cout << "wybierz nr zadania (od 1 do 4), wpisz 5 aby zakonczyc sekcje: " << endl;
                cin >> d;
                switch (d)
                {

                case 1:
                    przestepnosc();
                    break;
                case 2:
                    sumujLiczby();
                    break;
                case 3:
                    maxminroz();
                    break;
                case 4:
                    sredniaLiczb();
                    break;
                case 5:
                    e = 0;
                    break;
                default:
                    break;
                }
            }
            break;
        }
        case 3:
        {
            cout << "podaj 4 liczby definiujace odleglosci, na ktore przemiesci sie robot: " << endl;
            double movey1, movex1, movey2, movex2;
            cin >> movey1 >> movex1 >> movey2 >> movex2;
            cout << "wspolrzedna x robota: " << robot(movex1, movex2) << endl
                << "wspolrzedna y robota " << robot(movey1, movey2) << endl;
            break;
        }
        case 4:
        {
            int n, m = 0, cmp, bilgr = 0, bilcpu = 0;
            while (true)
            {
                int pktgr = 0, pktcpu = 0;
                while (!((pktgr == 3) || (pktcpu == 3)))
                {
                    srand(time(NULL));
                    cout << "Wpisz liczbe, ktora odpowiada pozadanemu sprzetowi:\n1 - Kamien\n2 - Papier\n3 - Nozyce\n";
                    cin >> n;
                    cmp = ((rand() % 3) + 1);
                    if (kpn(n, cmp) == 2)
                    {
                        cout << "Remis!" << endl;
                        cout << "Aktualny wynik: " << endl << "Ty - " << pktgr << " : " << pktcpu << " - Komputer" << endl;
                        continue;
                    }
                    if (kpn(n, cmp) == 1)
                    {
                        cout << "Wygrywasz!" << endl;
                        cout << "Aktualny wynik: " << endl << "Ty - " << ++pktgr << " : " << pktcpu << " - Komputer" << endl;
                        continue;
                    }
                    else
                    {
                        cout << "Przegrywasz!" << endl;
                        cout << "Aktualny wynik: " << endl << "Ty - " << pktgr << " : " << ++pktcpu << " - Komputer" << endl;
                        continue;
                    }
                }
                if (pktgr == 3)
                    cout << "Wygrales rozgrywke!\nAktualny bilans: Ty - " << ++bilgr << " : " << bilcpu << " - Komputer" << endl;
                else
                    cout << "Przegrales rozgrywke!\nAktualny bilans: Ty - " << bilgr << " : " << ++bilcpu << " - Komputer" << endl;
                cout << "Czy chcesz rozpoczac kolejne starcie z komputerem?\n 1 - Tak \n 0 - Nie\n";
                cin >> m;
                if (!m)
                    break;
            }
            break;
        }
        case 5:
        {
            double a1, r;
            double tab[100][2];
            cout << "podaj 1 wyraz i roznice ciagu arytmetycznego: " << endl;
            cin >> a1 >> r;
            zapisz_wypiszTab(a1, r, tab);
            break;
        }
        case 6:
        {
            int num = ((rand() % 100) + 1), wyb = 0, ileProb = 0;
            while (true)
            {
                if (czyZgadles(num, ileProb))
                    break;
            }
            cout << "Ilosc prob: " << ileProb << endl;
            break;
        }
        case 7:
        {
            cout << "totolotek stratuje:" << endl;
            for (int i = 0; i < 6; i++)
            {
                Sleep(1000);
                cout << ((rand() % 49) + 1) << endl;
            }
            break;
        }
        case 8:
        {
            double press;
            cout << "podaj cisnienie w Pascalach: " << endl;
            cin >> press;
            double convValue = convPa(press);
            cout << "przekonwertowana wartosc: " << convValue << endl;
            break;
        }
        case 9:
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
        default:
            break;
        }
    }
}

double robot(double a, double b)
{
    return a - b;
}


int farma(int krowy, int swinie, int kury)
{
    return (krowy * 4) + (swinie * 4) + (kury * 2);
}

int kpn(int gr, int cpu)
{
    if (gr == cpu)
        return 2;
    if (((gr == 1 && cpu == 3)) || ((gr == 2) && (cpu == 1)) || ((gr == 3) && (cpu == 2)))
        return 1;
    else
        return 0;
}

void przestepnosc()
{
    int rok;
    cout << "podaj rok: ";
    cin >> rok;
    if (((rok % 4 == 0) && !(rok % 100 == 0)) || rok % 400 == 0)
        cout << "wybrany rok jest przestepny" << endl;
    else
        cout << "wybrany rok nie jest przestepny" << endl;
}

void sumujLiczby()
{
    int a, b;
    cout << "podaj dwie liczby calkowite: " << endl;
    cin >> a >> b;
    cout << "wszystkie liczby z przedzialu podanych liczb: " << endl;
    if (a > b)
    {
        int pom = b;
        b = a;
        a = pom;
    }
    int suma = 0;
    for (int i = ++b; i < b; i++)
    {
        cout << i << "   ";
        if (i % 2 == 0)
            suma += i;
    }
    cout << endl << "suma liczb parzystych z przedzialu wynosi: " << suma << endl;
}

void maxminroz()
{
    double x1, x2, x3, x4, x5;
    cout << "podaj 5 liczb" << endl;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;
    double tab[5] = { x1, x2, x3, x4, x5 };
    sort(tab, tab + 5);
    cout << "najmniejsza liczba: " << tab[0] << endl << "najmniejsza liczba: " << tab[4] << endl
        << "ich roznica: " << tab[4] - tab[0] << endl;
}

void sredniaLiczb()
{
    cout << "podaj ilosc liczb do wczytania: " << endl;
    int y;
    double suma2 = 0;
    cin >> y;
    for (int i = 0; i < y; i++)
    {
        double a;
        cout << "podaj " << i + 1 << " liczbe: " << endl;
        cin >> a;
        suma2 += a;
    }
    double avg = suma2 / (double)y;
    cout << "srednia liczb wynosi: " << avg << endl;
    for (int i = 0; i < avg; i++)
        cout << "0   ";
}
void zapisz_wypiszTab(double a1, double r, double tab[][2])
{
    for (int i = 0; i < 100; i++)
    {
        tab[i][0] = i + 1;
        tab[i][1] = a1 + (r * i);
        cout << tab[i][0] << " wyraz ciagu: " << tab[i][1] << endl;
    }
}

bool czyZgadles(int num, int& ileProb)
{
    int a = 0;
    while (a <= 0 || a >= 101)
    {
        cout << "podaj liczbe calkowita od 1 do 100: " << endl;
        cin >> a;
        ileProb++;
    }
    if (a == num)
    {
        cout << "ZGADLES" << endl;
        return true;
    }
    else if (a < num)
    {
        cout << "ZA MALO" << endl;
        return false;
    }
    else
    {
        cout << "ZA DUZO" << endl;
        return false;
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

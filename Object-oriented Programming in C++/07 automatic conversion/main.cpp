#include <iostream>
#include <numeric>
#include <cstdlib>
using namespace std;

class Ulamek{
    int licznik;
    int mianownik;
public:
    Ulamek(int licznik, int mianownik) : licznik(licznik), mianownik(mianownik) {}
    Ulamek(int a){
        licznik = a;
        mianownik = 1;
    }
    Ulamek(){licznik = 0; mianownik = 0;}

    operator double() const{
        return static_cast<double> (licznik) /mianownik;
    }

    void Skroc(){
        int nwd = gcd(licznik, mianownik);
        licznik /= nwd;
        mianownik /= nwd;
    }
    int getLicznik() const {
        return licznik;
    }

    void setLicznik(int licznik) {
        Ulamek::licznik = licznik;
    }

    int getMianownik() const {
        return mianownik;
    }

    void setMianownik(int mianownik) {
        Ulamek::mianownik = mianownik;
    }
};

ostream& operator<<(ostream& out, const Ulamek& u){
    out << u.getLicznik() <<'/' << u.getMianownik();
    return out;
}
Ulamek dodaj(Ulamek u1, Ulamek u2);
double doKwadratu(double a);
void generateRandom(int n);

int main() {
    Ulamek tab1[3] = {Ulamek(1,2), Ulamek(5,8), Ulamek(7,9)};
    for(int i = 0; i < 3; i++)
        cout<<tab1[i]<<endl;
    cout<<dodaj(tab1[0], tab1[1]) << endl;
    cout<<dodaj(tab1[0], 7) << endl;
    cout<<doKwadratu(tab1[2])<<endl;
    Ulamek u1(88, 22);
    u1.Skroc();
    cout<<u1<<endl;
    generateRandom(10);
    return 0;
}

Ulamek dodaj(Ulamek u1, Ulamek u2)
{
    return Ulamek(u1.getLicznik() * u2.getMianownik() + u2.getLicznik() * u1.getMianownik(), u1.getMianownik() * u2.getMianownik());
}

double doKwadratu(double a){
    return a*a;
}

void generateRandom(int n){
    srand(time(NULL));
    Ulamek tab[n];
    Ulamek maxUl = INT_MIN;
    for(int i = 0; i < n; i++){
        int li = (rand() % 2001) - 1000;
        int mian = (rand() % 2001) - 1000;
        if(mian == 0){
            while(mian == 0)
                mian = (rand() % 2001) - 1000;
        }
        tab[i] = Ulamek(li, mian);
        cout<<tab[i] << " = " << (double)tab[i]<< endl;
        if((double)tab[i] > (double)maxUl)
            maxUl = tab[i];
    }
    cout<<"max: "<<maxUl<<" = " << (double)maxUl <<endl;
}
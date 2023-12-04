#include <iostream>
#include <initializer_list>

using namespace std;

class Wielomian{
    int deg;
    double* tab;

    public:
    static bool outType;

    Wielomian(int d, initializer_list<double> t){
        deg = d;
        tab = new double[deg];
        if(t.size() == d){
            int i = 0;
            for(const double* it = t.begin(); it != t.end(); ++it) {
                tab[i++] = *it;
            }
        }
        else
            cout<<"error, nieprawidlowe dane";
    }

    Wielomian(int d, double t[]){
        deg = d;
        tab = new double[deg];
        int i;
        for(i = 0; i < deg; i++)
            tab[i] = t[i];
    }

    Wielomian(){
        deg = 0;
        tab = nullptr;
    }

    friend ostream& operator<<(ostream& out, const Wielomian& w){
        if(outType){
            if(w.tab[0] < 0)
                out<<'-';
            for (int i = w.deg; i > 0; i--) {
                if (!w.tab[w.deg - i])
                    continue;
                if (i != 2 && i != w.deg && w.tab[w.deg - i] > 0)
                    out << " + ";
                else if(i != 2 && i != w.deg)
                    out << " - ";
                if(i == 1){
                    out<<abs(w.tab[w.deg - i]);
                    continue;
                }
                if (w.tab[w.deg - i] == 1)
                    out << "x";
                else
                    out << abs(w.tab[w.deg - i]) << "x^" << i - 1;
            }
            return out;
        }else{
            for (int i = w.deg; i > 0; i--) {
                if (!w.tab[w.deg - i])
                    continue;
                if (i != 2 && i != w.deg)
                    out << " + ";
                if (w.tab[w.deg - i] == 1)
                    out << "(x^" << i - 1 << ')';
                else
                    out << "(" << w.tab[w.deg - i] << "x^" << i - 1 << ')';
            }
            return out;
        }
    }

    Wielomian operator+(const Wielomian& w){
        int newDeg;
        double* newTab;
        if(deg > w.deg) {
            newDeg = deg;
            newTab = new double[newDeg];
            for(int i = w.deg - 1; i > 0; i--)
                newTab[i] = tab[i] + w.tab[i];
            for(int i = w.deg; i < deg; i++)
                newTab[i] = tab[i];
        }else{
            newDeg = w.deg;
            newTab = new double[newDeg];
            for(int i = 0; i < deg; i++)
                newTab[i] = tab[i] + w.tab[i];
            for(int i = deg; i < w.deg; i++)
                newTab[i] = w.tab[i];
        }
        return Wielomian(newDeg, newTab);
    }

    Wielomian operator*(int a){
        double* newTab = new double[deg];
        for(int i = 0; i < deg; i++)
            newTab[i] = tab[i] * a;
        return Wielomian(deg, newTab);
    }

    ~Wielomian() {
        delete[] tab;
    }

};

bool Wielomian::outType = 1;

int main() {
    Wielomian w1(2, {1, -5});
    Wielomian w2(4, {-3.4, -7, 0, 1});
    Wielomian w3(6, {7.8, 0, -7, 0, 0, 0});
    cout<<w1 * 2<<endl;
    return 0;
}

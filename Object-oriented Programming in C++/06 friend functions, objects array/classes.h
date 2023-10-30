using namespace std;
class Okrag;

#pragma once

class Punkt
{
    friend void wypisz(Punkt p);
    friend void wypisz(Okrag o);
    friend int czyPrzecina(Okrag tab1[], Okrag tab2[]);
    double x;
    double y;
    public:
    Punkt(double x1, double x2)
    {
        x = x1;
        y = x2;
    }
    
    double getX()
    {
        return x;
    }
    
    double getY()
    {
        return y;
    }
};

class Prostokat
{
    friend void wypisz(Prostokat pr);
    friend class Punkt;
    Punkt lwd;
    double szer;
    double wys;
    
    public:
    Prostokat(Punkt a, double b, double c) : lwd(a)
    {
        szer = b;
        wys = c;
    }
    
    bool czyWspolne(Punkt p)
    {
        if(p.getX() >= lwd.getX() && p.getY() <= lwd.getX() + szer && p.getY() >= lwd.getY() && p.getY() <= lwd.getY() + wys)
        {
            //cout<<"zawiera sie"<<endl;
            return true;
        }
        else
        {
            //cout<<"nie zawiera sie"<<endl;
            return false;
        }
    }
};

class Okrag
{
    friend class Punkt;
    friend void wypisz(Okrag o);
    friend int czyPrzecina(Okrag tab1[], Okrag tab2[]);
    Punkt srodek;
    int r;
    
    friend class Punkt;
    public:
    Okrag(Punkt sr, int r1) : srodek(sr)
    {
        r = r1;
    }
    
    Okrag() : srodek(Punkt(0,0))
    {
        r = 0;
    }
};

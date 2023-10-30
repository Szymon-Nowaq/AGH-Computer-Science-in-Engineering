#include "classes.h"
#include <iostream>
#include <cmath>
#pragma once

using namespace std;

void wypisz(Okrag o)
{
    cout << "Okrąg: "<< endl;
    cout<<"srodek: "<< "x: "<< o.srodek.x << "  y: "<< o.srodek.y <<endl<<"promien: "<<o.r<<endl;
}

void wypisz(Punkt p)
{
    cout << "Punkt: "<< endl;
    cout<<"x: "<< p.x << "  y: "<< p.y << endl;
}

void wypisz(Prostokat pr)
{
    cout << "Prostokat: "<< endl;
    cout << "lewy dolny: ";
    wypisz(pr.lwd);
    cout << "szerokosc: " << pr.szer << "   wysokokosc: " << pr.wys << endl;
}

int czyPrzecina(Okrag tab1[], Okrag tab2[])
{
    int count = 0;
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            double distance = sqrt(pow(tab1[i].srodek.x - tab1[j].srodek.x, 2) + pow(tab2[i].srodek.y - tab2[j].srodek.y, 2));
            double RminR = fabs(tab1[i].r - tab2[j].r); 
            double RplusR = tab1[i].r + tab2[j].r;
            wypisz(tab1[i]);
            wypisz(tab2[j]);
            cout << RminR << "  " << distance << "   " << RplusR << endl;
            if(RminR < distance && distance < RplusR)
            {
                count++;
            }
        }
    }
    return count;
}
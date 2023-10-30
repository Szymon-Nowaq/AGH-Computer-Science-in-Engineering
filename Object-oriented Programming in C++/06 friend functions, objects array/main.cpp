#include <iostream>
#include <cstdlib>
#include <ctime>
#include "classes.h"
#include "functions.cpp"

using namespace std;


int main()
{
    srand(time(NULL));
    Punkt p1(5,2);
    Punkt p2(-9,-9);
    Punkt p3(2,3);
    Punkt tabPkt[3] = {p1, p2, p3};
    Punkt p4(-8,-6);
    Prostokat pro1(p4, 13, 10);
    for(int i = 0; i < 3; i++)
    {
        if(pro1.czyWspolne(tabPkt[i]))
            cout<<"zawiera sie"<<endl;
        else   
            cout<<"nie zawiera sie"<<endl;
    }
    Okrag okrTab[100];
    
    for(int i = 0; i < 100; i++)
    {
        Punkt sr(( rand() % 6 ),  (rand() % 6 ) - 5);
        Okrag ok(sr, ( std::rand() % 9 ) + 1);
        okrTab[i] = ok;
    }
    
    Okrag *tabDynOkr = new Okrag[50];
    
    for(int i = 0; i < 50; i++)
    {
        Punkt sr1(( rand() % 16 ) - 5,  (rand() % 16 ) - 10);
        Okrag ok(sr1, ( std::rand() % 14 ) + 1);
        okrTab[i] = ok;
        //wypisz(okrTab[i]);  
    }
    
    //wypisz(p1);
    //wypisz(okrTab[0]);
    //wypisz(pro1);
    cout << "przecina się: " << czyPrzecina(okrTab, tabDynOkr) << endl;
    delete [] tabDynOkr;
    return 0;
}

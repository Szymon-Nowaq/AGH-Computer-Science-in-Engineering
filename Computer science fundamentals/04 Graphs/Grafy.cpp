
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file;
    file.open("graf.txt", ios::in);
    int edges = 0, tops = 0;
    string wierz;
    file >> wierz;
    tops = (int)wierz[0] - 48;
    string* tab = new string[tops];
    for (int i = 0; i < tops; i++)
        file >> tab[i];
    int** mac_sas = new int * [tops];
    for (int i = 0; i < tops; i++)
        mac_sas[i] = new int[tops];
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
            mac_sas[i][j] = (int)tab[i][j] - 48;
    }
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
            cout << mac_sas[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < tops; i++)
        delete mac_sas[i];
    delete tab;
    // METODA STWORZENIA GRAFU Z KLAWIATURY

    /*
    int edges, tops;
    cout << "podaj liczbe wierzcholkow i krawedzi: " << endl;
    cin >> tops >> edges;
    int** mac_sas = new int* [tops];
    for (int i = 0; i < tops; i++)
        mac_sas[i] = new int[tops];
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
            mac_sas[i][j] = 0;
    }
    for (int i = 0; i < edges; i++)
     {
         int m, n;
         bool b = true;
         do
         {
             cout << "podaj pare wierzcholkow miedzy ktorymi utoworzyc krawedz: ";
             cin >> m >> n;
             if ((m < 0 && m >= tops) && (n < 0 && n >= tops))
             {
                 cout << "podany wierzcholek nie istnieje, wprowadz wartosci ponownie" << endl;
                 break;
             }else
                 b = false;
         } while (b);
         mac_sas[m][n] = 1;
     }
    
    for (int i = 0; i < tops; i++)
    {
        for (int j = 0; j < tops; j++)
            cout << mac_sas[i][j] << " ";
        cout << endl;
    }
    for (int i = 0; i < tops; i++)
        delete mac_sas[i];
    */
}

// Wypisanie grafu za pomocą istniejacych polaczeń:
//cout << i << " wierzcholek ma polaczenie z wierzcholkiem: ";
//int przecinek = 0;
//for (int j = 0; j < tops; j++)
//{
//    if (mac_sas[i][j])
//    {
//        if (przecinek++ == 1)
//            cout << ", ";
//        if (przecinek > 2)
//            cout << ", ";
//        cout << j + 1;
//    }
//}
//cout << endl;
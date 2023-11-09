#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    int u;
    cout << "wybierz dzialanie:\n 1 - tabliczka mnozenia\n 2 - haslo\n";
    cin >> u;
    switch (u)
    {
        case 1:
        {
            fstream file;
            file.open("tabliczka.txt", ios::out);
            if (file.good() == false)
            {
                cout << "brak pliku";
                exit(1);
            }
            int dl;
            cout << "jak duza tabliczke mnozenia zapisac do pliku? " << endl;
            cin >> dl;
            int** tab;
            tab = new int* [dl + 1];
            for (int i = 0; i < dl + 1; i++)
                tab[i] = new int[dl + 1];
            for (int i = 0; i < dl + 1; i++)
                tab[i][0] = i;
            for (int i = 1; i < dl + 1; i++)
                tab[0][i] = i;
            for (int i = 1; i < dl + 1; i++)
            {
                for (int j = 1; j < dl + 1; j++)
                {
                    tab[i][j] = i * j;
                }
            }
            for (int i = 1; i < dl + 1; i++)
            {
                for (int j = 1; j < dl + 1; j++)
                    file << tab[i][j] << " ";
                file << endl;
            }
            file.close();
            for (int i = 0; i < dl + 1; i++)
                delete tab[i];
            break;
        }
        case 2:
            fstream file;
            file.open("haslo.txt", ios::in);
            if (file.good() == false)
            {
                cout << "brak pliku";
                exit(1);
            }
            string hasloPlik, hasloUser;
            file >> hasloPlik;
            cout << "podaj haslo: ";
            cin >> hasloUser;
            if (hasloPlik == hasloUser)
                cout << "haslo poprawne\n";
            else
                cout << "haslo niepoprawne\n";
    }
}

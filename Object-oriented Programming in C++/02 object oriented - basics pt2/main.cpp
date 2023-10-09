#include <iostream>
using namespace std;
class Produkt
{
public:
    string name;
    double price;
    int category;
    int id;
    void zastosujRabat(int x)
    {
        if (x < 0 || x > 100)
        {
            cout << "zla wartosc";
            return;
        }
        this->price = this->price - (this->price * x / 100);
        return;
    }
    void ustawProdukt(string n, double p, int c, int i)
    {
        name = n;
        price = p;
        category = c;
        id = i;
        return;
    }
    void Pisz()
    {
        cout << "nazwa: " << name << endl << "cena: " << price << endl << "kategoria: " << category << endl << "id: " << id << endl;
        return;
    }

private:

};

class Sklep
{
public:
    string name;
    string adress;
    Produkt produkty[4];
    int counter = 0;
    void dodajProdukt(Produkt p)
    {

        if (counter > 4)
        {
            cout << "za duzo produktow";
            return;
        }
        produkty[counter] = p;
        counter++;
    }

    Produkt* znajdzProduktyKategorii(int c)
    {
        int catCounter = 0;
        for (int i = 0; i < 4; i++)
        {
            if (produkty[i].category == c)
                catCounter++;
        }
        Produkt* tab = new Produkt[catCounter + 1];
        for (int i = 0; i < 4; i++)
        {
            if (produkty[i].category == c)
                tab[i] = produkty[i];
        }
        Produkt ghost;
        ghost.ustawProdukt("ostatni", 0, 0, 0);
        tab[catCounter] = ghost;
        return tab;
    }
    void ustawSklep(string n, string a)
    {
        name = n;
        adress = a;
        return;
    }
    void Pisz()
    {
        cout << "nazwa: " << name << endl << "adres: " << adress << endl << "Produkty: ";
        for (int i = 0; i < counter; i++)
        {
            produkty[i].Pisz();
        }
        return;
    }

private:

};

int main()
{
    Produkt tabP[4];
    tabP[0].ustawProdukt("cola", 5, 1, 1234);
    tabP[1].ustawProdukt("pepsi", 6, 1, 4321);
    tabP[2].ustawProdukt("chleb", 7, 2, 5678);
    tabP[3].ustawProdukt("jajka", 10, 2, 8765);
    for (int i = 0; i < 4; i++)
    {
        tabP[i].Pisz();
    }
    tabP[0].zastosujRabat(10);
    cout << endl;
    tabP[0].Pisz();
    Sklep biedra;
    biedra.ustawSklep("biedra", "Piastowska 10");
    for (int i = 0; i < 4; i++)
    {
        biedra.dodajProdukt(tabP[i]);
    }
    Produkt* found = biedra.znajdzProduktyKategorii(1);
    for (int i = 0; found[i].name != "ostatni"; i++)
        (found + 1)->Pisz();
}

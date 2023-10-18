#include <iostream>
using namespace std;

bool isImpication(bool, bool);
bool isEquivalent(bool, bool);
bool isalternative(bool, bool);
bool isconjunction(bool, bool);
bool negate(bool);

int main()
{
    int u = 1, a;
    bool p, q, r;
    while (u)
    {
        cout << "wybierz nr zadania (od 1 do 3), wpisz 0 aby zakonczyc program: " << endl;
        cin >> a;
        switch (a)
        {
            case 0:
                u = 0;
                break;
            case 1:
            {
                int iteA = 0, iteB = 0, iteC = 0;
                for (int i = 0; i < 2; i++)
                {
                    for (int j = 0; j < 2; j++)
                    {
                        for (int k = 0; k < 2; k++)
                        {
                            p = i;
                            q = j;
                            r = k;
                            if (isImpication(isImpication(p || q, r), isImpication(p, r) || isImpication(q, r)))
                                iteA++;
                            if (isImpication((p || q) && isImpication(p,q), isImpication(q, p)))
                                iteB++;
                            if (isImpication(!isImpication(p,q) || isImpication(q, p), p && !q))
                                iteC++;
                        }
                    }
                }
                if (iteA == 6)
                    cout << "wyrazenie (p ∨ q ⇒ r) ⇒ (p ⇒ r) ∨ (q ⇒ r) jest tautologia" << endl;
                else
                    cout << "wyrazenie (p ∨ q ⇒ r) ⇒ (p ⇒ r) ∨ (q ⇒ r) nie jest tautologia" << endl;
                if (iteB == 6)
                    cout << "wyrazenie (p ∨ q) ∧ (p ⇒ q) ⇒ q ⇒ p jest tautologia" << endl;
                else
                    cout << "wyrazenie (p ∨ q) ∧ (p ⇒ q) ⇒ q ⇒ p nie jest tautologia" << endl;
                if (iteC == 6)
                    cout << "wyrazenie  ¬(p ⇒ q) ∧ (q ⇒ p) ⇒ p ∧ ¬q jest tautologia" << endl;
                else
                    cout << "wyrazenie ¬(p ⇒ q) ∧ (q ⇒ p) ⇒ p ∧ ¬q nie jest tautologia" << endl;
                break;
            }
            case 2:
                cout << "podaj wartosci logiczne (0 lub 1) dla p i q:" << endl;
                cin >> p >> q;
                cout << "\nnegacja p: " << negate(p) << "\nnegacja q: " << negate(q) <<
                "\nkoniunkcja: " << isconjunction(p,q) << "\nalternatywa: " << isalternative(p,q) <<
                "\nimplikacja: " << isImpication(p, q) << "\nrownowaznosc: " << isEquivalent(p, q) << endl;
                break;
            case 3:
                q = 0;
                p = 1;
                r = 0;
                if (p && q)
                    cout << "wyrazenie p && q jest prawdziwe" << endl;
                else
                    cout << "wyrazenie p && q nie jest prawdziwe" << endl;
                if (p || q)
                    cout << "wyrazenie p || q jest prawdziwe" << endl;
                else
                    cout << "wyrazenie p || q nie jest prawdziwe" << endl;
                if (!p && (p || q))
                    cout << "wyrazenie !p && (p || q) jest prawdziwe" << endl;
                else
                    cout << "wyrazenie !p && (p || q) nie jest prawdziwe" << endl;
                if (isImpication(p && r,q))
                    cout << "wyrazenie (p && r) => q jest prawdziwe" << endl;
                else
                    cout << "wyrazenie (p && r) => q nie jest prawdziwe" << endl;
                if (!isEquivalent(p,q || r))
                    cout << "wyrazenie !(p <=>(q || r)) jest prawdziwe" << endl;
                else
                    cout << "wyrazenie !(p <=>(q || r)) nie jest prawdziwe" << endl;
                if (isEquivalent(isImpication(p,r) || !q, isImpication(p, r && !q)))
                    cout << "wyrazenie [(p => r) || !q] <=> [p => (r && !q)] jest prawdziwe" << endl;
                else
                    cout << "wyrazenie [(p => r) || !q] <=> [p => (r && !q)] nie jest prawdziwe" << endl;
                if (isImpication((!r || q) || !(q && r), !isImpication(q, p)))
                    cout << "wyrazenie [(!r || q) || !(q && r)] => !( q => p) jest prawdziwe" << endl;
                else
                    cout << "wyrazenie [(!r || q) || !(q && r)] => !( q => p) nie jest prawdziwe" << endl;
                break;
        }
    }
}

bool isImpication(bool a, bool b)
{
    if ( (a == b) || (a == 0 && b == 1) )
        return true;
    return false;

}

bool isEquivalent(bool a, bool b)
{
    if (a == b)
        return true;
    return false;
}

bool isalternative(bool a, bool b)
{
    if (a || b)
        return true;
    return false;
}
bool isconjunction(bool a, bool b)
{
    if (a && b)
        return true;
    return false;
}
bool negate(bool a)
{
    return !a;
}
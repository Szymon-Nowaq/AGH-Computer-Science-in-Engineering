#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define length1 10
#define length2 10

int main(void)
{
    srand(time(NULL));
    int randArray[length1], histogram[length1] = {0};
    for (int i = 0; i < length1; i++)
    {
        randArray[i] = rand() % 10;
        histogram[randArray[i]]++;
    }
    for (int i = 0; i < length1; i++)
    {
        if (histogram[i] != 0)
            printf("%d :", i);
        for (int j = 0; j < histogram[i]; j++)
            printf(" *");
        if (histogram[i] != 0)
            printf("\n");
    }

    // KOPIOWANIE
   /* printf("do 1 tablicy wprowadz TYLKO litery: \n");
    int i1 = 0;
    char magicarray1[length1], ck = 0;
    while (((ck = getchar()) != EOF) && ck != '\n') {
        magicarray1[i1] = ck;
        putchar(ck);
        i1++;
    }
    magicarray1[i1] = '\n'*/;
    /*  WARIANT Z BREAK
    while ((ck = getchar()) != EOF) {
        if (ck != '\n')
            break;
        magicarray[i] = ck;
        putchar(ck);
        i++;
    }
    */
    /*
    int dlstr1 = 0;
    for (; dlstr1 < length1; dlstr1++)
    {
        if (magicarray1[dlstr1] == '\n')
            break;
    }
    printf("\ndlugosc napisu nr 1: %d\n", dlstr1);

    // SWITCH

    int nwhite = 0, nother = 0, i2 = 0; // zmienne do zliczania
    int ndigit[length2] = { 0 }; // w tym tablica inicjowana zerami
    int magicarray2[length2];
    char c = 0; // c definiowane jako int bo EOF niekoniecznie jest znakiem
    while (c!='\n') { // wczytywanie kolejnych znakĂłw aĹź do EOF
        scanf_s("%c", &c);
        magicarray2[i2] = c;
        if (0 <= (c-48) && (c-48) <= 9)
            ndigit[c-48]++;
        // printf("%c, %d,  %d\n", c, c-'0', ndigit[c-'0']); - wydruk kontrolny
        // (istniejÄ
            // poprawnoĹci programu (np. assert, static_assert) )
        else if (c == ' ' || c == '\n' || c == '\t')// znaki traktowane jako "white space"
            nwhite++;
        else
            nother++;
        i2++;
    }
    magicarray2[i2] = '\n';
    printf("\ndigits:\n");
    for (int i = 0; i < 10; i++) 
        printf("'%d' = %d\n", i, ndigit[i]);
    printf("white space = %d\nother =  %d\n", nwhite, nother);
    int dlstr2 = 0;
    for (; dlstr2 < length2; dlstr2++)
    {
        if (magicarray2[dlstr2] == '\n')
            break;
    }
    printf("\ndlugosc napisu nr 1: %d\n", dlstr2);

    //porownywanie tablic
   
    bool czy_rowne = false;
    if (dlstr1 == dlstr2)
    {
        czy_rowne = true;
        for (int i = 0; i < dlstr1; i++)
        {
            if (magicarray1[i] != magicarray2[i])
                czy_rowne = false;
        }
    }
    if (!czy_rowne)
        printf("\noba napisy nie sa identyczne\n");
    else
        printf("\noba napisy sa identyczne\n");

    //zamiana kolejnosci 2 tablicy
    
    for(int i = 0; i <= ((dlstr2 - 1) / 2); i++)
    {
        char pom = magicarray2[i];
        magicarray2[i] = magicarray2[dlstr2 - i - 1];
        magicarray2[dlstr2 - i - 1] = pom;
    }
    printf("zamiana kolejnosci wyrazow w tablicy 1: \n");
    for (int i = 0; i < dlstr2; i++)
        putchar(magicarray2[i]);

    //zamiana malych liter na wielkie w 1 tablicy

    for (int i = 0; i < dlstr1; i++)
        magicarray1[i] -= 32;
    printf("\nzamiana malych liter na wielkie w 1 tablicy: \n");
    for (int i = 0; i < dlstr1; i++)
        putchar(magicarray1[i]);
    */
}
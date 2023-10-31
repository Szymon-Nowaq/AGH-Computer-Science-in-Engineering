#include <stdio.h>

#define ROZMIAR_TABLICY 10
#define ROZMIAR_TABLICY2 100

void main(void)
{

    //int tablica_int[ROZMIAR_TABLICY] = { 0 };

    // 1. inicjowanie tablicy w momencie definowania:

    // a. wszystkie wartoci
    
    int tablica_int[ROZMIAR_TABLICY] = { 5 };
    
    // b. poczštkowe wartoci
    
    //int tablica_int[ROZMIAR_TABLICY] = {1 , 2, 3, 4};
    
    // 2. nadanie wartoci w pętli

    // a. zależnych od wartoci zmiennej sterujacej

    for (int i = 0; i < ROZMIAR_TABLICY; i++)
        tablica_int[i] = i;
    
    // b. wczytywanych z klawiatury za pomocš scanf
    
    for (int i = 0; i < ROZMIAR_TABLICY; i++)
    {
        printf("podaj %d element tablicy:\n", i + 1);
        scanf(" %d", &tablica_int[i]);
    }
    
    // 3. zamiana pętli for nadawania wartoci na pętlę while
    /*
    int i = 0;
    while ( i < ROZMIAR_TABLICY)
    {
        printf("podaj %d element tablicy:\n", i + 1);
        scanf("%d", &tablica_int[i]);
        i++;
    }
    */
    // 4. zamiana poniższej pętli for na pętlę do
    /*
    int i = 0;
    do 
    {
        printf("podaj %d element tablicy:\n", i + 1);
        scanf_s("%d", &tablica_int[i]);
        i++;
    } while (i < ROZMIAR_TABLICY);
    */
    // (jak zwykle najlepiej wykomentować starš pętlę i wpisać poniżej nowš pętlę)
    
    for (int i = 0; i < ROZMIAR_TABLICY; i++)
        printf("Iteracja %d: tablica_int[%d] = %d\n", i + 1, i, tablica_int[i]);
    
    // 5. wyszukiwanie wartoci maksymalnej w tablicy (pętla for)
    
    int max = tablica_int[0];
    for (int i = 1; i < ROZMIAR_TABLICY; i++)
    {
        if (max < tablica_int[i])
            max = tablica_int[i];
    }
    printf("element maksymalny: %d\n", max);
    
    // 6. obliczanie sumy elementów tablicy (pętla while)
    
    int suma = 0;
    for (int i = 0; i < ROZMIAR_TABLICY; i++)
        suma += tablica_int[i];
    printf("suma elementow tablicy: %d\n", suma);
    
    //-------------------------------- 3.0 ------------------------------------

    // 7. tablica z wartociami losowymi i wyszukiwanie zadanych wartoci

    // a. nowa definicja tablicy (np. tablicy znaków)
    char tablicaczarow[ROZMIAR_TABLICY2];
    // b. nadawanie wartoci losowych wyrazom tablicy
    //    (np. liczby z zakresu 33-126, czyli odpowiadajšce znakom ASCII)
    //    -> odpowiednie wydruki
    srand(time(NULL));
    for (int i = 0; i < ROZMIAR_TABLICY2; i++)
        tablicaczarow[i] = (rand() % 93) + 33;
    for (int i = 0; i < ROZMIAR_TABLICY2; i++)
        printf("Iteracja %d: tablica_int[%d] = %c\n", i + 1, i, tablicaczarow[i]);
    // c. sprawdzenie losowoci - obliczenie wartoci redniej w tablicy
    //    (w odpowiedniej pętli) - porównanie z teoretycznš redniš
    //    -> odpowiednie wydruki
    int suma1 = 0;
    for (int i = 0; i < ROZMIAR_TABLICY2; i++)
        suma1 += (int) tablicaczarow[i];
    printf("srednia elementow tablicy: %d\n", suma1/ROZMIAR_TABLICY2);

    // srednia dazy do 78

    // d. wyszukiwanie zadanej wartoci
    //    -> odpowiednie wydruki w momencie znalezienia wartoci
    //    np. "Znaleziono wartoć %.. w %d elemencie tablicy\n", ...
    int look_for;
    printf("podaj wartosc szukanego elementu (od 33 do 126): \n");
    scanf("%d", &look_for);

    //  d1. wyszukanie tylko jednej (pierwszej) wartoci - pętla while
    //      (lub pętla for i break)
    for (int i = 0; i < ROZMIAR_TABLICY2; i++)
    {
        if (look_for == (int)tablicaczarow[i])
        {
            printf("Pierwszy znaleziony element: \nZnaleziono wartosc %d w %d elemencie tablicy\n\n", look_for, i + 1);
            break;
        }
    }
    //  d2. wyszukanie (i wypisanie) wszytskich wartoci - pętla for
    //      (lub pętla while)
    printf("Wszystkie znalezione elementy: \n");
    for (int i = 0; i < ROZMIAR_TABLICY2; i++)
    {
        if (look_for == (int)tablicaczarow[i])
            printf("Znaleziono wartosc % d w % d elemencie tablicy\n", look_for, i + 1);
    }
    //-------------------------------- 4.0 ------------------------------------
  


}

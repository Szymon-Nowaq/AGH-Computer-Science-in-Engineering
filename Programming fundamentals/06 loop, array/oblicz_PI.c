#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#define SCALAR double
#define SCALAR float

#define SMALL_NUMBER 1.e-20

#ifndef M_PI // standardy C99 i C11 nie wymagają definiowania stałej M_PI
#define M_PI (3.14159265358979323846)
#endif

#define DOKLADNOSC 0.001
//#define MAX_LICZBA_WYRAZOW 1111111111
#define MAX_LICZBA_WYRAZOW 111111

int main( void ){ // program obliczania przybliżenia PI za pomocą wzoru Leibniza
                   // PI = 4 * ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + itd. )

  int max_liczba_wyrazow = MAX_LICZBA_WYRAZOW;
  //printf("Podaj maksymalną liczbę wyrazów do obliczenia przybliżenia PI\n");
  //scanf("%d", &max_liczba_wyrazow);

  SCALAR dokladnosc = DOKLADNOSC;
  printf("Podaj dokladnosc obliczenia przyblizenia PI\n");
  if(sizeof(SCALAR)==4){ // czterobajtowe liczby zmiennoprzecinkowe -> float
    scanf("%f", &dokladnosc);
  }
  else{
    scanf("%lf", &dokladnosc);
  }

  // wzór: PI/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 itd. itp.  
  SCALAR suma_plus=0.0;
  SCALAR suma_minus=0.0;
  SCALAR aktualnePI = 0.0;
  SCALAR poprzedniePI = 0.0;
  int i = 0, j = 1, ite = 0;
  // alternatywa: for(i=0; i<ceil(max_liczba_wyrazow/2.0); i++){
  do{
    suma_plus += 1.0/j;
    suma_minus += 1.0/(j+2.0);
    if(suma_plus < SMALL_NUMBER || suma_minus < SMALL_NUMBER)
    {
	printf("przerwanie petli w %d iteracji\nosiegnieto wartosci zbyt bliskie zero", ite);
        break;
    }
    j += 4;
    poprzedniePI = aktualnePI;
    aktualnePI = 4*(suma_plus-suma_minus);
    if((aktualnePI - poprzedniePI) < SMALL_NUMBER)
    {
	printf("przerwanie petli w %d\nosiagnieto maksymalna dokladnosc\n", ite);
	break;
    }
    printf("PI obliczone: %20.15lf, aktualna poprawka: %20.15lf\n",
    aktualnePI, 4.0/j-4.0/(j+2.0));

    i = (j-1)/4;
    if(i>=ceil(max_liczba_wyrazow/2.0)) {
	        printf("Przekroczona maksymalna liczba wyrazow %d", max_liczba_wyrazow);
	        printf(" przed osiagnieciem założonej dokladnosci - break\n");
	        break;
     }
     ite++;
      // niska dokładność float - znany przykład (a+b)-a = 0 zamiast b 
      //    if(sizeof(SCALAR)==4){ // czterobajtowe liczby zmiennoprzecinkowe -> float

      //      SCALAR temp_PI = 4*(suma_plus-suma_minus);
      //	SCALAR temp_poprawka = (4.0/j-4.0/(j+2.0)); // zawsze dodatnia
      //	if( (temp_PI + temp_poprawka) - temp_PI < SMALL_NUMBER ){

      //	  printf("Dodatkowe wyrazy przestaja zmieniac wynik! Przerwanie obliczen!\n");
      //	  break;
	  
      //	}

      //      }



      //} while(i<ceil(max_liczba_wyrazow/2.0));
      //} while(i<ceil(max_liczba_wyrazow/2.0) && 4.0/j > dokladnosc);
  } while( ( 4.0/j - 4.0/(j+2.0) ) > dokladnosc );

  printf("PI obliczone: %20.15lf, PI z biblioteki matematycznej: %20.15lf\n",
	 4*(suma_plus-suma_minus), M_PI);
  printf("Zalozona dokladnosc: %20.15lf, rzeczywisty blad: %20.15lf\n",
	 dokladnosc, fabs( 4*(suma_plus-suma_minus) - M_PI) );
  return 0;
	/*
w przypadku petli while i podaniu adekwatnej do warunki wartosci dokladnosci petla sie nie wykona
w przypadku for mozliwe jest brak wejscia w petle, poza tym roznic sie bedzie zapis, poszczegolne operacje mozna bedzie umiescic argumentach funkcji
*/
}



  // całka
  /* h   = 1.0 / (SCALAR) n; */
  /* sum = 0.0; */
  /* for (i = 1; i <= n; i++) { */
  /*   x = h * ((SCALAR)i - 0.5); */
  /*   sum += 4.0 / (1.0 + x*x); */
  /* } */
  /* mypi = h * sum; */

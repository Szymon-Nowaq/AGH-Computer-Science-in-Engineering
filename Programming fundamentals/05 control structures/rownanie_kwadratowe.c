#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

#define SCALAR float
//tolerancja double:
#define TOLERANCJA 1
//#define SCALAR float
//tolerancja float:
//#define TOLERANCJA 10e-8
#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?

// Konstrukcje sterujące (nazwy zmiennych, zakresy widoczności i czas życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // prosta wersja: int a, b, c;
	for(int i = 5; i <=25; i++)
	  {
		  SCALAR a = pow(10,-i), b = 2, c = 1;
		  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
		  // input - uodpornianie na błędy wczytywania danych 
		  //printf("\nPodaj parametr a: "); scanf(" %lf",&a); // adres! (miejsce na wpisanie wartości)
		  //printf("Podaj parametr b: "); scanf(" %lf", &b); // uwaga: inny format dla float!
		  //printf("Podaj parametr c: "); scanf(" %lf", &c);
			
		  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
		  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie
		    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
		    exit(-1);
		  }
		  //if(fabs(a) < TOLERANCJA || fabs(b) < TOLERANCJA || fabs(c) < TOLERANCJA)
		  //{
		//	printf("wprowadzona wartosc a lub b lub c jest zbyt mala, interpretowana przez kompilator jako 0\n");
			//exit(-1); 
		   //}
 		  else{
		    if(fabs(a) == 0) { // równanie liniowe
		      	//co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?
		      	a = 0;
		      	SCALAR x1 = -c/b;
		      	//printf("równanie liniowe, jeden pierwiastek rzeczywisty: %20.15lf\n", x1);
		    }
		    else{
		      	SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
		      	delta = b*b - 4*a*c; // czy delta = b*b (w skończonej precyzji)?
			printf("i = %d -> delta = %20.15f \n",i, delta);
		      	if(delta<0){
		      		SCALAR sqrdeltaIm = sqrt(fabs(delta));
		      		SCALAR xRe = -b/2*a;
		      		SCALAR xIm = sqrdeltaIm/2 * a;
				//printf("Dwa pierwiastki zespolone, (RE + IM):\nx1 = %20.15lf + %20.15lf * i\nx2 = %20.15lf + %20.15lf * i\n", xRe, xIm, xRe, xIm * -1);
		     	 } else if (delta == 0){
				//printf("Jeden pierwiastek rzeczywisty: x = %20.15lf\n", -b/(2*a) );
				// ile cyfr znaczacych daje dzielenie dla float i dla double?
				// kiedy dzielenie dużej liczby przez małą liczbę da w efekcie śmieci?
		      	} else {
				SCALAR temp = sqrt(delta);
				SCALAR x1 = (-b-temp)/(2*a), x2 = (-b+temp)/(2*a);
S				SCALAR fx1 = a*x1*x1 + b*x1 +c , fx2 = a*x2*x2 + b*x2 +c
				if(fabs((fx1) <= TOLERANCJA && (fx2) <= TOLERANCJA))
				{  
					//printf("Dwa pierwiastki rzeczywiste: x1 = %20.15lf, x2 = %20.15lf\n", x1, x2 );
				      //	printf("f(x1) = %20.15lf\nf(x2) = %20.15lf\n", a*x1*x1 + b*x1 + c , a*x2*x2 + b*x2 + c);
				}else{
					//printf("Wartości przekroczyły tolerancję\n");
				}
		}  
	    }
        //  }
} // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu	  
  return(0);
}

// Lab 
// Uzupełnienie programu o obsługę wszystkich przypadków liczbowych danych wejściowych
// Różne przypadki kontraktu - uwzględniające lub nie skończoną precyzję

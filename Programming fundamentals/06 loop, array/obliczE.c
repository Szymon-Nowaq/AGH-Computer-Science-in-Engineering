#include <stdio.h>
#include <math.h>

#define M_E 2.71828182845904523536
#define SCALAR double
//#define SCALAR float
#define SMALL_NUMBER 1.e-20

int silnia(int);

void main(void)
{
	int aprox;
	SCALAR e = 0;
	printf("podaj przyblizenie, tzn z ile wyrazow sumy szeregu dodac do siebie:\n");
	scanf("%d", &aprox);
	for (int i = 0; i < aprox; i++)
	{
		e += 1.0 / (SCALAR) silnia(i);
		if((1.0 / (SCALAR) silnia(i)) < SMALL_NUMBER )
    		{
			printf("przerwanie petli w %d iteracji\nosiegnieto wartosci zbyt bliskie 				zero", ite);
        	break;
    		}
		if( < SMALL_NUMBER)
    		{
		printf("przerwanie petli w %d\nosiagnieto maksymalna dokladnosc\n", i);
		break;
    		}
	}
	if(sizeof(SCALAR) == 8){
		printf("e obliczone: %20.15lf\ne z biblioteki matematycznej: %20.15lf\n",e, (double)M_E);
	}	
	else{
		printf("\nZalozona dokladnosc: %d\nrzeczywisty blad: %20.15f\n", aprox, (float)M_E - e);
	}
	//for (int i = 0; i < 10; i++)
		//printf("%d! = %d\n", i , silnia(i));
}

int silnia(int a)
{
	int suma = 1;
	for (int i = 0; i < a; i++)
		suma *= i + 1;
	return suma;
}

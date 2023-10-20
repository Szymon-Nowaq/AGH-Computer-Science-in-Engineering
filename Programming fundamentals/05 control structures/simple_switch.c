#include <stdio.h>

void main(void)
{
  
  char c;
  for(;;){  // wykonywanie nieskończenie wiele razy

    printf("\nWprowadź cyfrę od 1 do 5: \nAby zakończyć program wprowadź 'z'\n");  
    scanf(" %c",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyć się \n ?)
    if(c == 'z')
    {
    	return;
    }else if(c == '0'){
    	printf("Wprowadzono: 0\n");
    }else if(c == '1'){
    	printf("Wprowadzono: 1\n");
    	printf("Wprowadzono: 1 lub 2\n");
    }else if(c == '2'){
    	printf("Wprowadzono: 1 lub 2\n");
    }else if(c == '3'){
    	printf("Wprowadzono: 3\n");
    }else if(c == '4' || c == '5'){
    	printf("Wprowadzono: 4 lub 5\n");
    }else{
    	printf("Wprowadzono: znak spoza zakresu 0-5\n");
    }
  }

}

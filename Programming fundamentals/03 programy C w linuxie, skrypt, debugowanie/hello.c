#include <stdio.h>

int main(void)
{
	for(int i = 0; i<9; i++)
	{
		printf("\t");
		for(int j = 0; j < i; j++)
			printf("\b");
		printf("/");
		for(int k = 0; k < i; k++)
			printf("  ");
		printf("\\\n");
	}
}



#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 9

int main(void) {
	int numeros[CANTIDAD]={54,26,93,17,77,31,44,55,27};
	int i;
	int j;
	int aux;

	for(i=0;i<CANTIDAD;i++)
	{
		printf("%d\t",numeros[i]);
	}

	for(i=0;i<CANTIDAD-1;i++)
	{
		for(j=i+1;j<CANTIDAD;j++)
		{
			if(numeros[i]<numeros[j])
			{
				aux=numeros[i];
				numeros[i]=numeros[j];
				numeros[j]=aux;
			}
		}
	}
	printf("\n");
	for(i=0;i<CANTIDAD;i++)
		{
			printf("%d\t",numeros[i]);
		}

	for(i=0;i<CANTIDAD-1;i++)
	{
		for(j=i+1;j<CANTIDAD;j++)
		{
			if(numeros[i]>numeros[j])
			{
				aux=numeros[i];
				numeros[i]=numeros[j];
				numeros[j]=aux;
			}
		}
	}
	printf("\n");
	for(i=0;i<CANTIDAD;i++)
		{
			printf("%d\t",numeros[i]);
		}

	return EXIT_SUCCESS;
}

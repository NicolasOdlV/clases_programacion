
#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 9

int imprimirArray(int* pArray, int len);
int ordenarArray(int* pArray, int len);

int main(void) {

	int numeros[CANTIDAD]={54,26,93,17,77,31,44,55,27};
	int respuesta;

	imprimirArray(numeros,CANTIDAD);

	respuesta=ordenarArray(numeros,CANTIDAD);

	if(respuesta > 0)
	{
		printf("\n\nIteracion: %d\n\n",respuesta);
	}

	imprimirArray(numeros,CANTIDAD);

	return EXIT_SUCCESS;
}

int imprimirArray(int* pArray, int len)
{
	int retorno=-1;
	int i;

	if(pArray!=NULL && len>=0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			printf("%d\t",pArray[i]);
		}
	}

	return retorno;
}
int ordenarArray(int* pArray, int len)
{
	int flagSwap;
	int i;
	int aux;
	int contador=0;
	int retorno=-1;
	int nuevoLimite;

	if(pArray!=NULL && len >= 0)
	{

		nuevoLimite=len-1;

			do
			{
				flagSwap=0;
				for(i=0;i<nuevoLimite;i++)
				{
					if(pArray[i] < pArray[i+1])
					{
						flagSwap=1;
						aux=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=aux;
					}
					contador++;
				}
				nuevoLimite--;
			}while(flagSwap);
			retorno=contador;
	}
		return retorno;
}

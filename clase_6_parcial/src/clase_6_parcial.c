/*
 ============================================================================
 Name        : clase_6_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define CANT 10

int ordenarAscendente(int* pArray,int len);
int ordenarDescendente(int* pArray, int len);
int imprimir(int* pArray,int len);
int main(void)
{
	int numeros[CANT]={25,96,87,152,46,12,64,128,784,22};
	imprimir(numeros,CANT);
	printf("\n\n==========================================================================\n\n");
	ordenarAscendente(numeros,CANT);
	imprimir(numeros,CANT);
	printf("\n\n==========================================================================\n\n");
	ordenarDescendente(numeros,CANT);
	imprimir(numeros,CANT);

	return EXIT_SUCCESS;
}

int imprimir(int* pArray,int len)
{
	int i;
	int retorno= -1;
	if(pArray!=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			printf("%d\t",pArray[i]);
		}
		retorno=0;
	}
	return retorno;
}


int ordenarAscendente(int* pArray,int len)
{
	int i;
	int aux;
	int flagSwap;
	int cotaSup;
	int retorno=-1;

	if(pArray!=NULL && len>0)
	{
		cotaSup=len-1;
		do
		{
			flagSwap=0;
			for(i=0;i<cotaSup;i++)
			{
				if(pArray[i]<pArray[i+1])
				{
					flagSwap=1;
					aux=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=aux;
				}
			}
			cotaSup--;
		}while(flagSwap);
		retorno=0;
	}
	return retorno;
}

int ordenarDescendente(int* pArray, int len)
{
		int i;
		int aux;
		int flagSwap;
		int cotaSup;
		int retorno=-1;

		if(pArray!=NULL && len>0)
		{
			cotaSup=len-1;
			do
			{
				flagSwap=0;
				for(i=0;i<cotaSup;i++)
				{
					if(pArray[i]>pArray[i+1])
					{
						flagSwap=1;
						aux=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=aux;
					}
				}
				cotaSup--;
			}while(flagSwap);
			retorno=0;
		}
		return retorno;
}







/*
void intSwap(int* pNumeroA,int* pNumeroB)
{
	int buffer;
	buffer=*pNumeroA;
	*pNumeroA=*pNumeroB;
	*pNumeroB=buffer;

}
*/

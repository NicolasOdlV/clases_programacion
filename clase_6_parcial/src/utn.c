/*
 * utn.c
 *
 *  Created on: 14 abr. 2020
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>


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

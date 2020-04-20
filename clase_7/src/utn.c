/*
 * utn.c
 *
 *  Created on: 9 abr. 2020
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include  <ctype.h>


int dividir (float* pResultado,int operador1,int operador2)
{
	float resultado;
	int retorno = -1;

	if(pResultado != NULL && operador2 != 0)
	{
		resultado = (float) operador1 / operador2;
		*pResultado = resultado;
		retorno=0;
	}
	return retorno;
}

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	int bufferInt;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%d",&bufferInt);
	}
	if(bufferInt<minimo||bufferInt>maximo)
	{
		for(;reintentos>0;reintentos--)
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%d",&bufferInt);

				if(!(bufferInt<minimo||bufferInt>maximo))
				{
					*pResultado=bufferInt;
					retorno=0;
					break;
				}
			}
	}
	else
	{
		*pResultado=bufferInt;
		retorno=0;
	}
	return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	float bufferFloat;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%f",&bufferFloat);
	}
	if(bufferFloat<minimo||bufferFloat>maximo)
	{
		for(;reintentos>0;reintentos--)
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%f",&bufferFloat);

				if(!(bufferFloat<minimo||bufferFloat>maximo))
				{
					*pResultado=bufferFloat;
					retorno=0;
					break;
				}
			}
	}
	else
	{
		*pResultado=bufferFloat;
		retorno=0;
	}
	return retorno;
}

int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char bufferChar;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&bufferChar);
	}
	bufferChar=tolower(bufferChar);
	if(bufferChar<minimo||bufferChar>maximo)
	{
		for(;reintentos>0;reintentos--)
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%c",&bufferChar);

				if(!(bufferChar<minimo||bufferChar>maximo))
				{
					*pResultado=bufferChar;
					retorno=0;
					break;
				}
			}
	}
	else
	{
		*pResultado=bufferChar;
		retorno=0;
	}
	return retorno;
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
int imprimirArrayFloat(float* pArray, int len)
{
	int retorno=-1;
	int i;

	if(pArray!=NULL && len>=0)
	{
		retorno=0;
		for(i=0;i<len;i++)
		{
			printf("Dia %d = %.3f\n",i+1,pArray[i]);
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
int ordenarArrayFloat(float* pArray, int len)
{
	int flagSwap;
	int i;
	float aux;
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
//0 son iguales 1 si encontro un mayor
int calcularMayor(int* pNumeroMayor,int numero1, int numero2)
{
	int retorno=-1;
if(pNumeroMayor!= NULL)
{
	if(numero1==numero2)
	{
		retorno=0;
	}
	else
	{
		if(numero1>numero2)
		{
			*pNumeroMayor=numero1;
		}
		else
		{
			*pNumeroMayor=numero2;
		}
		retorno=1;
	}
}
	return retorno;
}

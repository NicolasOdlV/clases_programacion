/*
 * utn.c
 *
 *  Created on: 7 abr. 2020
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
		scanf("%f",&bufferInt);
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
				scanf("%f",&bufferChar);

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

/*
 * utn.c
 *
 *  Created on: 21 abr. 2020
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//entero
 static int getInt(int* pResultado);
 static int esNumerica(char* cadena, int limite);
//flotante
 static int getFloat(float* pResultado);
 static int esNumericoFlotante(char* cadena, int limite);




 int myGets(char* cadena, int longitud)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char bufferString[15];// luego cambiara al usar malloc


	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]== '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]= '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString))<=longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

 static int getInt(int* pResultado)
 {
	 int retorno=-1;
	 char bufferString[50];
	 if(pResultado != NULL && myGets(bufferString,sizeof(bufferString))==0 && esNumerica(bufferString,sizeof(bufferString))==1)
	 {
		 retorno=0;
		 *pResultado= atoi(bufferString);
	 }
	 return retorno;
 }

static int esNumerica(char* cadena, int limite)
{
	int retorno = 1;
	int i;


	for(i=0;i<limite && cadena[i] != '\0';i++)
	{

		if(i==0 && (cadena[i]=='+'||cadena[i]=='-'))
		{
			continue;
		}
		if(cadena[i]<'0' || cadena[i]>'9')
		{
			retorno=0;
			break;
		}
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
		do{
			printf("%s",mensaje);
			if(getInt(&bufferInt)==0 && bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado=bufferInt;
				retorno=0;
				break;
			}
			reintentos--;
			printf("\n%s",mensajeError);
		}while(reintentos>=0);

	}
	return retorno;
}
// flotantes
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
		int retorno=-1;
		float bufferFloat;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat)==0 && bufferFloat>=minimo && bufferFloat<=maximo)
			{
				*pResultado=bufferFloat;
				retorno=0;
				break;
			}
			reintentos--;
			printf("\n%s",mensajeError);
		}while(reintentos>=0);

	}
	return retorno;
}
static int getFloat(float* pResultado)
 {
	 int retorno=-1;
	 char bufferString[50];
	 if(pResultado != NULL && myGets(bufferString,sizeof(bufferString))==0 && esNumericoFlotante(bufferString,sizeof(bufferString))==1)
	 {
		 retorno=0;
		 *pResultado= atof(bufferString);
	 }
	 return retorno;
 }

static int esNumericoFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int i;
	int contadorPunto=0;

	for(i=0;i<limite && cadena[i] != '\0';i++)
	{

		if(i==0 && (cadena[i]=='+'||cadena[i]=='-'||cadena[i]=='.'))
		{
			if(cadena[i]=='.')
			{
				contadorPunto++;
			}
			continue;
		}
		if(cadena[i]<'0' || cadena[i]>'9')
		{
			if(cadena[i]=='.' && contadorPunto<1)
			{
				contadorPunto++;
			}
			else if(contadorPunto>1)
			{
				retorno=0;
				break;
			}
			else
			{
				retorno=0;
				break;
			}
		}
	}

	return retorno;
}

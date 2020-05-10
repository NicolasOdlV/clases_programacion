/*
 * utn.c
 *
 *  Created on: 21 abr. 2020
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//entero
 static int getInt(int* pResultado);
 static int esNumerica(char* cadena, int limite);
//flotante
 static int getFloat(float* pResultado);
 static int esNumericoFlotante(char* cadena, int limite);
//caracter
 static int getChar(char* pResultado);
 static int esCaracter(char* caracter);
// string
 static int getNombre(char* pResultado, int longitud);
 static int esNombre(char* cadena,int longitud);
 static int getString(char* cadena, int longitud);


 int myGets(char* cadena, int longitud)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char bufferString[15];// luego cambiara al usar malloc


	if(cadena != NULL && longitud >= 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]== '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]= '\0';
			}
			if((strnlen(bufferString,sizeof(bufferString))<=longitud)&& longitud !=0)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
			if((strnlen(bufferString,sizeof(bufferString))<=longitud)&& longitud==0)
						{
							*cadena=bufferString[0];
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
//caracteres
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
			int retorno=-1;
			char bufferChar;
		if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
		{
			do{
				printf("%s",mensaje);
				if(getChar(&bufferChar)==0 && bufferChar>=minimo && bufferChar<=maximo)
				{
					*pResultado=bufferChar;
					retorno=0;
					break;
				}
				reintentos--;
				printf("\n%s",mensajeError);
			}while(reintentos>=0);

		}
		return retorno;
}

static int getChar(char* pResultado)
 {
	 int retorno=-1;
	 char bufferChar;
	 if(pResultado != NULL && myGets(&bufferChar,2)==0 &&esCaracter(&bufferChar)==0)
	 {
		 retorno=0;
		 *pResultado= bufferChar;
	 }
	 return retorno;
 }

static int esCaracter(char* caracter)
{
	int retorno = 1;
	char caracterValido=tolower(*caracter);

	if(caracter!=NULL)
	{
		if((caracterValido>='a' && caracterValido<='z')||(caracterValido>=0 && caracterValido<=9))
		{
			retorno=0;
		}
	}
	return retorno;
}

//string
int utn_getString(char* pResultado, char* mensaje,char* mensajeError, int longitud,int reintentos)
{
	setbuf(stdout,NULL);
	char bufferString[15];
		int retorno = -1;
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
			if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
		}
		return retorno;
}
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[15];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 &&esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
static int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[15]; // *****************************

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

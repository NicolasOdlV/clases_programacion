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
 static int directorChar(char* pResultado,int minimo, int maximo ,int opcion);
// string
 static int getString(char* cadena, int longitud);
 //llevara a la funcion que se necesite pedir
 static int director(char* pResultado, int longitud, int opcion);

 // nombre
 static int getNombre(char* pResultado, int longitud);
 static int esNombre(char* cadena,int longitud);

// telefono
 static int getTelefono(char* pResultado, int longitud);
 static int esTelefono(char* cadena,int longitud);

// dni
 static int getDni(char* pResultado, int longitud);
 static int esDni(char* cadena,int longitud);

// direccion
 static int getDireccion(char* pResultado, int longitud);
 static int esDireccion(char* pResultado, int longitud);
//Alfanumerico
 static int getCodigoAlfanumerico(char* pResultado, int longitud);
 static int esAlfanumerico(char* pResultado, int longitud);
// descripcion
static int getDescripcion(char* pResultado, int longitud);
static int esDescripcion(char* pResultado, int longitud);
// eMail
static int getMail(char* pResultado, int longitud);
static int esMail(char* pResultado, int longitud);

 int myGets(char* cadena, int longitud)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char bufferString[15];


	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1]== '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1]= '\0';
			}
			if((strnlen(bufferString,sizeof(bufferString))<=longitud))
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
int myChar(char* caracter)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char aux;
	if(caracter!=NULL)
	{
		fflush(stdin);
		scanf("%c",&aux);
		*caracter=aux;
		retorno=0;
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
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos,int opcion)
{
	setbuf(stdout,NULL);
			int retorno=-1;
			char bufferChar;
		if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
		{
			do{
				printf("%s",mensaje);
				if(directorChar(&bufferChar,minimo,maximo,opcion)==0)
						{
							retorno=0;
							*pResultado=bufferChar;
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
	 if(pResultado != NULL && myChar(&bufferChar)==0 &&esCaracter(&bufferChar)==1)
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
		if(!((caracterValido>='a' && caracterValido<='z')||(caracterValido>='0' && caracterValido<='9')))
		{
			retorno=0;
		}
	}
	return retorno;
}
static int directorChar(char* pResultado,int minimo, int maximo ,int opcion)
{
	char bufferChar;
	int retorno = -1;
	switch(opcion)
	{
		case 1:
				if(getChar(&bufferChar)==0 && bufferChar>=minimo && bufferChar<=maximo)
				{
					*pResultado=bufferChar;
					retorno=0;
				}
				break;
		case 2:
				if(getChar(&bufferChar)==0 && (bufferChar=='F'|| bufferChar=='f' || bufferChar=='m'|| bufferChar=='M'))
				{
					*pResultado=bufferChar;
					retorno=0;
				}
				break;
		default:
			break;
	}
	return retorno;
}

//string
int utn_getString(char* pResultado, char* mensaje,char* mensajeError, int longitud,int reintentos,int opcion)
{
	setbuf(stdout,NULL);
		int retorno = -1;
		while(reintentos>=0)
		{
			reintentos--;
			printf("%s",mensaje);
		if(director(pResultado,longitud,opcion)==0)
		{
			retorno=0;
			break;
		}
			printf("%s",mensajeError);
		}
		return retorno;
}
static int director(char* pResultado, int longitud, int opcion)
{
	char bufferString[20];
	int retorno = -1;
	switch(opcion)
	{
		case 1:
				if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		case 2:
				if(getTelefono(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		case 3:
				if(getDni(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		case 4:
				if(getDireccion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		case 5:

				if(getCodigoAlfanumerico(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		case 6:

				if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		case 7:

				if(getMail(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
				{
					strncpy(pResultado,bufferString,longitud);
					retorno = 0;
				}
					break;
		default:
			break;
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
//--------------------------------------------------------------------


static int getTelefono(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[15];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 &&esTelefono(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
static int esTelefono(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

static int getDni(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[9];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 &&esDni(buffer,sizeof(buffer)) && (strnlen(buffer,sizeof(buffer))>6 && strnlen(buffer,sizeof(buffer))<9))
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
static int esDni(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud>0)
	{

			for(i=0 ; cadena[i] != '\0' && i < longitud && cadena[0]!='0'; i++)
					{

						if( cadena[i] < '0' || cadena[i] > '9')
						{
							retorno = 0;
							break;
						}
					}
	}
	return retorno;
}

//---------------------------------------------------------------------
static int getDireccion(char* pResultado, int longitud)
{
    int retorno=-1;
    char bufferCalle[25];

    if(pResultado != NULL)
    {
    	if(getString(bufferCalle,sizeof(bufferCalle))==0
    	&& esDireccion(bufferCalle,sizeof(bufferCalle))
    	&& strnlen(bufferCalle,sizeof(bufferCalle))<longitud)
    	{
    		strncpy(pResultado,bufferCalle,longitud);
    		retorno=0;
    	}
    }
    return retorno;
}
static int esDireccion(char* pResultado, int longitud)
{
	int i=0;
		int retorno = 1;

		if(pResultado != NULL && longitud>0)
		{

				for(i=0 ; pResultado[i] != '\0' && i < longitud; i++)
						{

							if(	  (pResultado[i]< 'A' || pResultado[i]> 'Z')
								&&(pResultado[i]< 'a' || pResultado[i]> 'z')
								&&(pResultado[i]< '0' || pResultado[i]> '9')
								&&(pResultado[i]!= ' ' && pResultado[i]!=  '.'))
							{
								retorno = 0;
								break;
							}
						}
		}
		return retorno;
}
static int getCodigoAlfanumerico(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[15];

    if(pResultado != NULL && longitud > 0)
    {
    	if(getString(buffer,sizeof(buffer))==0 &&esAlfanumerico(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}
static int esAlfanumerico(char* pResultado, int longitud)
{
	int i=0;
		int retorno = 1;

		if(pResultado != NULL && longitud>0)
		{

				for(i=0 ; pResultado[i] != '\0' && i < longitud; i++)
						{

							if((pResultado[i]< 'A' || pResultado[i]> 'Z')
								&&(pResultado[i]< 'a' || pResultado[i]> 'z')
								&&(pResultado[i] < '0' || pResultado[i] > '9'))
							{
								retorno = 0;
								break;
							}
						}
		}
		return retorno;
}
static int getDescripcion(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[50];

	if(pResultado != NULL && longitud > 0)
	    {
	    	if(getString(buffer,sizeof(buffer))==0 &&esDescripcion(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
	    	{
	    		strncpy(pResultado,buffer,longitud);
				retorno = 0;
			}
	    }
	    return retorno;
}
static int esDescripcion(char* pResultado, int longitud)
{
	int i=0;
	int retorno = 1;

	if(pResultado != NULL && longitud>0)
	{

			for(i=0 ; pResultado[i] != '\0' && i < longitud; i++)
					{

						if(!(pResultado[i]>' ' && pResultado[i]<'~'))
						{
							retorno = 0;
							break;
						}
					}
	}
	return retorno;
}
static int getMail(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[30];

	if(pResultado != NULL && longitud > 0)
	    {
	    	if(getString(buffer,sizeof(buffer))==0 &&esMail(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
	    	{
	    		strncpy(pResultado,buffer,longitud);
				retorno = 0;
			}
	    }
	    return retorno;
}
static int esMail(char* pResultado, int longitud)
{
	int i=0;
	int retorno = 1;
	int contadorArroba=0;
	int contadorGuion=0;
	int contadorPunto=0;
	if(pResultado != NULL && longitud>0)
	{

		for(i=0 ; pResultado[i] != '\0' && i < longitud; i++)
		{
			if(pResultado[i]=='@')
			{
				contadorArroba++;
			}
			if(pResultado[i]=='_')
			{
				contadorGuion++;
			}
			if(pResultado[i]=='.')
			{
				contadorPunto++;
			}
			if(	  (pResultado[i]< 'A' || pResultado[i]> 'Z')
				&&(pResultado[i]< 'a' || pResultado[i]> 'z')
				&&(pResultado[i]< '0' || pResultado[i]> '9')
				&&pResultado[i]!= '_' && pResultado[i]!=  '.'
				&& pResultado[i]!='@' && contadorArroba>1&& contadorPunto>1&& contadorGuion>1)
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
//--------------------------------------------------------------------
static int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[25];

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

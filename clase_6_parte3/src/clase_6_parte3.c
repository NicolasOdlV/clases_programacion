/*
 ============================================================================
 Name        : clase_6_parte3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
static int esNumerica(char* cadena);
static int getInt(int* pResultado);
int main(void) {

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

static int getInt(int* pResultado)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char buffer[20];

	fflush(stdin);
	scanf("%s",buffer);



	if(myGets(buffer, sizeof(buffer))==0  &&esNumerica(buffer))
	{
		retorno=0;
		*pResultado= atoi(buffer);
	}

	return retorno;
}
static int esNumerica(char* cadena)
{
	int retorno=1;
	int i=0;


	if(cadena[0] == '-')
	{
		i=1;
	}

	for(i=0;cadena[i] != '\0';i++)
	{
		if(cadena[i]<'0'||cadena[i]>'9')
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}
static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);
	cadena[srtlen(cadena)-1]= '\0';

	return 0;
}

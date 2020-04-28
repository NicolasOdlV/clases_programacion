/*
 ============================================================================
 Name        : clase_7_ej_6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contarPalabras(char* pFrase,int len,int* pCantPalabras);

int main(void) {
	int palabras;
	char texto[]="Las medidas de aislamiento que los diferentes paises adoptaron para frenar el avance del coronavirus.";

	if(contarPalabras(texto,sizeof(texto),&palabras)==0)
	{
		printf("El texto contiene: %d palabras",palabras);
	}
	return EXIT_SUCCESS;
}
int contarPalabras(char* pFrase,int len,int* pCantPalabras)
{
	int i;
	int contadorPalabras=0;
	int retorno=-1;

	if(pFrase != NULL && len>0 && pCantPalabras != NULL )
	{
		for(i=0;i<len && pFrase[i]!='\0';i++)
		{
			retorno=0;
			if(pFrase[i]==' ')
			{
				contadorPalabras++;
			}
			if(pFrase[i+1]=='\0'&&pFrase[i]!=' ')
			{
				contadorPalabras++;
			}
		}
		*pCantPalabras= contadorPalabras;
	}
	return retorno;
}

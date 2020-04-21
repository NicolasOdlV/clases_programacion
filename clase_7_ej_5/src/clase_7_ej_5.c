/*
 ============================================================================
 Name        : clase_7_ej_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANT 5


int main(void) {
	int numBuffer[CANT];
	int i;

	for(i=0;i<CANT;i++)
	{
		utn_getNumero(&numBuffer[i],"\nIngrese numero: ","\nNo es un numero, reintente",0,100,5);
	}
	if(borrarImpares(numBuffer,CANT)==0)
	{
		imprimirArray(numBuffer,CANT);
		ordenarArray(numBuffer,CANT,'a');
		printf("\n");
		imprimirArray(numBuffer,CANT);
	}
	return EXIT_SUCCESS;
}

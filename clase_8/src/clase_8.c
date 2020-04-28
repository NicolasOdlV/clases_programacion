/*
 ============================================================================
 Name        : clase_8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	/*
	int numero;

		if(utn_getNumero(&numero, "\nIngrese un numero entre 0 y 5:  ","\nEl numero es erroneo",0,5,2) == 0)
		{
			printf("\nEl numero es %d",numero);
		}
		else
		{
			printf("\nEl dato ingresado es erroneo, sin reintentos disponibles");
		}

		*/

		float numerin;
		if(utn_getNumeroFlotante(&numerin, "\nIngrese un numero entre 0 y 5:  ","\nEl numero es erroneo",0,5.0,2) == 0)
				{
					printf("\nEl numero es %.2f",numerin);
				}
				else
				{
					printf("\nEl dato ingresado es erroneo, sin reintentos disponibles");
				}



	return EXIT_SUCCESS;
}

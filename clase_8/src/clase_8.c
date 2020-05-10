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
	/*
		float numerin;
		if(utn_getNumeroFlotante(&numerin, "\nIngrese un numero entre 0 y 5:  ","\nEl numero es erroneo",0,5.0,2) == 0)
				{
					printf("\nEl numero es %.2f",numerin);
				}
				else
				{
					printf("\nEl dato ingresado es erroneo, sin reintentos disponibles");
				}
*/
	char opcion;
	if(utn_getCaracter(&opcion, "\na)Imprimir letra A\nb)Imprimir letra B\nc)Imprimir letra C\nd)Imprimir letra D\ne)Imprimir letra E\nIngrese la letra de la opcion:  ","\nLetra de la opcion invalida",'a','e',2) == 0)
					{
						switch(opcion)
						{
						case 'a':
								printf("\nLetra a");
							break;
						case 'b':
							printf("\nLetra b");
							break;
						case 'c':
							printf("\nLetra c");
							break;
						case 'd':
							printf("\nLetra d");
							break;
						case 'e':
							printf("\nLetra e");
							break;
						default:
							printf("\nIntentelo nuevamente");
							break;
						}
					}
					else
					{
						printf("\nEl dato ingresado es erroneo, sin reintentos disponibles");
					}

	return EXIT_SUCCESS;
}

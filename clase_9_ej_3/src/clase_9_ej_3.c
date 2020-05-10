/*
 ============================================================================
 Name        : clase_9_ej_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "utn.h"
#define CANT 100

int main(void) {

	Producto productos[100];
	productos_initArray(productos,CANT);


	return EXIT_SUCCESS;
}

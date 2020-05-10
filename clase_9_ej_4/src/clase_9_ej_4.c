/*
 ============================================================================
 Name        : clase_9_ej_4.c
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
	int i;
	int indice;
	Producto productos[CANT];
	productos_initArray(productos,CANT);

	if(producto_cargarProducto(productos,CANT,utn_getNumero(&indice,"Ingrese el numero del indice a guardar","La posicion ingresada no existe",0,CANT-1,2))==1)
	{
		printf("\nCarga exitosa en posicion %d",indice);
	}
	for(i=0;i<CANT;i++)
	{
		producto_imprimirProducto(&productos[indice]);
	}

	return EXIT_SUCCESS;
}

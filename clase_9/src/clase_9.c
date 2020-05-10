/*
 ============================================================================
 Name        : clase_9.c
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

int main(void) {

	Producto producto;
/*
	char auxNombre[15];
	char auxDescripcion[20];
	float auxPrecio;

	if(utn_getString(auxNombre,"\nIngrese nombre del producto: ","\nNombre invalido",sizeof(auxNombre),2)==0)
	{
		strncpy(producto.nombreProducto,auxNombre,sizeof(auxNombre));
		if(utn_getString(auxDescripcion,"\nIngrese Descripcion del producto: ","\nDescripcion invalido",sizeof(auxDescripcion),2)==0)
		{
			strncpy(producto.descripcion,auxDescripcion,sizeof(auxDescripcion));
			if(utn_getNumeroFlotante(&auxPrecio,"\nIngrese precio del producto: ","\nPrecio invalido",0,100,2)==0)
			{
				producto.precio=auxPrecio;
			}
		}
	}
*/
	if(utn_getString(producto.nombreProducto,"\nIngrese nombre del producto: ","\nNombre invalido",15,2)==0
	&&utn_getString(producto.descripcion,"\nIngrese Descripcion del producto: ","\nDescripcion invalido",15,2)==0
	&&utn_getNumeroFlotante(&producto.precio,"\nIngrese precio del producto: ","\nPrecio invalido",0,100,2)==0)
		{
			printf("\n%s\t\t%s\t\t%.2f",producto.nombreProducto,producto.descripcion,producto.precio);
		}

	return EXIT_SUCCESS;
}

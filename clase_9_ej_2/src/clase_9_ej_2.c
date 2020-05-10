/*
 ============================================================================
 Name        : clase_9_ej_2.c
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
	float descuento=0.25;
	char seguir;

	if(utn_getString(producto.nombreProducto,"\nIngrese nombre del producto: ","\nNombre invalido",15,2)==0
		&&utn_getString(producto.descripcion,"\nIngrese Descripcion del producto: ","\nDescripcion invalido",15,2)==0
		&&utn_getNumeroFlotante(&producto.precio,"\nIngrese precio del producto: ","\nPrecio invalido",0,100,2)==0)
			{
				//printf("\n%s\t\t%s\t\t%.2f",producto.nombreProducto,producto.descripcion,producto.precio);
				producto_imprimirProducto(&producto);
			}
	if(utn_getCaracter(&seguir,"\nDesea aplicar 25% de descuento? s/n","No ha ingresado correctamente la letra",'n','s',2)==0)
	{
		if(seguir=='s')
		{
			producto.precio=producto.precio*(1-descuento);
		//	printf("\n%s\t\t%s\t\tTotal con descuento: %.2f",producto.nombreProducto,producto.descripcion,producto.precio);
			producto_imprimirProducto(&producto);
		}
		else
		{
		//	printf("\n%s\t\t%s\t\tTotal sin descuento: %.2f",producto.nombreProducto,producto.descripcion,producto.precio);
			producto_imprimirProducto(&producto);
		}
	}

	return EXIT_SUCCESS;
}

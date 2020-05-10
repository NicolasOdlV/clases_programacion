/*
 * Producto.c
 *
 *  Created on: 28 abr. 2020
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "utn.h"

void producto_imprimirProducto(Producto* pProducto)
{
	printf("\n%d\t\t%s\t\t%s\t\t%.2f",pProducto->isEmpty,pProducto->nombreProducto,pProducto->descripcion,pProducto->precio);
}
int productos_initArray(Producto* pProducto,int longitud)
{
	int retorno=-1;
	int i;

	if(pProducto!=NULL)
	{
		for(i=0;i<longitud;i++)
			{
				pProducto[i].isEmpty=1;
			}
		retorno=0;
	}

	return retorno;
}
int producto_cargarProducto(Producto* producto,int longitud,int indice)
{
	int retorno=0;
	Producto productoAux;

	if(producto!=NULL&& longitud >0 && indice < longitud )
	{
		if(utn_getString(productoAux.nombreProducto,"\nIngrese nombre del producto: ","\nNombre invalido",15,2)==0
				&&utn_getString(productoAux.descripcion,"\nIngrese Descripcion del producto: ","\nDescripcion invalido",15,2)==0
				&&utn_getNumeroFlotante(&productoAux.precio,"\nIngrese precio del producto: ","\nPrecio invalido",0,100,2)==0)
		{
			producto[indice]=productoAux;
			producto[indice].isEmpty=0;
			retorno=1;
		}
	}
	return retorno;
}

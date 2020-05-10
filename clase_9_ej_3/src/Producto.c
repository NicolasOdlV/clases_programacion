/*
 * Producto.c
 *
 *  Created on: 28 abr. 2020
 *      Author: Nicolas
 */

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

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

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
	printf("\n%s\t\t%s\t\t%.2f",pProducto->nombreProducto,pProducto->descripcion,pProducto->precio);
}

/*
 * Producto.h
 *
 *  Created on: 28 abr. 2020
 *      Author: Nicolas
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct{
	char nombreProducto[15];
	char descripcion[20];
	float precio;
	int isEmpty;
}Producto;
void producto_imprimirProducto(Producto* pProducto);
int productos_initArray(Producto* pProducto,int longitud);
#endif /* PRODUCTO_H_ */

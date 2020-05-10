/*
 * Producto.h
 *
 *  Created on: Apr 23, 2020
 *      Author: Mauro
 */

#ifndef FANTASMA_H_
#define FANTASMA_H_

#define MACRO1_LEN 50
#define MACRO2_LEN 20

typedef struct
{
	char campoStr1[MACRO1_LEN];
	char campoStr2[MACRO2_LEN];
	float campoFloat1;
	int isEmpty;
	int id;
}Fantasma;

int fan_imprimir(Fantasma* auxProducto);
int fan_inicializarArray(Fantasma* array,int limite);
int fan_altaArray(Fantasma* array,int limite, int indice, int* id);
int fan_getEmptyIndex(Fantasma* array,int limite);
int fan_imprimirArray(Fantasma* array,int limite);
int fan_buscarId(Fantasma array[], int limite, int valorBuscado);
int fan_ordenarPorNombre(Fantasma* array,int limite);
int fan_modificarArray(Fantasma* array,int limite, int indice);
int fan_bajaArray(Fantasma* array,int limite, int indice);

#endif /* FANTASMA_H_ */

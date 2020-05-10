/*
 * Objeto.h
 *
 *  Created on: 4 may. 2020
 *      Author: Nicolas
 */

#ifndef OBJETO_H_
#define OBJETO_H_

#define MACRO1 20
#define MACRO2 20

typedef struct
{
	char caracter;
	int entero;
	float decimal;
	char str1[MACRO1];
	char str2[MACRO2];
	int isEmpty;
	int id;
}Objeto;
int obj_imprimir(Objeto* auxObjeto);
int obj_inicializarArray(Objeto* array,int limite);
int obj_alta(Objeto* array,int limite, int indice, int* id);
int obj_getEmptyIndex(Objeto* array,int limite);
int obj_imprimirArray(Objeto* array,int limite);
int obj_buscarId(Objeto array[], int limite, int buscarNroId);
int obj_modificar(Objeto* array,int limite, int indice);
int obj_baja(Objeto* array,int limite, int indice);
int obj_ordenarPorNombre(Objeto* array,int limite);
#endif /* OBJETO_H_ */

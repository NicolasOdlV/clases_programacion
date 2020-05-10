/*
 ============================================================================
 Name        : ABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Objeto.h"
#define CANT_OBJ 5

int main(void) {

Objeto bufferObjeto[CANT_OBJ];
int idObjeto=0;
int opcion;
int auxIndice;
int auxId;

if(obj_inicializarArray(bufferObjeto,CANT_OBJ)==0)
{
	printf("\nInicializacion completa");
}

do{
	if(utn_getNumero(&opcion,"\n1)Alta de objeto\n2)Baja de objeto\n3)Modificar de objeto\n4)Ordenar lista de objetos\n5)Imprimir lista de objetos\n6)Salir\n","\ERROR",1,6,2)==0)
	{
		switch(opcion)
			{
				case 1:
					auxIndice=obj_getEmptyIndex(bufferObjeto,CANT_OBJ);
					if(auxIndice>=0 && obj_alta(bufferObjeto,CANT_OBJ,auxIndice,&idObjeto)==0)
					{
						printf("\n¡Alta exitosa!");
					}
					else
					{
						printf("\nCapacidad llena.");
					}
					break;
				case 2:
					obj_imprimirArray(bufferObjeto,CANT_OBJ);
					if(utn_getNumero(&auxId,"\nIngrese el ID del objeto a eliminar: ","\nID invalido",0,idObjeto,2)==0)
					{
						auxIndice=obj_buscarId(bufferObjeto,CANT_OBJ,auxId);
						if(auxIndice>=0 && obj_baja(bufferObjeto,CANT_OBJ,auxIndice)==0)
						{
							printf("\nBaja exitosa");
						}
					}
					break;
				case 3:
					obj_imprimirArray(bufferObjeto,CANT_OBJ);
					if(utn_getNumero(&auxId,"\nIngrese el ID del objeto a eliminar: ","\nID invalido",0,idObjeto,2)==0)
					{
						auxIndice=obj_buscarId(bufferObjeto,CANT_OBJ,auxId);
						if(auxIndice>=0 && obj_modificar(bufferObjeto,CANT_OBJ,auxIndice)==0)
						{
							printf("\nModificacion exitosa");
						}
					}
					break;
				case 4:
					if(obj_ordenarPorNombre(bufferObjeto,CANT_OBJ)==0)
					{
						printf("\nOrdenamiento con exito");
					}
					break;
				case 5:
					obj_imprimirArray(bufferObjeto,CANT_OBJ);
					break;
				case 6:
					break;
				default:
					printf("\nOpcion invalida");
					break;
			}

	}
	}while(opcion!=6);


	return EXIT_SUCCESS;
}

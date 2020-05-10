/*
 * Objeto.c
 *
 *  Created on: 4 may. 2020
 *      Author: Nicolas
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Objeto.h"

int obj_imprimir(Objeto* auxObjeto)
{
	int retorno=-1;

	if(auxObjeto!=NULL && auxObjeto->isEmpty ==0)
	{
		retorno=0;
		printf("\nID:%d\t\tstr1:%s\t\tstr2:%s\t\tnumero:%d\t\tdecimal:%.3f\t\tcaracter:%c",auxObjeto->id,auxObjeto->str1,auxObjeto->str2,auxObjeto->entero,auxObjeto->decimal,auxObjeto->caracter);
	}

	return retorno;
}
int obj_imprimirArray(Objeto* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			obj_imprimir(&array[i]);
		}
	}
	return retorno;
}

int obj_inicializarArray(Objeto* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty=1;
		}
	}
	return retorno;
}

int obj_getEmptyIndex(Objeto* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int obj_alta(Objeto* array,int limite, int indice, int* id)
{
	int retorno=-1;
	Objeto bufferObjeto;
	if(array!=NULL && limite>0 && indice<limite && id!=NULL)
	{
		if(

			utn_getCaracter(&bufferObjeto.caracter,"\nCaracter: ","\nERROR",'f','m',2,2)==0 &&
			utn_getString(bufferObjeto.str1,"\nNombre: ","\nERROR",MACRO1,2,1)==0 &&
			utn_getString(bufferObjeto.str2,"\nApellido: ","\nERROR",MACRO2,2,1)==0 &&
			utn_getNumero(&bufferObjeto.entero,"\nNumero: ","\nERROR",0,100,2)==0 &&
			utn_getNumeroFlotante(&bufferObjeto.decimal,"\nDecimal: ","\nERROR",0,100,2)==0)
		{
			retorno=0;
			bufferObjeto.isEmpty=0;
			bufferObjeto.id= *id;
			array[indice]=bufferObjeto;
			(*id)++;
		}
	}
	return retorno;
}

int obj_modificar(Objeto* array,int limite, int indice)
{
	int retorno=-1;
		Objeto bufferObjeto;
		if(array!=NULL && limite>0 && indice<limite && indice>=0 && array[indice].isEmpty==0)
		{
			if(utn_getCaracter(&bufferObjeto.caracter,"\nIngrese su caracter: ","\nDato ingresado invalido",'f','m',2,2)==0 &&
					utn_getString(bufferObjeto.str1,"\nIngrese su string1: ","\nDato ingresado invalido",MACRO1,2,1)==0
			&&utn_getString(bufferObjeto.str2,"\nIngrese su string2: ","\nDato ingresado invalido",MACRO2,2,1)==0
			&&utn_getNumero(&bufferObjeto.entero,"\nIngrese su numero: ","\nDato ingresado invalido",0,100,2)==0
			&&utn_getNumeroFlotante(&bufferObjeto.decimal,"\nIngrese su numero decimal: ","\nDato ingresado invalido",0,100,2)==0)
			{
				retorno=0;
				bufferObjeto.isEmpty=0;
				bufferObjeto.id=array[indice].isEmpty;
				array[indice]=bufferObjeto;
			}
		}
		return retorno;
}

int obj_baja(Objeto* array,int limite, int indice)
{
	int retorno=-1;

		if(array!=NULL && limite>0 && indice<limite && indice>=0 && array[indice].isEmpty==0)
		{
			retorno=0;
			array[indice].isEmpty=1;
		}
		return retorno;

}

int obj_buscarId(Objeto array[], int limite, int buscarNroId)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && buscarNroId>=0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id==buscarNroId)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}


int obj_ordenarPorNombre(Objeto* array,int limite)
{
	int retorno=-1;
	int i;
	int swap;
	Objeto auxObjeto;
	if(array!=NULL && limite>0)
	{
		do
		{
			swap=0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].str1,array[i+1].str1,MACRO1)>0)
				{
					auxObjeto=array[i];
					array[i]=array[i+1];
					array[i+1]=auxObjeto;
					swap=1;
				}
			}
			limite--;
		}while(swap);
		retorno=0;
	}
	return retorno;
}

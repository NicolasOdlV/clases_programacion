/*
 * Alumno.c
 *
 *  Created on: 26 abr. 2020
 *      Author: Nicolas
 */
#include "Alumno.h"
#include <stdio.h>
#include <stdlib.h>
int inicializarArrayAlumnos(Alumno* pArray, int limite)
{
	int retorno=-1;
	int i;

	if(pArray != NULL && limite >0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}

int imprimirArrayAlumnos(Alumno* pArray, int limite)
{
	int retorno=-1;
	int i;

	if(pArray!= NULL && limite >0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i].isEmpty==0)
			{
				printf("\n%d\t%s\t%.2f",pArray[i].legajo,pArray[i].nombre,pArray[i].altura);

			}
		}
		retorno=0;
	}
	return retorno;
}

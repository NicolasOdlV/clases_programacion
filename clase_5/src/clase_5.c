/*
 ============================================================================
 Name        : clase_5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CTE 5
void imprimirArray(int array[],int len);
float promediar(int array[], int len);
void elPromedio(int array[], int len,float* promedio);

int main(void) {
//	int edad;
	int edades[CTE];
	int i;
	float promedio;


	for(i=0;i<CTE;i++)
	{
	//	if(utn_getNumero(&edad,"Ingrese una edad: ","Edad fuera del rango",0,120,0)==0)
			if(utn_getNumero(&edades[i],"Ingrese una edad: ","Edad fuera del rango",0,120,0)==0)
		{
			//edades[i]=edad;
		}
		else
		{
			printf("Edad invalida\n");
			i=i-1;
			continue;
		}
	}

 imprimirArray(edades,CTE);
 promedio=promediar(edades,CTE);
printf("\nEl promedio es: %.2f",promedio);

elPromedio(edades,CTE,&promedio);
printf("\nPromedio: %.2f",promedio);

	return EXIT_SUCCESS;
}


void imprimirArray(int array[], int len)
{
	int i;
	for(i=0;i<len;i++)
		{
			printf("Numero %d: %d\n",i+1,array[i]);
		}

}
float promediar(int array[], int len)
{
	int i;
	int acumulador=0;
	float resultado;

	for(i=0;i<len;i++)
	{
		acumulador+=array[i];
	}
	resultado=(float)acumulador/len;
	return resultado;
}
void elPromedio(int array[], int len,float* promedio)
{
	int i;
	int acumulador=0;

	for(i=0;i<len;i++)
	{
		acumulador+=array[i];
	}

	*promedio=(float)acumulador/len;
}

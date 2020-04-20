/*
 ============================================================================
 Name        : clase_7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANT 31



int main(void) {
/*
	int resultado;
	int number1, number2;
	int exito1,exito2;

do
{
	exito1=utn_getNumero(&number1,"Ingrese un numero: ","No es un numero",0,10,2);
	exito2=utn_getNumero(&number2,"Ingrese un numero: ","No es un numero",0,10,2);
}while((exito1&&exito2)!=0);

	if(calcularMayor(&resultado,number1,number2)==0)
	{
		printf("Los numeros son iguales");
	}
	else
	{
		printf("EL mayor entre %d y %d es: %d",number1,number2,resultado);
	}
*/
	//Ejercicio 2
	setbuf(stdout,NULL);
	float dias[CANT];
	int opcion;
	int exito;
	int numDiaAux;
	int i;

	for(i=0;i<CANT;i++)
	{
		dias[i]=0;
	}

	do
	{
		if(utn_getNumero(&opcion,"\n1) Imprimir Array\n2) Cargar Array\n3) Salir\nOpcion numero: ","\nOpcion invalida",1,3,0)==0)
		{
			switch(opcion)
					{
						case 1:
								if(exito==0)
								{
									imprimirArrayFloat(dias,CANT);
								}
								else
								{
									printf("\nArray no cargado");
								}
								break;
						case 2:
								fflush(stdin);
								if(utn_getNumero(&numDiaAux,"\nIngrese el numero del dia a cargar: ","\nNumero de dia invalido",1,31,0)!=-1)
								{
									do
									{
										exito=utn_getNumeroFlotante(&dias[numDiaAux-1],"\nIngrese la temperatura: ","\nTemperatura erronea",-10,50,0);
									}while(exito!=0);
								}
								break;
						case 3:
								break;
						default:
								printf("\n\tOpcion invalida");
								break;
					}

		}

	}while(opcion!=3);
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	/*
	float resultado;
	int numero1;
	int numero2;
	int respuesta;

	printf("\nNumero 1: ");
	fflush(stdin);
	scanf("%d",&numero1);
	printf("\nNumero 2: ");
	fflush(stdin);
	scanf("%d",&numero2);

	respuesta= dividir(&resultado,numero1,numero2);
	if(respuesta==0)
	{
		printf("El resultado es : %f", resultado);
	}
	else
	{
		printf("Error, no se puede dividir por cero.");
	}
	*/
	int edad;
	int peso;
	float altura;
	char letra;
	int respuesta;

	respuesta= utn_getNumero(&edad,"Edad?\n","Error, el rango de la edad es de 0 a 199",0,199,2);
	if(respuesta==0)
	{
		printf("La edad es: %d",edad);
	}
	else
	{
		printf("ERROR");
	}

	respuesta= utn_getNumero(&peso,"\nPeso?\n","Error, el rango del peso es de 0 a 500",0,500,3);
		if(respuesta==0)
		{
			printf("El peso es: %d",peso);
		}
		else
		{
			printf("ERROR");
		}

	respuesta= utn_getNumeroFlotante(&peso,"\nAltura(en metros)?\n","Error, el rango de la altura es 0 a 2.00 mts",0,2,3);
			if(respuesta==0)
			{
				printf("Su altura es: %.2f",altura);
			}
			else
			{
				printf("ERROR");
			}

	respuesta= utn_getNumero(&peso,"\nSu letra favorita?\n","Error, no ha ingresado una letra",97,122,3);
			if(respuesta==0)
			{
				printf("Su letra favorita es: %c",letra);
			}
			else
			{
				printf("ERROR");
			}

	return EXIT_SUCCESS;
}

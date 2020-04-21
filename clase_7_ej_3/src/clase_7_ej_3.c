/*
 ============================================================================
 Name        : clase_7_ej_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN 8

int validarFloat(char* pCadena);

int main(void) {
	setbuf(stdout,NULL);
	char numero[LEN];

	printf("Ingrese numero: ");
	fflush(stdin);
	scanf("%s",numero);

	if(validarFloat(numero)==1)
	{
		printf("\n%.3f",atof(numero));
	}
	else
	{
		printf("No es un numero");
	}
	return EXIT_SUCCESS;
}

int validarFloat(char* pCadena)
{
	int retorno=1;
	int i=0;
	int contadorPunto=0;

	if(pCadena!=NULL)
	{
		if(pCadena[i]=='.'||pCadena[i]=='+'||pCadena[i]=='-')
		{
			i=1;
		}
		for(;pCadena[i]!='\0';i++)
		{
			printf("%d",i);

			if(pCadena[i]<'0'||pCadena[i]>'9')
			{
				if(pCadena[i]=='.')
				{
					contadorPunto++;
					if(contadorPunto>1)
					{
						retorno=0;
						break;
					}
				}
				else
				{
					retorno=0;
					break;
				}
			}
		}
	}

	return retorno;
}

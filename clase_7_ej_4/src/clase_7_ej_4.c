/*
 ============================================================================
 Name        : clase_7_ej_4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int validarFloat(char* pCadena);
int getFloat(float* pResultado);

int main(void) {

	float precio;

	printf("Ingrese un precio: ");

	if(getFloat(&precio)==1)
	{
		printf("El precio es valido: %.3f",precio);
	}
	else
	{
		printf("Valor incorrecto");
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
 int getFloat(float* pResultado)
{
	 setbuf(stdout,NULL);
	char buffer[128];
	int retorno=0;

	if(pResultado!=NULL)
	{
		fflush(stdin);
		scanf("%s",buffer);


		if(validarFloat(buffer)==1)
		{
			*pResultado=atof(buffer);
			retorno=1;
		}
	}
	return retorno;
}

/*
 ============================================================================
 Name        : clase6_parte2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
	char nombre[19]="Juan"; // '\0'
	char apellido[11]="Lopez";
//	char auxiliar[12];
	char buffer[50];
//	int num;

//	strncpy(auxiliar,nombre,sizeof(auxiliar));
	//strncpy se le pasa un limite para usar

//	num=strnlen(auxiliar,sizeof(auxiliar));
	// version segura

//	strncat(nombre," lala",sizeof(nombre));
	// concatena de manera segura

	snprintf(buffer, sizeof(buffer),"Nombre: %s\t Apellido: %s",nombre,apellido);
	//se escribe dentro de la variable pero no la muestra en consola
	//pero para que lo vea en la consola uso printf
	printf("%s",buffer);

	return EXIT_SUCCESS;
}

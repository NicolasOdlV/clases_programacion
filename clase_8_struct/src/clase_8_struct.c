/*
 ============================================================================
 Name        : clase_8_struct.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumno.h"
#define CANT 5


int main(void) {

	Alumno auxiliar;
	Alumno arrayAlumno[CANT];

	inicializarArrayAlumnos(arrayAlumno,CANT);

	auxiliar.altura=1.85;
	auxiliar.legajo=123;
	strcpy(auxiliar.nombre,"Hector");
	auxiliar.isEmpty=0;

	arrayAlumno[1]=auxiliar;

	auxiliar.altura=1.70;
		auxiliar.legajo=124;
		strcpy(auxiliar.nombre,"Hedigberto");
		auxiliar.isEmpty=0;
		arrayAlumno[0]=auxiliar;

	imprimirArrayAlumnos(arrayAlumno,CANT);



	return EXIT_SUCCESS;
}

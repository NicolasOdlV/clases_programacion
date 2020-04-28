/*
 * utn.h
 *
 *  Created on: 21 abr. 2020
 *      Author: Nicolas
 */

#ifndef UTN_H_
#define UTN_H_

int myGets(char* cadena, int longitud);

//entero
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);

//flotante
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);



#endif /* UTN_H_ */

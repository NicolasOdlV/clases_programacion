/*
 * utn.h
 *
 *  Created on: 9 abr. 2020
 *      Author: Nicolas
 */

#ifndef UTN_H_
#define UTN_H_



int dividir (float* pResultado,int operador1,int operador2);

int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);

int imprimirArray(int* pArray, int len);
int imprimirArrayFloat(float* pArray, int len);
int ordenarArray(int* pArray, int len);
int ordenarArrayFloat(float* pArray, int len);

int calcularMayor(int* pNumeroMayor,int numero1, int numero2);


#endif /* UTN_H_ */

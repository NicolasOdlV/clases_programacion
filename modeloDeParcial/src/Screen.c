#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Screen.h"

/**
 * \brief Imprime los datos de un cliente
 * \param auxProducto Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int screen_imprimir(Screen* auxProducto,int tipo)
{
	int retorno=-1;
	if(auxProducto != NULL && auxProducto->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - Nombre: %s - Tipo: %d -Direccion: %s - Precio: %.2f",auxProducto->id,auxProducto->nombre,auxProducto->tipo,auxProducto->direccion,auxProducto->precio);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int screen_imprimirArray(Screen* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			screen_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int screen_inicializarArray(Screen* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int screen_altaArray(Screen* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Screen bufferScreen;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferScreen.nombre,SCREEN_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNumero(&bufferScreen.tipo,"\tPulse el numero 1.LED\n2.LCD","ERROR",TIPO_LED,TIPO_LCD,2)&&
			utn_getDescripcion(bufferScreen.direccion,20,"\nDireccion?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferScreen.precio,"\nPrecio?\n","\nERROR\n",0,5,2) == 0)
		{
			respuesta = 0;
			bufferScreen.id = *id;
			bufferScreen.isEmpty = 0;
			array[indice] = bufferScreen;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int screen_modificarArray(Screen* array,int limite, int indice)
{
	int respuesta = -1;
	Screen bufferScreen;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferScreen.nombre,SCREEN_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
				utn_getNumero(&bufferScreen.tipo,"\tPulse el numero 1.LED\n2.LCD","ERROR",TIPO_LED,TIPO_LCD,2)&&
				utn_getDescripcion(bufferScreen.direccion,20,"\nDireccion?\n","\nERROR\n",2) == 0 &&
				utn_getNumeroFlotante(&bufferScreen.precio,"\nAltura?\n","\nERROR\n",0,5,2) == 0)
		{
			respuesta = 0;
			bufferScreen.id = array[indice].id;
			bufferScreen.isEmpty = 0;
			array[indice] = bufferScreen;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int screen_bajaArray(Screen* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int screen_buscarId(Screen array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int screen_getEmptyIndex(Screen* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int screen_ordenarPorNombre(Screen* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Screen buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,SCREEN_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de clientes por nombre y precio
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int screen_ordenarPorNombreAltura(Screen* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Screen buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
/*
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,SCREEN_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
				else if(strncmp(array[i].nombre,array[i+1].nombre,SCREEN_LEN) == 0)
				{
					if(array[i].precio < array[i+1].precio)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}
				}
*/
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].nombre,array[i+1].nombre,SCREEN_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].precio < array[i+1].precio) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}





















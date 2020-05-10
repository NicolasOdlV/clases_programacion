/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Screens
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del cliente
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Screen.h"
#include "utn.h"

#define CANTIDAD_SCREENS 4

int main(void) {

	Screen arrayScreens[CANTIDAD_SCREENS];
	int idScreens=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(screen_inicializarArray(arrayScreens,CANTIDAD_SCREENS) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Alta de pantalla"
							"\n2.Modificar datos de pantalla"
							"\n3.Baja de pantalla"
							"\n4.Salir\n\n",
							/*
							 * 4.Contratar publicidad
							 * 5.Modificar condiciones de publicacion
							 * 6.Cancelar contratacion
							 */
							"\nError opcion invalida",1,4,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = screen_getEmptyIndex(arrayScreens,CANTIDAD_SCREENS);
				if(auxiliarIndice >= 0)
				{
					if(screen_altaArray(arrayScreens,CANTIDAD_SCREENS,auxiliarIndice,&idScreens) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				screen_imprimirArray(arrayScreens,CANTIDAD_SCREENS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idScreens,0) == 0)
				{
					auxiliarIndice = screen_buscarId(arrayScreens,CANTIDAD_SCREENS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						screen_modificarArray(arrayScreens,CANTIDAD_SCREENS,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				screen_imprimirArray(arrayScreens,CANTIDAD_SCREENS);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idScreens,0)==0)
				{
					auxiliarIndice = screen_buscarId(arrayScreens,CANTIDAD_SCREENS,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						screen_bajaArray(arrayScreens,CANTIDAD_SCREENS,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				break;
			}
		}
	}while(opcion != 4);

	return EXIT_SUCCESS;
}






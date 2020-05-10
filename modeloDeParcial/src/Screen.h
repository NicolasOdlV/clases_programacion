#ifndef SCREEN_H_
#define SCREEN_H_

#define SCREEN_LEN 50
#define DIREC_LEN 15

#define TIPO_LCD 1
#define TIPO_LED 2

typedef struct
{
	char nombre[SCREEN_LEN];
	char direccion[DIREC_LEN];
	float precio;
	int tipo;
	int isEmpty;
	int id;
}Screen;

int screen_imprimir(Screen* auxProducto);
int screen_inicializarArray(Screen* array,int limite);
int screen_altaArray(Screen* array,int limite, int indice, int* id);
int screen_getEmptyIndex(Screen* array,int limite);
int screen_imprimirArray(Screen* array,int limite);
int screen_buscarId(Screen array[], int limite, int valorBuscado);
int screen_modificarArray(Screen* array,int limite, int indice);
int screen_bajaArray(Screen* array,int limite, int indice);
int screen_ordenarPorNombre(Screen* array,int limite);

#endif /* SCREEN_H_ */

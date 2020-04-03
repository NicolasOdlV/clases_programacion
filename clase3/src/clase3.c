#include <stdio.h>
#include <stdlib.h>

int pedirDato(void);
int sumar(int operador1,int operador2 );
int restar(int operador1,int operador2 );
int multiplicar(int operador1,int operador2 );
float dividir(int operador1,int operador2);

int main(void) {

	setbuf(stdout,NULL);

	int num1;
	int num2;
	char opcion;
	int solucion;
	float solucionDiv;

	num1=pedirDato();

	printf("\nElija la letra con la opcion deseada: \na- Sumar\t b-Restar\nc-Multiplicar\td-Dividir\n");
	fflush(stdin);
	scanf("%c",&opcion);

	switch(opcion)
	{
	case 'a':
			num2=pedirDato();
			solucion=sumar(num1,num2);
			printf("Rta: %d",solucion);
			break;
	case 'b':
			num2=pedirDato();
			solucion=restar(num1,num2);
			printf("Rta: %d",solucion);
			break;
	case 'c':
			num2=pedirDato();
			solucion=multiplicar(num1,num2);
			printf("Rta: %d",solucion);
			break;
	case 'd':
			num2=pedirDato();
			if(num2!=0)
			{
				solucionDiv=dividir(num1,num2);
				printf("Rta: %.2f",solucionDiv);
			}
			else
			{
				printf("\nERROR, no se puede dividir por 0 (CERO)");
			}
			break;
	default:
		break;
	}
	return EXIT_SUCCESS;
}

int pedirDato(void)
{
	int dato;
	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%d",&dato);
	return dato;
}
int sumar(int operador1,int operador2 )
{
	int resultado;
	resultado=operador1+operador2;
	return resultado;
}

int restar(int operador1,int operador2 )
{
	int resultado;
		resultado=operador1-operador2;
		return resultado;
}
int multiplicar(int operador1,int operador2 )
{
	int resultado;
		resultado=operador1*operador2;
		return resultado;
	}
float dividir(int operador1,int operador2)
{
	float resultado;


		resultado=(float)operador1/operador2;

	return resultado;
}

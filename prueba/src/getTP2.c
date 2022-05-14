/*
 * getTP2.c
 *
 *  Created on: 13 may. 2022
 *      Author: alanl
 */
#include "getTP2.h"

static int idIncremental = 2000;
static int obtenerIdPasajero();
static int obtenerIdPasajero() {
	return idIncremental++;
}

int Menu(char menus[])
{
	int opcionMenu;
	printf("%s",menus);
	scanf("%d",&opcionMenu);
	return opcionMenu;
}
int CargarEstadoEnCero(ePasajero pasajeros[], int size)
{
	int i;
	int retorno=-1;
	if (pasajeros!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			pasajeros[i].isEmpty=0;
		}
		retorno= 0;
	}
	return retorno;
}
int RecorrerArrayBuscandoEmpy(ePasajero* pasajeros, int size)
{
	int retorno=-1;
	int i;

	if(pasajeros!=NULL&&size>0)
	{

		for(i=0;i<size;i++)
		{
			if (pasajeros[i].isEmpty==0)
			{
				return retorno=i;
				break;

			}
		}
	}
	return retorno;
}
ePasajero CargarPasajero(void)
{
	ePasajero pasajero;

		pasajero.idPasajero=obtenerIdPasajero();//Codigo album generico e incremental
		printf("Su ID de pasajero es: %d\n\n",pasajero.idPasajero); //Muestro ID pasajero generico
		// PedirCadenaCaracteres nombre pasajero
		while (PedirCadenaCaracteres("Ingrese el nombre del pasajero: \n",pasajero.nombrePasajero,51)==-1)
		{
			PedirCadenaCaracteres("Ingrese el nombre del pasajero, sin superar los 51 caracteres: \n",pasajero.nombrePasajero,51);
		}

		//Apellido pasajero
		while (PedirCadenaCaracteres("Ingrese el apellido del pasajero: \n",pasajero.apellidoPasajero,51)==-1)
		{
			PedirCadenaCaracteres("Ingrese el apellido del pasajero, sin superar los 51 caracteres: \n",pasajero.apellidoPasajero,51);
		}


		//Importe
		pasajero.precio=PedirLongFloatMinimoMaximo("Ingrese un precio: ", 1,90000000);
		while(pasajero.precio==-1)
		{
			pasajero.precio=PedirLongFloatMinimoMaximo("Error, ingrese un precio entre 1 y 90000000: ", 1,90000000);
		}
		// IdTipoPasajero
		pasajero.idTipoPasajero=PedirEnteroMinimoMaximo("Ingrese tipo de pasajero: \n1)Clase economica\n2)Clase ejecutiva\n3)Primera clase\n", 1,3);
		while(pasajero.idTipoPasajero==-1)
		{
			pasajero.idPasajero=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,3);
		}

		//CodigoVuelo
		while (PedirCadenaCaracteres("Ingrese el codigo del vuelo: \n",pasajero.codigoVuelo,10)==-1)
		{
			PedirCadenaCaracteres("Ingrese el codigo del vuelo, sin superar los 10 caracteres: \n",pasajero.codigoVuelo,10);
		}

		//Estado de vuelo
		pasajero.estadoVuelo=PedirEnteroMinimoMaximo("Seleccione estado de vuelo: \n1)Activo\n2)Cancelado\n3)Demorado", 1,3);
		while(pasajero.estadoVuelo==-1)
		{
			pasajero.estadoVuelo=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,3);
		}


		pasajero.isEmpty=1;
		return pasajero;
}
/////Validaciones

int  PedirCadenaCaracteres(char mensaje [],char cadena1[], int TAM)
{
	int retorno=0;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",cadena1);
	if (strlen(cadena1)>TAM)
	{

		printf("su ingreso es incorrecto\n");
		retorno= -1;
	}

return retorno;
}
int PedirEnteroMinimoMaximo(char mensaje[], int minimo,int maximo)
{
	int numero;
	int retorno=-1;
	printf("%s",mensaje);
	scanf("%d",&numero);
	if(numero>=minimo&&numero<=maximo)
	{
		retorno=numero;
	}
	else
	{
		retorno=-1;
	}
	return retorno;

}
double PedirLongFloatMinimoMaximo(char mensaje[], double minimo,double maximo)
{
	double numero;
	double retorno=-1;
	printf("%s",mensaje);
	scanf("%lf",&numero);
	if(numero>=minimo&&numero<=maximo)
	{
		retorno=numero;
	}
	else
	{
		retorno=-1;
	}
	return retorno;
}
int RecorrerArrayBuscandoID(ePasajero* array, int size, int id)
{
	int retorno=-1;
	int i;

	if(array!=NULL&&size>0)
	{

		for(i=0;i<size;i++)
		{
			if (array[i].isEmpty==0&&array[i].idPasajero==id)
			{
				printf("Se encontro el siguiente pasajero: %s\n",array[i].apellidoPasajero);
				return i;
				break;

			}
		}
	}
	return retorno;
}

////Fin validaciones


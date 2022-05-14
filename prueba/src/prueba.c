/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Alan Maciel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#define CANT 2000
#include <stdio.h>
#include <stdlib.h>
#include "getTP2.h"


int main(void)
{
	char continuar='s';
	int opcionMenu;
	int cantidadDeDatos=0;
	int bajaIdpasajero;
	int indiceBaja;

	eTipoPasajero tiposDePasajeros[3]=
	{
			{1,"Clase economica"},
			{2,"Clase ejecutiva"},
			{3,"Primera clase"}
	};

	setbuf(stdout,0);
	ePasajero pasajeros[CANT]; //Mi vector de pasajeros
		//Cargar estado de pasajero en cero
		CargarEstadoEnCero(pasajeros,CANT);
		//comienzo do While
		do
		{
			opcionMenu=Menu("1) Alta\n2) Modificar\n3) Baja\n4) Informar\n5) Carga forzada pasajeros\n6) Salir\n"); // El menu
			switch(opcionMenu)
			{
			case 1: //Alta
				if(RecorrerArrayBuscandoEmpy(pasajeros, CANT)>=0)
				{
					pasajeros[RecorrerArrayBuscandoEmpy(pasajeros, CANT)]=CargarPasajero();
					cantidadDeDatos++;
				}
				else
				{
					printf("No queda mas espacio en el sistema\n");
				}

				break;
			case 2: //Modificacion
				if(cantidadDeDatos!=0)
				{
					printf("Ingrese un codigo de album: ");
					scanf("%d",&bajaIdpasajero);
					indiceBaja=RecorrerArrayBuscandoID(pasajeros, CANT, bajaIdpasajero);
					if(indiceBaja>=0)
					{
						/*Hacer submenu aca.
						o Título
						o Fecha de publicación
						o Importe*/
						opcionMenu=Menu("Seleccione la opcion a modificar: \n1)Nombre pasajero.\n2)Apellido Pasajero.\n3)Precio.\n4)Tipo de pasajero.\n5)Codigo de vuelo.\n");
						switch (opcionMenu) //Sub menu de modificacion
						{
						case 1:
							// PedirCadenaCaracteres nombre pasajero
							while (PedirCadenaCaracteres("Ingrese el nombre del pasajero: \n",pasajeros[indiceBaja].nombrePasajero,51)==-1)
							{
								PedirCadenaCaracteres("Ingrese el nombre del pasajero, sin superar los 51 caracteres: \n",pasajeros[indiceBaja].nombrePasajero,51);
							}
							break;
						case 2:
							//Apellido pasajero
							while (PedirCadenaCaracteres("Ingrese el apellido del pasajero: \n",pasajeros[indiceBaja].apellidoPasajero,51)==-1)
							{
								PedirCadenaCaracteres("Ingrese el apellido del pasajero, sin superar los 51 caracteres: \n",pasajeros[indiceBaja].apellidoPasajero,51);
							}
							break;
						case 3:
							//Importe
							pasajeros[indiceBaja].precio=PedirLongFloatMinimoMaximo("Ingrese un precio: ", 1,90000000);
							while(pasajeros[indiceBaja].precio==-1)
							{
								pasajeros[indiceBaja].precio=PedirLongFloatMinimoMaximo("Error, ingrese un precio entre 1 y 90000000: ", 1,90000000);
							}
							break;
						case 4:
							// IdTipoPasajero
							pasajeros[indiceBaja].idTipoPasajero=PedirEnteroMinimoMaximo("Ingrese tipo de pasajero: \n1)Clase economica\n2)Clase ejecutiva\n3)Primera clase\n", 1,3);
							while(pasajeros[indiceBaja].idTipoPasajero==-1)
							{
								pasajeros[indiceBaja].idTipoPasajero=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,3);
							}
							break;
						case 5:
							//CodigoVuelo
							while (PedirCadenaCaracteres("Ingrese el codigo del vuelo: \n",pasajeros[indiceBaja].codigoVuelo,10)==-1)
							{
								PedirCadenaCaracteres("Ingrese el codigo del vuelo, sin superar los 10 caracteres: \n",pasajeros[indiceBaja].codigoVuelo,10);
							}
							break;
						default: printf("No se ha seleccionado una opcion correcta.\n");
						break;
						}//Fin switch submenu modificar
					}//Fin de if indice buscado mayor o  igual a cero.
					else
					{
						printf("No se ha encontrado su codigo\n");
					}
				}//Fin de if de cantidad de datos mayor a cero
				else
				{
					printf("No hay datos cargados.\n");
				}
				break;
			case 3: //Baja

				break;
			case 4:
				break;
			case 6: //salir
				continuar='n';
				break;

			default: printf("No ha seleccionado una opcion correcta.\n");
			break;
			}//Fin de switch
		}while(continuar=='s');

	return 0;
}

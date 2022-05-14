/*
 * getTP2.h
 *
 *  Created on: 13 may. 2022
 *      Author: alanl
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int idTipoPasajero; //principal key
	char descripcionTipoPasajero[51];
}eTipoPasajero;

typedef struct
{
	int idPasajero; //principal key
	char nombrePasajero[51];
	char apellidoPasajero[51];
	float precio;
	char codigoVuelo[10];
	int idTipoPasajero;//Foranea
	int estadoVuelo;
	int isEmpty;


}ePasajero;



#ifndef GETTP2_H_
#define GETTP2_H_

int Menu(char menus[]);
int CargarEstadoEnCero(ePasajero pasajeros[], int size);
int RecorrerArrayBuscandoEmpy(ePasajero* pasajeros, int size);
ePasajero CargarPasajero(void);
////Validacion
int PedirCadenaCaracteres(char mensaje [],char cadena1[], int TAM);
int PedirEnteroMinimoMaximo(char mensaje[], int minimo,int maximo);
double PedirLongFloatMinimoMaximo(char mensaje[], double minimo,double maximo);
////Fin validacion
int RecorrerArrayBuscandoID(ePasajero* array, int size, int id);

#endif /* GETTP2_H_ */

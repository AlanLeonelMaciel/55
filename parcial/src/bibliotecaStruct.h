/*
 * bibliotecaStruct.h
 *
 *  Created on: 29 abr. 2022
 *      Author: alanl
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaValidaciones.h"
#define tam 5

typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;
typedef struct
{
	int idTipoAlbum;
	char descripcionTipoAlbum[52];
}eTipoAlbun;
typedef struct
{
	int idGenero; //principal key
	char descripcionGenero[52];

}eGenero;

typedef struct
{
	int idArtista; //principal key
	char nombreArtista[52];
}eArtista;

typedef struct
{
	int idTipoArtista; //principal key
	char descripcionTipoArtista[52];

}eTipoArtista;

typedef struct
{
	int idAlbum; //principal key
	char tituloAlbum[52];
	eFecha fechaPublicacion;
	double importe;
	int idArtista; //foranea
	int idGenero; //foranea
	int idTipoArtista;//foranea
	int idTipoAlbum;//foranea
	int estado;

}eAlbum;

#ifndef BIBLIOTECASTRUCT_H_
#define BIBLIOTECASTRUCT_H_

int CargarEstadoEnCero(eAlbum album[], int size);
int Menu(char menus[]);
int RecorrerArrayBuscandoEmpy(eAlbum* albun, int size);
eAlbum CargarAlbum(void);
int RecorrerArrayBuscandoID(eAlbum* array, int size, int id);
double RecorrerArraySumandoImporte(eAlbum* array, int size);
int RecorrerArrayBuscandoCantImporteMayorA(eAlbum* array, int size,double importe);
int RecorrerArrayFechaPublicacionAnteriorA(eAlbum* array, int size,int anio);
void ListarGenerosCargadosEnAlbum(eAlbum* arrayAlbum,eGenero* arrayGenero, int CANT,int sizeGenero);
void ListarTipoArtista(eTipoArtista* arrayTipoArtista,int size);
void ListarArtistas(eArtista* arrayArtista,int size);
int ListarAlbunes(eAlbum* arrayAlbum,int size,eArtista* arrayArtista, int sizeArtista,char mensaje[]);
int AlbunesOrdenadosPorPrecioYTitulo(eAlbum* arrayAlbum, int CANT);
void ImprimirAlbunesAntesDel2000(eAlbum* array, int size,eArtista* arrayArtista,int sizeArtista,int anio);
void ListarAlbunesSuperanPromedio (eAlbum* array, int size,eArtista* arrayArtista,int sizeArtista,int promedioImportes);
void ListarPorAnio(eAlbum* array, int size, char mensaje2[], int numero);
int ListarTipoAlbunes (eTipoAlbun* tipoAlbun ,int size,char mensaje[]);
int AlbunesNoSonVinilo (eAlbum* array, int size);
int AlbunesViniloDeUnArtista (eAlbum* array, int size, int idArtista);

#endif /* BIBLIOTECASTRUCT_H_ */

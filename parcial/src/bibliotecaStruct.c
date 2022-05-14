/*
 * bibliotecaParcial.c
 *
 *  Created on: 29 abr. 2022
 *      Author: alanl
 */
#include "bibliotecaStruct.h"

static int idIncremental = 2000;
static int obtenerIdAlbum();
static int obtenerIdAlbum() {
	return idIncremental++;
}

int CargarEstadoEnCero(eAlbum album[], int size)
{
	int i;
	int retorno=-1;
	if (album!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			album[i].estado=0;
		}
		retorno= 0;
	}
	return retorno;
}
int Menu(char menus[])
{
	int opcionMenu;
	printf("%s",menus);
	scanf("%d",&opcionMenu);
	return opcionMenu;
}
int RecorrerArrayBuscandoEmpy(eAlbum* albun, int size)
{
	int retorno=-1;
	int i;

	if(albun!=NULL&&size>0)
	{

		for(i=0;i<size;i++)
		{
			if (albun[i].estado==0)
			{
				return retorno=i;
				break;

			}
		}
	}
	return retorno;
}
eAlbum CargarAlbum(void)
{
	eAlbum album;

	album.idAlbum=obtenerIdAlbum();//Codigo album generico e incremental
	printf("Su codigo de album es: %d\n\n",album.idAlbum); //Muestro codigo Album generico
	// PedirCadenaCaracteres Titulo Album
	while (PedirCadenaCaracteres("Ingrese el titulo del album: \n",album.tituloAlbum,51)==-1)
	{
		PedirCadenaCaracteres("Ingrese el titulo del album, sin superar los 51 caracteres: \n",album.tituloAlbum,51);
	}
    // Fecha Dia
    album.fechaPublicacion.dia=PedirEnteroMinimoMaximo("Ingrese fecha de publicacion: \nDia: \t\n", 1,31);
	while(album.fechaPublicacion.dia==-1)
	{
		album.fechaPublicacion.dia=PedirEnteroMinimoMaximo("Error, ingrese un dia del 1 al 31\n", 1,31);
	}
	// Fecha mes
	album.fechaPublicacion.mes=PedirEnteroMinimoMaximo("Mes: \t\n", 1,12);
	while(album.fechaPublicacion.mes==-1)
	{
		album.fechaPublicacion.mes=PedirEnteroMinimoMaximo("Error, ingrese un mes del 1 al 12\n", 1,12);
	}
	// Fecha anio
	album.fechaPublicacion.anio=PedirEnteroMinimoMaximo("Anio: \t\n", 1500,2022);
	while(album.fechaPublicacion.anio==-1)
	{
		album.fechaPublicacion.anio=PedirEnteroMinimoMaximo("Error, ingrese un anio del 1500 al 2022\n", 1500,2022);
	}
	//Importe
	album.importe=PedirLongFloatMinimoMaximo("Ingrese un importe: ", 1,90000000);
	while(album.importe==-1)
	{
		album.importe=PedirLongFloatMinimoMaximo("Error, ingrese un importe entre 1 y 90000000: ", 1,90000000);
	}
	// IdArtista
	album.idArtista=PedirEnteroMinimoMaximo("Ingrese Artista: \n1)Christopher Anthony John\n2)Jon Bon Jovi\n3)Adele\n4)Dua Lipa\n5)Sandro\n", 1,5);
	while(album.idArtista==-1)
	{
		album.idArtista=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 5\n", 1,5);
	}
	//IdGenero
	album.idGenero=PedirEnteroMinimoMaximo("Ingrese un genero: \n1)Pop Rock\n2)Rock\n3)Jazz\n4)Pop\n5)Tango\n6)Balada Romantica\n7)Blues\n8)Soul\n", 1,8);
	while(album.idGenero==-1)
	{
		album.idGenero=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 8\n", 1,8);
	}
	//IdTipoArtista
	album.idTipoArtista=PedirEnteroMinimoMaximo("Ingrese tipo de artista: \n1)Solista\n2)banda\n", 1,2);
	while(album.idTipoArtista==-1)
	{
		album.idTipoArtista=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 2\n", 1,2);
	}
	//IDTipoAlbun
	album.idTipoAlbum=PedirEnteroMinimoMaximo("Ingrese tipo de album: \n1)Vinilo\n2)Cinta\n3)CD", 1,3);
	while(album.idTipoAlbum==-1)
	{
		album.idTipoAlbum=PedirEnteroMinimoMaximo("Error, ingrese una seleccion  del 1 al 3\n", 1,2);
	}
	album.estado=1;
	return album;

}
int RecorrerArrayBuscandoID(eAlbum* array, int size, int id)
{
	int retorno=-1;
	int i;

	if(array!=NULL&&size>0)
	{

		for(i=0;i<size;i++)
		{
			if (array[i].estado!=0&&array[i].idAlbum==id)
			{
				printf("Se encontro el siguiente album: %s\n",array[i].tituloAlbum);
				return i;
				break;

			}
		}
	}
	return retorno;
}
double RecorrerArraySumandoImporte(eAlbum* array, int size)
{
	double retorno=-1;
	int i;
	double sumaImporte=0;

	if(array!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if (array[i].estado!=0&&array[i].importe>0)
			{
				sumaImporte=sumaImporte+array[i].importe;
				retorno=sumaImporte;
			}
		}
	}
	return retorno;
}
int RecorrerArrayBuscandoCantImporteMayorA(eAlbum* array, int size,double importe)
{
	int retorno=-1;
	int i;
	int contadorImporte=0;

	if(array!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if (array[i].estado!=0&&array[i].importe>importe)
			{
				contadorImporte++;
				retorno=contadorImporte;
			}
		}
	}
	return retorno;
}
//B. Cantidad de álbumes cuya fecha de publicación es anterior a 1/1/2000.*/
int RecorrerArrayFechaPublicacionAnteriorA(eAlbum* array, int size,int anio)
{
	int retorno=-1;
	int i;
	int contador=0;

	if(array!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if (array[i].estado!=0&&array[i].fechaPublicacion.anio<anio)
			{
				contador++;
				retorno=contador;
			}
		}
	}
	return retorno;
}

void ListarGenerosCargadosEnAlbum(eAlbum* arrayAlbum,eGenero* arrayGenero, int CANT,int sizeGenero)
{
	printf("Generos cargados: \n");
	for(int i=0;i<CANT;i++)
	{
		for(int j=0;j<sizeGenero;j++)
		{
			if(arrayAlbum[i].idGenero==arrayGenero[j].idGenero)
			{
				printf("%s\n",arrayGenero[j].descripcionGenero);
				break;
			}
		}
	}
}
void ListarTipoArtista(eTipoArtista* arrayTipoArtista,int size)
{
	printf("Tipos de artistas: \n");
	for (int i=0;i<size;i++)
	{
		printf("\t%s\t\n",arrayTipoArtista[i].descripcionTipoArtista);
	}
}
void ListarArtistas(eArtista* arrayArtista,int size)
{
	printf("Artistas: \n");
	for (int i=0;i<size;i++)
	{
		printf("\t%s\t\n",arrayArtista[i].nombreArtista);
	}
}
int ListarAlbunes(eAlbum* arrayAlbum,int size,eArtista* arrayArtista, int sizeArtista,char mensaje[])
{
	int retorno=-1;
	printf("%s",mensaje);
	for(int j=0;j<sizeArtista;j++) //Recorro artista
	{
		for (int i=0;i<size;i++) //Recorro albunes
		{	if(arrayAlbum[i].estado!=0&&arrayAlbum[i].idArtista==arrayArtista[j].idArtista)
			{
				printf("\tTitulo: %s\tArtista: %s\n",arrayAlbum[i].tituloAlbum,arrayArtista[j].nombreArtista);
				retorno=0;
			}

		}
	}
	return retorno;
}
int AlbunesOrdenadosPorPrecioYTitulo(eAlbum* arrayAlbum, int CANT)
{
	eAlbum auxiliar2;
	int retorno=-1;
	eAlbum auxiliar;



	if(arrayAlbum!=NULL&&CANT>0)
	{
		for(int i=0;i<CANT-1;i++)
			{
				for(int j=i+1;j<CANT;j++)
				{
					if(arrayAlbum[i].importe>arrayAlbum[j].importe)
					{
						auxiliar=arrayAlbum[i];
						arrayAlbum[i]=arrayAlbum[j];
						arrayAlbum[j]=auxiliar;
						retorno=0;
					}
					else
					{
						if(arrayAlbum[i].importe==arrayAlbum[j].importe)
						{
							if(strcmp(arrayAlbum[i].tituloAlbum,arrayAlbum[j].tituloAlbum)>0)
							{
								auxiliar2=arrayAlbum[i];
								arrayAlbum[i]=arrayAlbum[j];
								arrayAlbum[j]=auxiliar2;
							}
						}
					}
				}
			}
		printf("Albumes ordenados por precio y titulo: \n");
		for (int i=0;i<CANT;i++)
		{
			if(arrayAlbum[i].estado!=0)
			{
				printf("\tImporte: %.2lf\tTitulo: %s\t\n",arrayAlbum[i].importe,arrayAlbum[i].tituloAlbum);
			}

		}
	}

	return retorno;
}
void ImprimirAlbunesAntesDel2000(eAlbum* array, int size,eArtista* arrayArtista,int sizeArtista,int anio)
{
	int i;
	int condicion;
	eAlbum aux[size];
	CargarEstadoEnCero(aux,size);

	if(array!=NULL&&size>0)
	{
		for(i=0;i<size;i++)
		{
			if (array[i].estado!=0&&array[i].fechaPublicacion.anio<anio)
			{
				aux[i]=array[i];

			}
		}

		condicion=ListarAlbunes(aux,size,arrayArtista,sizeArtista,"Albumes antes del 2000: \n");
		if(condicion==-1)
		{
			printf("No se ha podido realizar la tarea.");
		}
	}

}
void ListarAlbunesSuperanPromedio (eAlbum* array, int size,eArtista* arrayArtista,int sizeArtista,int promedioImportes)
{
	eAlbum aux[size];
	CargarEstadoEnCero(aux,size);
	if(array!=NULL&&size>0)
	{
		for(int i=0;i<size;i++)
		{
			if(array[i].estado!=0&&array[i].importe>promedioImportes)
			{
				aux[i]=array[i];

			}
		}
		ListarAlbunes(aux,size,arrayArtista,sizeArtista,"Albumes que superan el promedio: \n");
	}
}

void ListarPorAnio(eAlbum* array, int size, char mensaje2[], int numero)
{
	printf("%s",mensaje2);
	for(int j=0;j<size;j++) //Recorro album
	{
		if(numero==array[j].fechaPublicacion.anio&&array[j].estado!=0)
		{
			printf("\tTitulo: %s\tAnio: %d\n",array[j].tituloAlbum,array[j].fechaPublicacion.anio);

		}

	}
}
int ListarTipoAlbunes (eTipoAlbun* tipoAlbun ,int size,char mensaje[])
{
	int retorno=-1;
	printf("%s",mensaje);

	for (int i=0;i<size;i++) //Recorro tipo albun
	{

		printf("\t%d %s\n",i+1,tipoAlbun[i].descripcionTipoAlbum);
		retorno=0;



	}
	return retorno;
}
int AlbunesNoSonVinilo (eAlbum* array, int size)
{
	int retorno= -1;
	int j;

	eAlbum aux[size];
	CargarEstadoEnCero(aux,size);

	if(array!=NULL&&size>0)
	{
		for(j=0;j<size;j++)
		{
			if(array[j].idTipoAlbum!=1&&array[j].estado!=0)
			{
					printf("%s\n",array[j].tituloAlbum);
					retorno=0;
			}
		}
	}
	return retorno;

}
int AlbunesViniloDeUnArtista (eAlbum* array, int size, int idArtista)
{
	int retorno=-1;

	int j;

	eAlbum aux[size];
	CargarEstadoEnCero(aux,size);

	if(array!=NULL&&size>0)
	{
		for(j=0;j<size;j++)
		{
			if(array[j].idTipoAlbum==1&&array[j].estado!=0&&idArtista==array[j].idArtista)
			{
					printf("%s\n",array[j].tituloAlbum);
					retorno=0;
			}
		}
	}
	return retorno;

}

/*
 ============================================================================
 Name        : Alan Leonel Maciel 1er Parcial
 Description : Desarrollar en ANSI C:
  A LO REALIZADO AGREGAR:
 La entidad Tipo de Album, la misma contendrá:
 Campos: id y descripción.
 Datos: 1, vinilo; 2, cinta; 3, CD.
 Listar todos los tipos de álbumes. // YA ESTA
 Agregar el Tipo de álbum al Alta y Modificación de álbumes.//YA ESTA
 Listar todos los albumes que no sean de vinilo.
 Listar todos los albumes de vinilo que correspondan a un artista determinado.*/
 //============================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecaStruct.h"
#include "bibliotecaValidaciones.h"
#define CANT 2

int main(void)
{
	char continuar='s';
	int opcionMenu;
	int cantidadDeDatos=0;
	int bajaIdAlbum;
	int indiceBaja;
	double sumaImporte;
	double promedioImportes;
	int albumesSuperandoPromedio;
	int cantidadAlbunesAntes2000;
	int anio;
	int opcion;
	int idArtistaAux;
	eAlbum aux3;


	setbuf(stdout,0);

	eArtista artistas[5]=
	{
			{1,"Christopher Anthony John"},
			{2,"Jon Bon Jovi"},
			{3,"Adele"},
			{4,"Dua Lipa"},
			{5,"Sandro"}
	};
	eTipoArtista tiposDeArtistas[2]=
	{
			{1,"Solista"},
			{2,"Banda"}
	};
	eGenero generos[8]=
	{
			{1,"Pop Rock"},
			{2,"Rock"},
			{3,"Jazz"},
			{4,"Pop"},
			{5,"Tango"},
			{6,"Balada Romantica"},
			{7,"Blues"},
			{8,"Soul"}
	};
	eTipoAlbun tiposDeAlbunes[3]=
	{
			{1,"Vinilo"},
			{2,"Cinta"},
			{3,"Cd"}
	};
	eAlbum albunes[CANT]; //Mi vector de albunes
	//Cargar estado de album en cero
	CargarEstadoEnCero(albunes,CANT);
	//comienzo do While
	do
	{
		opcionMenu=Menu("1) Alta\n2) Modificar\n3) Baja\n4) Informar\n5) Listar\n6) Salir\n"); // El menu
		switch(opcionMenu)
		{
		case 1: //Alta
			if(RecorrerArrayBuscandoEmpy(albunes, CANT)>=0)
			{
				albunes[RecorrerArrayBuscandoEmpy(albunes, CANT)]=CargarAlbum();
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
				scanf("%d",&bajaIdAlbum);
				indiceBaja=RecorrerArrayBuscandoID(albunes, CANT, bajaIdAlbum);
				if(indiceBaja>=0)
				{
					/*Hacer submenu aca.
					o Título
					o Fecha de publicación
					o Importe*/
					opcionMenu=Menu("Seleccione la opcion a modificar: \n1)Titulo.\n2)Fecha de publicacion.\n3)Importe.\n4)Tipo de album.\n");
					switch (opcionMenu) //Sub menu de modificacion
					{
					case 1:
						// PedirCadenaCaracteres Titulo Album
						while (PedirCadenaCaracteres("Ingrese el titulo del album: \n",albunes[indiceBaja].tituloAlbum,51)==-1)
						{
							PedirCadenaCaracteres("Ingrese el titulo del album, sin superar los 51 caracteres: \n",albunes[indiceBaja].tituloAlbum,51);
						}
						break;
					case 2:
					    // Fecha Dia
						albunes[indiceBaja].fechaPublicacion.dia=PedirEnteroMinimoMaximo("Ingrese fecha de publicacion: \nDia: \t\n", 1,31);
						while(albunes[indiceBaja].fechaPublicacion.dia==-1)
						{
							albunes[indiceBaja].fechaPublicacion.dia=PedirEnteroMinimoMaximo("Error, ingrese un dia del 1 al 31\n", 1,31);
						}
						// Fecha mes
						albunes[indiceBaja].fechaPublicacion.mes=PedirEnteroMinimoMaximo("Mes: \t\n", 1,12);
						while(albunes[indiceBaja].fechaPublicacion.mes==-1)
						{
							albunes[indiceBaja].fechaPublicacion.mes=PedirEnteroMinimoMaximo("Error, ingrese un mes del 1 al 12\n", 1,12);
						}
						// Fecha anio
						albunes[indiceBaja].fechaPublicacion.anio=PedirEnteroMinimoMaximo("Anio: \t\n", 1500,2022);
						while(albunes[indiceBaja].fechaPublicacion.anio==-1)
						{
							albunes[indiceBaja].fechaPublicacion.anio=PedirEnteroMinimoMaximo("Error, ingrese un anio del 1500 al 2022\n", 1500,2022);
						}
						break;
					case 3:
						//Importe
						albunes[indiceBaja].importe=PedirLongFloatMinimoMaximo("Ingrese un importe: ", 1,90000000);
						while(albunes[indiceBaja].importe==-1)
						{
							albunes[indiceBaja].importe=PedirLongFloatMinimoMaximo("Error, ingrese un importe entre 1 y 90000000: ", 1,90000000);
						}
						break;
					case 4:
						//Tipo albun
						albunes[indiceBaja].idTipoAlbum=PedirEnteroMinimoMaximo("Ingrese tipo de album: \n1)Vinilo\n2)Cinta\n3)CD", 1,3);
						while(albunes[indiceBaja].idTipoAlbum==-1)
						{
							albunes[indiceBaja].idTipoAlbum=PedirEnteroMinimoMaximo("Ingrese tipo de album: \n1)Vinilo\n2)Cinta\n3)CD", 1,3);
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
			if(cantidadDeDatos!=0)
			{
				printf("Ingrese un codigo de album: ");
				scanf("%d",&bajaIdAlbum);
				indiceBaja=RecorrerArrayBuscandoID(albunes, CANT, bajaIdAlbum);
				if(indiceBaja>=0)
				{
					albunes[indiceBaja].estado=0;
					printf("Su album ha sido eliminado.\n");
					cantidadDeDatos--;
				}
				else
				{
					printf("No se ha encontrado su codigo\n");
				}
			}
			else
			{
				printf("No hay datos cargados.\n");
			}
			break;
		case 4: /*INFORMAR:
			A. Total y promedio de los importes, y cuántos álbumes superan ese promedio.
			B. Cantidad de álbumes cuya fecha de publicación es anterior a 1/1/2000.*/

			if(cantidadDeDatos!=0)
			{
				//submenu informar
				opcionMenu=Menu("Seleccione la opcion a informar: \n1. Total y promedio de los importes, y cuántos álbumes superan ese promedio.\n2. Cantidad de álbumes cuya fecha de publicación es anterior a 1/1/2000.");
				switch(opcionMenu)
				{
				case 1:
					sumaImporte=RecorrerArraySumandoImporte(albunes, CANT);
					promedioImportes=sumaImporte/cantidadDeDatos;
					albumesSuperandoPromedio=RecorrerArrayBuscandoCantImporteMayorA(albunes, CANT,promedioImportes);
					printf("Total importes: %.2lf\tPromedio de importes: %.2lf\tCantidad de albunes que superan ese promedio: %d\n",sumaImporte,promedioImportes,albumesSuperandoPromedio);
					break;
				case 2:
					cantidadAlbunesAntes2000=RecorrerArrayFechaPublicacionAnteriorA(albunes, CANT,2000);
					printf("Cantidad de álbumes cuya fecha de publicación es anterior a 1/1/2000: %d\n",cantidadAlbunesAntes2000);
					break;
				default: printf("No ha seleccionado una opcion correcta.\n");
				break;
				}//Fin switch de sub menu informar

			}//Fin de if cantidad de datos mayor a 0
			else
			{
				printf("No hay datos cargados.\n");
			}
			break;
		case 5: /*Listar LISTAR:
			A. Todos los géneros.



			E. Realizar un solo listado de los álbumes ordenados por los siguientes criterios: \n
			o
			o





			*/
			if(cantidadDeDatos!=0)
			{
				opcion=Menu("Seleccione opcion: \n1. Todos los géneros.\n2. Todos los tipos de artistas musicales.\n3. Todos los artistas.\n4. Todos los álbumes.\n5. Realizar un solo listado de los álbumes ordenados por los siguientes criterios: \nImporte (descendentemente\nTítulo (ascendentemente)\n6. Todos los álbumes cuya fecha de publicación es anterior a 1/1/2000.\n7. Todos los álbumes que superan el promedio de los importes.\n8. Todos los álbumes de cada artista.\n9. Todos los álbumes de un año determinado.\n10. El álbum o los álbumes más caros.\n11. Listar todos los tipos de albumes.\n12. Todos los albumes que no sean de vinilo.\n13.Todos los albumes de vinilo que correspondan a un artista determinado. ");
				switch(opcion)
				{
				case 1:
					ListarGenerosCargadosEnAlbum(albunes,generos,CANT,8);//A
					break;
				case 2:
					ListarTipoArtista(tiposDeArtistas,2); //B
					break;
				case 3:
					ListarArtistas(artistas,5);//C
					break;
				case 4:
					ListarAlbunes(albunes,CANT,artistas,5,"Todos los albumes: \n");//D
					break;
				case 5:
					AlbunesOrdenadosPorPrecioYTitulo(albunes,CANT);//E
					break;
				case 6:
					ImprimirAlbunesAntesDel2000(albunes, CANT,artistas,5,2000);//F
					break;
				case 7:
					sumaImporte=RecorrerArraySumandoImporte(albunes, CANT);
					promedioImportes=sumaImporte/cantidadDeDatos;
					ListarAlbunesSuperanPromedio (albunes, CANT,artistas,5,promedioImportes);//G
					break;
				case 8:
					ListarAlbunes(albunes,CANT,artistas,5,"Todos los albumes y sus artistas: \n");//H
					anio=Menu("Seleccione año a listar: \n");
					while(anio>2022||anio<1500)
					{
						anio=Menu("Error, eleccione año a listar entre 1500 y 2022: \n");
					}
					break;
				case 9:
					ListarPorAnio(albunes, CANT, "Listado albumes por año seleccionado: \n", anio);//I
					break;
				case 10:

					for(int i=0;i<CANT;i++)
					{
						if((i==0&&albunes[i].estado!=0)||albunes[i].importe>aux3.importe)
						{
							aux3.importe=albunes[i].importe;
							printf("El album mas caro es %s",albunes[i].tituloAlbum);
						}
					}

					break;
				case 11:
					ListarTipoAlbunes (tiposDeAlbunes,3,"Los tipos de albumes son: \n");
					break;
				case 12:
					//todos los albumes que no sean de vinilo.
					printf("Albumes que no son vinilo: \n");
					AlbunesNoSonVinilo (albunes, CANT);

					break;
				case 13:
					idArtistaAux=Menu("Seleccione artista:\n1)Christopher Anthony John\n2)Jon Bon Jovi\n3)Adele\n4)Dua Lipa\n5)Sandro  \n");
					while(idArtistaAux>5||idArtistaAux<1)
					{
						idArtistaAux=Menu("Error, eleccione artista \n");
					}
					//todos los albumes de vinilo que correspondan a un artista determinado.
					printf("Albumes del artista: \n");
					AlbunesViniloDeUnArtista (albunes,CANT,idArtistaAux);

					break;
				default: printf("No ha seleccionado opcion correcta");
				}

			}//Fin if cantidad de datos
			else
			{
				printf("No hay datos cargados.\n");
			}
			break;
		case 6: //salir
			continuar='n';
			break;

		default: printf("No ha seleccionado una opcion correcta.\n");
		break;
		}//Fin de switch
	}while(continuar=='s');

	return 0;
} //Fin Main

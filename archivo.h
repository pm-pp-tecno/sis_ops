#ifndef ARCHIVO_H
#define ARCHIVO_H



#include <stdio.h>
#include <stdbool.h>



typedef struct archivo* Archivo;

typedef struct lista_archivos* Lista_archivos;



FILE *abro_archivo(Archivo a);


//char *leo_linea(int n);




Archivo CrearArchivo();

Archivo LeerArchivo();


Lista_archivos CrearListaArchivos();


bool IsEmptyListaArchivos(Lista_archivos lista_arch);


Lista_archivos Ultimo(Lista_archivos lista_arch);


Lista_archivos Primero(Lista_archivos lista_arch);



Lista_archivos InsertarArchivoListaArchivos(Lista_archivos lista_arch, char *nom_archivo);
// Inserta un nombre de archivo como ultimo en lista de archivos
// Actualizar puntero a ultimo. Ver tamaño, etc.



Lista_archivos EliminarArchivoListaArchivos(Lista_archivos lista_arch, char *nom_archivo);
// Elimina un nombre de archivo de la lista de archivos
// Actualizar punteros. Ver tamaño, etc.




#endif // ARCHIVO_H
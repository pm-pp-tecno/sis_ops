/***
 * 
 * Sis Ops - File System
 * 
 */


//#include "cargo.h"
#include "archivo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <cstdio>

#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>


struct archivo{
	char * nombreArch;
};




struct lista_archivos{
	Archivo nombreArch;
	Lista_archivos sig;
	Lista_archivos ant;
};






FILE *abro_archivo(Archivo a){
    FILE *fp;
    char *line = NULL;
    fp = fopen(a->nombreArch, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    return fp;
}

/*
char *leo_linea(int n){
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int cont=0;

    while (cont < n){
       //if ((read = getline(&line, &len, fp)) != -1) {
            cont++;
        //}
    } 
    return line;
}
*/



Archivo CrearArchivo(){
// Genera una lista de archivos vacia
    return NULL;
}



Archivo LeerArchivo(){
// Genera una lista de archivos vacia
    //Archivo a = new(archivo);
    //a->nombreArch = "datos.txt";

    //FILE *fp;
    //fp = abro_archivo(Archivo a);


}



Lista_archivos CrearListaArchivos(){
// Genera una lista de archivos vacia
    return NULL;
}


bool IsEmptyListaArchivos(Lista_archivos lista_arch){
// Indica si la lista esta vacia
    return (lista_arch == NULL);
}



Lista_archivos Ultimo(Lista_archivos lista_arch){
// 
    return lista_arch;
}



Lista_archivos Primero(Lista_archivos lista_arch){
// 
    return lista_arch;
}



Lista_archivos InsertarArchivoListaArchivos(Lista_archivos lista_arch, char *nom_archivo){
// Inserta un nombre de archivo como ultimo en lista de archivos
// Actualizar puntero a ultimo. Ver tamaño, etc.

    return lista_arch;

}


Lista_archivos EliminarArchivoListaArchivos(Lista_archivos lista_arch, char *nom_archivo){
// Elimina un nombre de archivo de la lista de archivos
// Actualizar punteros. Ver tamaño, etc.

    return lista_arch;
}


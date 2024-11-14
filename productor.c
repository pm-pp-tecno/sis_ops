/***
 * 
 * Sis Ops - File System
 * 
 */

#define MAX_SCRIPTS 10

#include "archivo.h"
#include "script.h"
#include "buffer.h"

#include "productor.h"
#include "consumidor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// semaforos
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/ipc.h>



using namespace std;


struct productor{
	Buffer buffer; // Ver si es 1 buffer o una lista. Puntero al 1er elemento? y al ultimo?
    Buffer ultimoBuffer;
	//Script productor; // Array circular con los scripts a colocar en buffer de memoria compartida
	//Lista_archivos archivos; // Para ver si hay archivos por leer? En un principio manual: archivo1.txt, archivo2.txt.
	Lista_scripts listaScripts; // Array circular con los scripts a colocar en buffer de memoria compartida
    //bool dormido;
};



/*

void productor(TIPO args){


    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int nro_lin = 1;
    fp = abro_archivo();
    if (fp == NULL)
        exit(EXIT_FAILURE);
    line = leo_linea(nro_lin);
    while (strcmp(line,".")) {
        printf("%s\n", line);
        line = leo_linea(nro_lin);
        // asigno a script->linea
        // muevo puntero a script->sig
    }

    // Asigno esos scripts a array buffer
    // Le hago sem_post a los consumidores para que sepan que hay mas scripts.
    // Chequeo que el valor de productor no sea mayor a consumidores
    // Si es igual entonces el productor se duerme.

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);




    const int SIZE = 4096;

    int shm_fd,pid,i;
    int *ptr;

    // create the shared memory segment
    shm_fd = shm_open("name", O_CREAT | O_RDWR, 0666);

    // configure the size of the shared memory segment
    ftruncate(shm_fd,SIZE);

    // coloco buffer en memoria compartida

}

*/



Productor CrearProductor(){
    Buffer buffer = CrearBuffer();
    Buffer ultimoBuffer = buffer;
    Lista_scripts listaScripts = CrearListaScripts();

    Productor nuevo_productor = new(productor);
    nuevo_productor->buffer = buffer;
    nuevo_productor->ultimoBuffer = ultimoBuffer;
    nuevo_productor->listaScripts = listaScripts;

    return nuevo_productor;
}



void ActualizarBufferProductor(Productor &prod, Lista_scripts listado_scripts){
// Actualiza el buffer de memoria compartida
	//printf("Productor: %s\n", fechaHora);
    printf("Actualizando Buffer - Productor.\n");
    int contador = 0;
    
    int shm_fd;
	int *ptr;
	int p;
    
    /*
	sem_t *sem_prod;
	sem_prod = sem_open("sem_prod.txt", O_CREAT, 644, 1);

    //sem_wait(sem_prod);

	sem_t *sem_cons;
	sem_cons = sem_open("sem_cons.txt", O_CREAT, 644, 0);

    sem_wait(sem_cons);
    */
    // Inserta MAX_SCRIPTS (10) scripts en array buffer en memoria compartida
    while (listado_scripts != NULL && contador < MAX_SCRIPTS){
        // prod->buffer
        //ColocarScriptsBuffer(prod->buffer, s);
        contador++;
    }


}

void IsEmptyProductor();

void Ultimo();


// Creo qeu quedo obselta con InsertarScriptBuffer(Buffer prod->buffer, Script s) en buffer.c
bool ColocarScripts(Lista_scripts lista);
// Coloca los scripts de lista en buffer circular array
// Llama a funcion ColocarScriptsBuffer(Lista_scripts lista) de Buffer.c
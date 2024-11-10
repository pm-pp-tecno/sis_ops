/***
 * 
 * Sis Ops - File System
 * 
 */

#include "archivo.h"
#include "scripts.h"
#include "buffer.h"

#include "consumidor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

typedef struct productor{
	buffer * buffer; // Ver si es 1 buffer o una lista. Puntero al 1er elemento? y al ultimo?
	script * productor; // Array circular con los scripts a colocar en buffer de memoria compartida
	lista_archivos * archivos; // Para ver si hay archivos por leer? En un principio manual: archivo1.txt, archivo2.txt.
    int tam;
    bool dormido;
} productor;





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

    /* create the shared memory segment */
    shm_fd = shm_open("name", O_CREAT | O_RDWR, 0666);

    /* configure the size of the shared memory segment */
    ftruncate(shm_fd,SIZE);

    // coloco buffer en memoria compartida

}
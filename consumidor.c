/***
 * 
 * Sis Ops - File System
 * 
 */

#define MAX_LECTURA 5

#include "archivo.h"
#include "script.h"
#include "buffer.h"

#include "productor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


using namespace std;

struct consumidor{
	Buffer buffer; 
    Buffer ultimoBuffer; 
	//Lista_archivos archivos; // Para ver si hay archivos por leer? En un principio manual: archivo1.txt, archivo2.txt.
	Lista_scripts listaScripts; 
};



void CrearConsumidor(){

    // duerme hasta que productor lo despierte con mas scripts
    // cuando hay scripts los lee del buffer circular de memoria compartida
    // hago exec de cada linea del script
    // envio los resultados a un archivo de log
    // cada archivo de log se nombra con el identificador del proceso y hora de ejecucion.
    // cuando no hay mas scripts para leer (consumidor == productor - 1)
    // se hecha a dormir.



}

/*
Productor CrearProductor(Lista_scripts listado_scripts){
    Buffer buffer = CrearBuffer();
    Buffer ultimoBuffer = buffer;
    Lista_scripts listaScripts = AsignarListaScripts(listado_scripts);

    Productor nuevo_productor = new(productor);
    nuevo_productor->buffer = buffer;
    nuevo_productor->ultimoBuffer = ultimoBuffer;
    nuevo_productor->listaScripts = listaScripts;

    return nuevo_productor;
}
*/

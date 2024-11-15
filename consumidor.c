/***
 * 
 * Sis Ops - File System
 * 
 */

#include "consumidor.h"
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
	Buffer buffer; // Ver si es 1 buffer o una lista. Puntero al 1er elemento? y al ultimo?
	//Script consumidor; // Array circular con los scripts a colocar en buffer de memoria compartida
	//Lista_archivos lista_ejecutar; // 
    int proximo; // proximo lugar del array que ingresa el consumidor
    //bool dormido; semaforo
};



Consumidor CrearConsumidor(Buffer buffer){

    // duerme hasta que productor lo despierte con mas scripts
    // cuando hay scripts los lee del buffer circular de memoria compartida
    // hago exec de cada linea del script
    // envio los resultados a un archivo de log
    // cada archivo de log se nombra con el identificador del proceso y hora de ejecucion.
    // cuando no hay mas scripts para leer (consumidor == productor - 1)
    // se hecha a dormir.
    Consumidor nuevo_consumidor = new(consumidor);
    nuevo_consumidor->buffer = buffer;
    nuevo_consumidor->proximo = 0;
    return nuevo_consumidor;
}

int ObtenerProximo(Consumidor c){
    return c->proximo;
}

void ActualizarProximo(Consumidor c, int nuevoProximo){
    c->proximo = nuevoProximo;
}
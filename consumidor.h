#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void consumidor(TIPO args){

    // duerme hasta que productor lo despierte con mas scripts
    // cuando hay scripts los lee del buffer circular de memoria compartida
    // hago exec de cada linea del script
    // envio los resultados a un archivo de log
    // cada archivo de log se nombra con el identificador del proceso y hora de ejecucion.
    // cuando no hay mas scripts para leer (consumidor == productor - 1)
    // se hecha a dormir.

}



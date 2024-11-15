#ifndef PRODUCTOR_H
#define PRODUCTOR_H



#include "obli.h"
#include "archivo.h"
#include "script.h"
#include "buffer.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct productor* Productor;


Productor CrearProductor(Buffer buffer, Lista_scripts lista_scripts);

void ActualizarBufferProductor(Productor &prod);

void IsEmptyProductor();

void Ultimo();


bool ColocarScripts(Lista_scripts lista);

#endif // PRODUCTOR_H
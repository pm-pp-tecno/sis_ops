#ifndef PRODUCTOR_H
#define PRODUCTOR_H



#include "archivo.h"
#include "script.h"
#include "buffer.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct productor* Productor;





Productor CrearProductor(Lista_scripts listado_scripts);

void ActualizarBufferProductor(Productor &prod);

void IsEmptyProductor();

void Ultimo();


bool ColocarScripts(Lista_scripts lista);

#endif // PRODUCTOR_H
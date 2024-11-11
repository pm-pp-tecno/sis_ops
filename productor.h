#ifndef PRODUCTOR_H
#define PRODUCTOR_H



#include "archivo.h"
#include "script.h"
#include "buffer.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct productor* Productor;





Productor CrearProductor();

void ActualizarBufferProductor();

void IsEmptyProductor();

void Ultimo();




#endif // PRODUCTOR_H
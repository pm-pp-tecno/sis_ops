#ifndef CONSUMIDOR_H
#define CONSUMIDOR_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

typedef struct consumidor* Consumidor;


Consumidor CrearConsumidor(Buffer buffer);




#endif // CONSUMIDOR_H
#ifndef BUFFER_H
#define BUFFER_H


#include "archivo.h"
#include "script.h"


typedef struct buffer* Buffer;

Buffer CrearBuffer();

int ColocarScriptsBuffer(Lista_scripts lista);

int LeerScriptsBuffer(int desde, int hasta);



#endif // BUFFER_H

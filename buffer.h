#ifndef BUFFER_H
#define BUFFER_H


#include "obli.h"
#include "archivo.h"
#include "script.h"


typedef struct buffer* Buffer;

Buffer CrearBuffer();

int ColocarScriptsBuffer(Buffer buffer, Script script);

int LeerScriptsBuffer(Buffer buffer, int desde, int hasta);

int ObtenerTamBuffer(Buffer buffer);

void ActualizarTamBuffer(Buffer buffer, int nuevoTam);

#endif // BUFFER_H

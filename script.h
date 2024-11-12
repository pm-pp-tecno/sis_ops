#ifndef SCRIPT_H
#define SCRIPT_H


#include "archivo.h"

typedef struct script* Script;

typedef struct lista_scripts* Lista_scripts;


Lista_scripts ArmarListaScripts();

Script InsertarScript (Lista_scripts lista, Script s);

Script ObtenerScript(Lista_scripts lista);

char *ObtenerLinea(Script s);

Lista_scripts Tail(Lista_scripts lista);

bool IsEmpty(Lista_scripts lista);

#endif // SCRIPT_H
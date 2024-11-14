#ifndef SCRIPT_H
#define SCRIPT_H


#include "archivo.h"

typedef struct script* Script;

typedef struct lista_scripts* Lista_scripts;


void ImprimirScript(Script script);

char *ObtenerLinea(Script s);

Script InsertarScript (Lista_scripts lista, Script s);

Script ObtenerScript(Lista_scripts lista);

Script Head(Lista_scripts lista);

Lista_scripts Tail(Lista_scripts lista);

bool IsEmpty(Lista_scripts lista);

Lista_scripts CrearListaScripts(Lista_scripts listado_scripts);

Lista_scripts AsignarListaScripts(Lista_scripts listado_scripts);

Lista_scripts ArmarListaScripts();

#endif // SCRIPT_H
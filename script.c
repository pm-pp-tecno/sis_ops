/***
 * 
 * Sis Ops - File System
 * 
 */

#include "archivo.h"
#include "script.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 1 Script = 1 linea ejecutable de codigo
struct script{
	char * linea;
};


// 1 lista de lineas ejecutables de codigo
struct lista_scripts{
	Script script;
    Lista_scripts sig;
    Lista_scripts ant;
};



Script InsertarScript (Lista_scripts lista, Script s){

}



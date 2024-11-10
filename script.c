/***
 * 
 * Sis Ops - File System
 * 
 */

#include "archivo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 1 Script = 1 linea ejecutable de codigo
typedef struct script{
	char * linea;
} script;


// 1 lista de lineas ejecutables de codigo
typedef struct lista_scripts{
	script * linea;
    lista_scripts * sig;
    lista_scripts * ant;
} script;



script InsertarScript (lista_scripts lista, script s){

}



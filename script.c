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
	char linea[256];
};


// 1 lista de lineas ejecutables de codigo
struct lista_scripts{
	Script script;
    Lista_scripts sig;
    Lista_scripts ant;
};



Lista_scripts CrearListaScripts(){
    Lista_scripts listaScripts = new(lista_scripts);
    return listaScripts;
}

/*
FILE *fp;
FILE *abro_archivo(Archivo a)
*/

Lista_scripts ArmarListaScripts(){
    char nom_arch[256], str_inodo[8], tipo_arch[2];
    int nro_inodo, cont = 0;
    //Script script;
    Lista_scripts listado_scripts = NULL, auxListado = NULL;

    FILE *f=fopen("./datos.txt","r");
    if (f==NULL){
        fprintf(stderr, "Error de archivo\n");
        exit(0);
    }

    //Archivo a = CrearArchivo();
    //a->nombreArch = "datos.txt";
    //strcpy(a->nombreArch, "datos.txt");
    
    
    //Archivo a = LeerArchivo();
    //FILE *f = abro_archivo(a);



    //printf("Hola1\n");
    while (!feof(f)){
        fscanf(f,"%*s %[^\n]", nom_arch);
        if (nom_arch != NULL && strcmp(nom_arch, "//----------------------------------------") != 0){
            //fprintf(stdout,"Archivo: %s inodo %d\n",nom_arch,nro_inodo);
            Script auxS = new(script);
            //auxS.linea = nom_arch;
            strcpy(auxS->linea, nom_arch);
            //fprintf(stdout,"%s\n",auxS->linea);
            Lista_scripts auxListado = new(lista_scripts);
            auxListado->script = auxS;
            auxListado->sig = listado_scripts;
            auxListado->ant = NULL;
            listado_scripts = auxListado;
            fprintf(stdout,"%s\n",auxListado->script->linea);
        } /* else {
            fclose(f);
        } */
    }
    fclose(f);

    printf("Hola!!!\n");

    return listado_scripts;

}







Script InsertarScript(Lista_scripts lista, Script s){
    return s;
}



Script ObtenerScript(Lista_scripts lista){
    Script s = lista->script;
    return s;
}


char *ObtenerLinea(Script s){
    //Script s = lista->script;
    return s->linea;
}



Lista_scripts Tail(Lista_scripts lista){
    if (lista != NULL)
        return lista->sig;
    else 
        return NULL;
}

Script Head(Lista_scripts lista){
    Lista_scripts iter = lista;
    while (iter->ant != NULL){
        iter = iter->ant;
    }
    return iter->script;
}

bool IsEmpty(Lista_scripts lista){
    return lista == NULL;
}



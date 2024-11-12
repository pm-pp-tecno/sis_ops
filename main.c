/***
 * 
 * Sis Ops - File System
 * 
 */

#include "script.h"
#include "productor.h"
#include "consumidor.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include  <wait.h>


using namespace std;

typedef struct fabrica{
	Productor productor;
	Consumidor consumidor;
} Fabrica;





int main(){

    // numero del array del buffer en el que se encuentra cada proceso?
    int productor, consumidores;
    //Fabrica fabrica;

/*
    while (productor < consumidores){
        productor(args);
        consumidor;
    
    }

    
*/

    Lista_scripts listado_scripts;

    listado_scripts = ArmarListaScripts();



    Lista_scripts iter = listado_scripts;
    int cont = 0;

    while (!IsEmpty(iter)) {
        Script auxiS = ObtenerScript(iter);
        printf("Contador: %d: ", cont);
        fprintf(stdout,"%s\n",ObtenerLinea(auxiS));
        iter = Tail(iter);
        cont++;
    }


    return 0;

}


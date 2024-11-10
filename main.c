/***
 * 
 * Sis Ops - File System
 * 
 */

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
	productor * productor;
	consumidor * consumidor;
} fabrica;





int main(){

    // numero del array del buffer en el que se encuentra cada proceso?
    int productor, consumidores;
    Fabrica fabrica;

/*
    while (productor < consumidores){
        productor(args);
        consumidor;
    
    }

    
*/



}


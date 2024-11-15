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
#include <semaphore.h>

using namespace std;

/*
// Fabrica fue!!!
typedef struct fabrica{
	Productor productor;
	Consumidor consumidor;
	Buffer buffer;
} Fabrica;
*/




int main(){

    // numero del array del buffer en el que se encuentra cada proceso?
    // int productor, consumidores;
    //Fabrica fabrica;

/*
    while (productor < consumidores){
        productor(args);
        consumidor;
    
    }

*/
/*
    sem_t * sem_produce = sem_open("sem_produce", O_CREAT, 0644, 1);
    sem_t * sem_consume = sem_open("sem_consume", O_CREAT, 0644, 0);
*/

	sem_t *sem_prod = sem_open("sem_prod.txt", O_CREAT, 644, 1);
	sem_t *sem_cons = sem_open("sem_cons.txt", O_CREAT, 644, 0);
    
    Buffer buffer = CrearBuffer();

    Lista_scripts listado_scripts = ArmarListaScripts();
    Productor prod = CrearProductor(buffer, listado_scripts); 
    Consumidor cons = CrearConsumidor(buffer);

    

    //Lista_scripts iter = listado_scripts;
    int cont = 0;

    

    // cambiar 2 condiciones
    while (!IsEmpty(iter)) {

        //fork(), 1 para proceso productor y otros 2 para consumidor

        // Productor
        // cambiar iter por prod->listaScripts
        Script auxiS = ObtenerScript(iter);
        printf("Contador: %d: ", cont);
        fprintf(stdout,"%s\n",ObtenerLinea(auxiS));
        iter = Tail(iter);
        cont++;

        // Consumidor
        //Lista_scripts = EjecutarScriptsBuffer();

    }

    // Hacer fork()? y si es padre que sea un productor y un hijo consumidor? creo que no
    // Crear un productor: Productor p = CrearProductor();
    // ver si hay archivos por leer
    // chequear semaforos entre productor y consumidor
    // bool ColocarScripts(Lista_scripts lista) en productor.c
    // duerme el productor y depierto consumidor
    // creo el consumidor
    // consumidor busca celdas vacias, hasta que no haya mas celdas vacias
    // ahi deberia ser desde donde tiene que empezar a leer
    // lee MAX_BUFFER / 2 como maximo ponele. O sino 10 y ahi hay que crear mas consumidores
    // ejecuta los scripts (todo en consumidor.c)
    // con cada script que ejecuta, guarda en un archivo la salida, con cierto nombre. 
    // liberar memoria de semaforos
    // etc.

    ActualizarBufferProductor(prod);

    // Imprimir array Buffer en memoria para ver que se lleno bien

    // dormir productor y sem_post a consumidor (dentro de ActualizarBufferProductor?)

    //Consumidor cons = CrearConsumidor(prod);
    // scripts = LeerBufferConsumidor(cons)
    // EjecutarScriptsConsumidor(scripts) // ejecuta y guarda las salidas
    // duerme consumidor. sem_post a productor


    
    // Los semaforos habria que eliminarlos al terminar el programa, calculo
	//sem_unlink("sem_prod.txt");
	//sem_unlink("sem_cons.txt");

	//shm_unlink("/nombre");


    return 0;

}


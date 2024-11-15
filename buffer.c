/***
 * 
 * Sis Ops - File System
 * 
 */

#define MAX_BUFFER 100

#include "archivo.h"
#include "script.h"
#include "buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

// semaforos
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <sys/ipc.h>

// mem compartida
#include <sys/shm.h>
#include <sys/mman.h>

#include <pthread.h>


struct buffer{
	//Lista_scripts scripts;
    // Definir como tengo el array circular de EDA
    // En esa estructura poner libre (y usado??)
    // Con eso puedo usar % MAX_BUFFER para nunca pasarme del array y dar la vuelta
    // Al dar la vuelta ver si necesito chequear usado
    char * array_buffer[MAX_BUFFER];
    int tam;
};


Buffer CrearBuffer(){
    int shm_fd;
	Buffer buffer;
	//int p;
	const int SIZE=1024;

    sem_t *sem_buffer = sem_open("sem_buffer.txt", O_CREAT, 644, 1);
    sem_wait(sem_buffer);
    
/*
	sem_t *sem1;
	sem1 = sem_open("sem3.txt", O_CREAT, 644, 1);
	
	sem_t *sem2;
	sem2 = sem_open("sem4.txt", O_CREAT, 644, 0);
*/
	//p = fork();
	//crear memoria compartida
	shm_fd = shm_open("/nombre", O_CREAT | O_RDWR, 0666);
	// Configurar el tamaño de la memoria compartida
	ftruncate(shm_fd, SIZE);
	//printf("Hola, funciono\n");
	// Mapear la memoria compartida a la memoria del proceso.
	buffer = (Buffer) mmap (0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	/*
    if (p == 0) wait(NULL);
	sem_wait(sem1);
	//printf("Hola, funciono\n");
    */

    // Usar la memoria compartida
    //*ptr=getpid();
	buffer->tam = 0;
	close(shm_fd);


	
    /*
    sem_post(sem2);

	sem_wait(sem2);
		if (p > 0) printf("El pid del hijo es %d\n", *ptr);
	sem_post(sem1);
	
	sem_close(sem1);
	sem_unlink("sem3.txt");
	
	sem_close(sem2);
	sem_unlink("sem4.txt");
    */

    sem_post(sem_buffer);
    sem_close(sem_buffer);

    return buffer;
}



// tal vez precise pasar algun dato mas...
// podria devolver el ultimo lugar del array donde coloco una linea de script.
// 	
int ColocarScriptsBuffer(Buffer buffer, Script script){
    // chekear si esta lleno
    if(buffer->tam >= MAX_BUFFER){
		printf("Buffer lleno\n");
		return -1; //por retornar algo, despues en el main verificar que retorna
	}
    sem_t *sem_buffer = sem_open("sem_buffer.txt", O_CREAT, 644, 1);
    sem_wait(sem_buffer);
    
	strcpy(buffer->array_buffer[buffer->tope], ObtenerLinea(script));
	// por lo que comprendi guarda la linea del script en el buffer segun el
	// buffer->tam, que el tam determina donde va el script?, ubica el script en
	// la posicion que le da el tam y incrementa este
	// capaz deberia ir al productor
    
    sem_post(sem_buffer);
    sem_close(sem_buffer);
	buffer->tam++;
	return 0;
}
// Coloca una cantidad < a MAX_BUFFER de Scripts en el array del buffer
// Tal vez un MAX_BUFFER / 4 o 3. Para que duerma despierte a consumidor y despues vuelva a terminar lo que le falta.
// En el array coloco la linea del script s en 1 lugar (char *) del buffer.



// tal vez precise pasar algun dato mas...
// desde y hasta los puedo pasar o podria fijar los limites dentro de la funcion.
// desde vamos a pasar proximo de consumidor desde main y hasta es MAX_lecturas
int EjecutarScriptsBuffer(Buffer buffer, int desde, int hasta){
    //Lista_scripts = lista;
	sem_t *sem_buffer = sem_open("sem_buffer.txt", O_CREAT, 644, 1);
    sem_wait(sem_buffer);

/*
    while (buffer )
    for (int i = desde; i < hasta && i < buffer->tam; i++){
		printf("Script %d: %s\n", i, buffer->array_buffer[i]);
        //lista += script;
	}
	*/

	// traer 1 script del array
	// con


    sem_post(sem_buffer);
    sem_close(sem_buffer);
	return i;
}
// Tengo que ver cual seria el primer elemento a quitar y cuantos
// esos datos los puedo obterner pasados por parametro o sino obtenerlos directo con el array.

/*
version anterior:
int LeerScriptsBuffer(Buffer buffer, int desde, int hasta){
	for (int i = desde; i < hasta && i < buffer->tam; i++){
		printf("Script %d: %s\n", i, buffer->array_buffer[i]);
	}
	return 1;
}
*/


int ObtenerTamBuffer(Buffer buffer){
	return buffer->tam;
}

void ActualizarTamBuffer(Buffer buffer, int nuevoTam){
	buffer->tam = nuevoTam;
}


bool IsEmptyCeldaBuffer(Buffer buffer, int celda){
// Retorna si la celda celda esta vacia
	return strcmp(buffer->array_buffer[celda], "") == 0;
}

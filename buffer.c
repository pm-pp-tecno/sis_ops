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
    char * array_buffer[100];
    int tam;
};


Buffer CrearBuffer(){
    int shm_fd;
	int *ptr;
	int p;
	const int SIZE=1024;
    
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
	ptr = (int*) mmap (0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	/*
    if (p == 0) wait(NULL);
	sem_wait(sem1);
	//printf("Hola, funciono\n");
    */

    // Usar la memoria compartida
    *ptr=getpid();

	close(shm_fd);
	shm_unlink("/nombre");

	
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


    return NULL;
}



// tal vez precise pasar algun dato mas...
// podria devolver el ultimo lugar del array donde coloco una linea de script.
int ColocarScriptsBuffer(Buffer buffer, Script script){
    return 0;
}
// Coloca una cantidad < a MAX_BUFFER de Scripts en el array del buffer
// Tal vez un MAX_BUFFER / 4 o 3. Para que duerma despierte a consumidor y despues vuelva a terminar lo que le falta.
// En el array coloco la linea del script s en 1 lugar (char *) del buffer.



// tal vez precise pasar algun dato mas...
// desde y hasta los puedo pasar o podria fijar los limites dentro de la funcion.
int LeerScriptsBuffer(int desde, int hasta);
// Tengo que ver cual seria el primer elemento a quitar y cuantos
// esos datos los puedo obterner pasados por parametro o sino obtenerlos directo con el array.



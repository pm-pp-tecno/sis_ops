// semaforos
#include <semaphore.h>
#include <sys/ipc.h>
#include <fcntl.h>

// mem compartida
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include <unistd.h>
#include <stdio.h>
#include <wait.h>

int main(){
	int shm_fd;
	int *ptr;
	int p;
	const int SIZE=1024;
	
	sem_t *sem1;
	sem1=sem_open("sem3.txt", O_CREAT, 644, 1);
	
	sem_t *sem2;
	sem2=sem_open("sem4.txt", O_CREAT, 644, 0);

	p = fork();
	//crear memoria compartida
	shm_fd = shm_open("/nombre", O_CREAT | O_RDWR, 0666);
	// Configurar el tamaño de la memoria compartida
	ftruncate(shm_fd, SIZE);
	//printf("Hola, funciono\n");
	// Mapear la memoria compartida a la memoria del proceso.
	ptr = (int*) mmap (0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
	
	if (p == 0) wait(NULL);
	sem_wait(sem1);
	//printf("Hola, funciono\n");
		// Usar la memoria compartida
		*ptr=getpid();
	sem_post(sem2);

	sem_wait(sem2);
		if (p > 0) printf("El pid del hijo es %d\n", *ptr);
	sem_post(sem1);
	
	close(shm_fd);
	shm_unlink("/nombre");

	sem_close(sem1);
	sem_unlink("sem3.txt");
	
	sem_close(sem2);
	sem_unlink("sem4.txt");
}

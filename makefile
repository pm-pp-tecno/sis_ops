all: main.o productor.o consumidor.o archivo.o script.o buffer.o
	g++ -o programa main.o productor.o consumidor.o archivo.o script.o buffer.o -lrt -pthread
main.o: main.c productor.h consumidor.h
	g++ -c main.c
productor.o: archivo.h script.h buffer.h productor.h
	g++ -c productor.c
consumidor.o: archivo.h script.h buffer.h consumidor.h
	g++ -c consumidor.c
script.o: archivo.h script.h
	g++ -c script.c
buffer.o: archivo.h script.h buffer.h
	g++ -c buffer.c
clean:
	rm *.o
	rm programa
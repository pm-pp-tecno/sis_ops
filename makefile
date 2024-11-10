all: main.o productor.o consumidor.o archivo.o scripts.o consumidor.o
	g++ -o programa main.o productor.o consumidor.o archivo.o scripts.o consumidor.o
main.o: main.c productor.h consumidor.h
	g++ -c main.c
productor.o: archivo.c scripts.h buffer.h consumidor.h
	g++ -c productor.c
consumidor.o: archivo.c scripts.h buffer.h consumidor.h
	g++ -c consumidor.c
clean:
	rm *.o
	rm programa
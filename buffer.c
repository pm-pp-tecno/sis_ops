/***
 * 
 * Sis Ops - File System
 * 
 */

#define MAX_BUFFER 5

#include "archivo.h"
#include "script.h"
#include "buffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct buffer{
	//Lista_scripts scripts;
    // Definir como tengo el array circular de EDA
    // En esa estructura poner libre (y usado??)
    // Con eso puedo usar % MAX_BUFFER para nunca pasarme del array y dar la vuelta
    // Al dar la vuelta ver si necesito chequear usado
    int tam;
};


// tal vez precise pasar algun dato mas...
// podria devolver el ultimo lugar del array donde coloco una linea de script.
int ColocarScriptsBuffer(Lista_scripts lista);
// Coloca una cantidad < a MAX_BUFFER de Scripts en el array del buffer
// Tal vez un MAX_BUFFER / 4 o 3. Para que duerma despierte a consumidor y despues vuelva a terminar lo que le falta.
// En el array coloco la linea del script s en 1 lugar (char *) del buffer.



// tal vez precise pasar algun dato mas...
// desde y hasta los puedo pasar o podria fijar los limites dentro de la funcion.
int LeerScriptsBuffer(int desde, int hasta);
// Tengo que ver cual seria el primer elemento a quitar y cuantos
// esos datos los puedo obterner pasados por parametro o sino obtenerlos directo con el array.



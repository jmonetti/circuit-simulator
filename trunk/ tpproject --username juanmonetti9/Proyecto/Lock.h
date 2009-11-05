/**************************   Clase Lock **************************************/
/**************************   Grupo 8    **************************************/
/* Utiliza el patrron de diseño RAII, de manera que al instanciarlo en forma
 * estatica dentro de scopes, al salir de el se llama al destructor automati_
 * camente y en ese momento se desbloquea el mutex.
 */

#ifndef CLASS_LOCK_H
#define CLASS_LOCK_H

#include "Mutex.h"

class Lock{

	private:
		//atributo
		Mutex* mutex;

	public:
		/**
		 * Constructor
		 * @param m: puntero a mutex
		 */
		Lock(Mutex* m);
		/**
		 * Destructor
		 */
		~Lock();

};
#endif

/**************************   Clase Mutex  ************************************/
/**************************   Grupo 8      ************************************/


#ifndef CLASS_MUTEX_H
#define CLASS_MUTEX_H

#include <pthread.h>


class Mutex{

private:

		pthread_mutex_t mutex; //variable mutex

public:

		/**
		 * Constructor
		 */
		Mutex();

		/**
		 * Destructor
		 */
		~Mutex();

		/**
		 * Bloquea el mutex
		 */
		void Lock();

		/**
		 * Desbloquea el mutex
		 */
		void unLock();
};

#endif

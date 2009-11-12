/**************************   Clase Thread  ***********************************/
/**************************   Grupo 8       ***********************************/


#ifndef CLASS_THREAD_H_
#define CLASS_THREAD_H_

#include <pthread.h>
#include <iostream>

class Thread{

private:
		//atributo
		pthread_t hilo;

public:
		//Constructor
		Thread();

		/**
		 * Creo el atributo hilo, y lo inicializo con sus valores por default.
		 * Este hilo se ejecutara llamando a la funcion Thread::ptr_tun.
		 */
		void start();

		/**
		 * Asegura que no se termine la ejecucion del programa hasta que este
		 * hilo haya terminado.
		 */
		void* join();

		/**
		 * Finaliza la ejecucion
		 */
		void cancel();

		//Desctructor Virtual
		virtual ~Thread();

	private:

		/**
		 * Retorna una referencia al atributo hilo.
		 */
		pthread_t& get_hilo();

		/**
		 * Se utiliza para mandar como argumento al crar un hilo.
		 * Llama a la funcion run().
		 */
		static void * ptr_run(void * arg);

		/**
		 * Funcion virtual para redefinir en sus hijos,  con la implementacion
		 * de la ejecucion del hilo.
		 *
		 */
		virtual void* run()=0;

};

#endif

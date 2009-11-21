/**************************   Clase Thread  ***********************************/
/**************************   Grupo 8       ***********************************/


#ifndef CLASS_THREAD_H_
#define CLASS_THREAD_H_

#include <pthread.h>
#include <iostream>
#include <stdexcept>

class Thread{

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

		void stop();

		bool esta_Activo();

		//Desctructor Virtual
		virtual ~Thread();

	private:

		//atributo
		pthread_t hilo;

		bool state;

		/**
		 * Retorna una referencia al atributo hilo.
		 */
		pthread_t& get_hilo();

		/**
		 * Se utiliza para mandar como argumento al crar un hilo.
		 * Llama a la funcion run().
		 */
		static void* start_routine(void* arg);

		/**
		 * Funcion virtual para redefinir en sus hijos,  con la implementacion
		 * de la ejecucion del hilo.
		 *
		 */
		virtual void* run()=0;

};

#endif

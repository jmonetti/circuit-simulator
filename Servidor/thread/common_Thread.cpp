/**************************   Clase Thread  ***********************************/
/**************************   Grupo 8       ***********************************/

#include "common_Thread.h"

/*----------------------------------------------------------------------------*/

Thread::Thread(){

	this->state=false;
}

/*----------------------------------------------------------------------------*/
void Thread::start(){

	if (!esta_Activo()) {

		this->state= true;
		int retorno= pthread_create(&(this->get_hilo()),NULL,start_routine,this);

		if (retorno != 0) {

			this->state= false;
			throw std::runtime_error("Error Thread - start() - Falla creacion de hilo.");

		}
	}
	else
	{
		throw std::runtime_error("Error Thread - start() - Hilo ya esta activo.");
	}
}
/*----------------------------------------------------------------------------*/

void* Thread::join(){

	void* up;
	pthread_join(hilo,&up);
	return up;
}

/*----------------------------------------------------------------------------*/

pthread_t& Thread::get_hilo(){

	return this->hilo;
}

/*----------------------------------------------------------------------------*/

void* Thread::start_routine(void* arg) {

	Thread* pthread = (Thread*)arg;
	return pthread->run();

}
/*----------------------------------------------------------------------------*/
void Thread::stop() {

	this->state=false;

}
/*----------------------------------------------------------------------------*/
bool Thread::esta_Activo() {

	return this->state;

}
/*----------------------------------------------------------------------------*/

Thread::~Thread(){}
/*----------------------------------------------------------------------------*/

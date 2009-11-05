/**************************   Clase Thread  ***********************************/
/**************************   Grupo 8       ***********************************/

#include "Thread.h"

/*----------------------------------------------------------------------------*/

Thread::Thread(){}

/*----------------------------------------------------------------------------*/
void Thread::start(){

	pthread_create(& (this->get_hilo()), NULL, & (Thread::ptr_run), this);
}
/*----------------------------------------------------------------------------*/

void* Thread::join(){

	void* up;
	pthread_join(hilo,&up);
	return up;
}

/*----------------------------------------------------------------------------*/
void Thread::cancel(){

	pthread_cancel(this->hilo);
}

/*----------------------------------------------------------------------------*/

pthread_t& Thread::get_hilo(){

	return this->hilo;
}

/*----------------------------------------------------------------------------*/

void * Thread::ptr_run(void * arg){

	Thread* hilo=(Thread*)arg;

	pthread_exit(hilo->run());

	return NULL;
}
/*----------------------------------------------------------------------------*/

Thread::~Thread(){}
/*----------------------------------------------------------------------------*/

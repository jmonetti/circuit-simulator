#include "common_HiloEscucha.h"
#include <stdlib.h>
#include <iostream>
#include "modelo/common_ManagerArchivos.h"

#define PARAR 'x'

int main(int argc, char **argv) {

	ManagerArchivos* managerArchivos= ManagerArchivos::crearInstancia();

	HiloEscucha hiloEscucha;

	hiloEscucha.escuchar(atoi(argv[1]));

	hiloEscucha.start();

	/*
	 * Frenar cuando se ingresa PARAR
	 */
	char caracter= ' ';
	while (caracter != PARAR){
		sleep(0);
		std::cin>>caracter;
	}

	std::cerr<<"Finalizando servicio..."<<std::endl;

	/*
	 * Termino el hilo de escuchar
	 */
	hiloEscucha.terminar();
	hiloEscucha.join();

	delete managerArchivos;

}


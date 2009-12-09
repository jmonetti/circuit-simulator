#include "common_HiloEscucha.h"
#include "socket/common_Protocolo.h"
#include "excepciones/common_SocketException.h"

HiloEscucha::HiloEscucha() {

	socketEscuchando= new Socket();

}

HiloEscucha::~HiloEscucha() {

	socketEscuchando->close();
	delete socketEscuchando;

}

void HiloEscucha::escuchar(unsigned int port) {

	socketEscuchando->listen(port);

}

void HiloEscucha::terminarHilos() {

	while (!hilosComunicacion.empty()) {

		HiloComunicacion* hilo= hilosComunicacion.back();hilosComunicacion.pop_back();
		if (hilo->esta_Activo()){

			hilo->terminar();

		}

		hilo->join();
		delete hilo;

	}

}

void* HiloEscucha::run() {

	while (esta_Activo()) {

		try{

			Socket* cliente= socketEscuchando->accept();

			if (cliente) {

				std::cerr<<"Nuevo cliente conectado"<<std::endl;

				/*
				 * Libero los hilos que terminaron
				 */

				vaciarHilos();

				/*
				 * Creo el nuevo hilo para el cliente
				 */

				HiloComunicacion* hiloComunicacion= new HiloComunicacion(new Protocolo(cliente));
				this->hilosComunicacion.push_back(hiloComunicacion);

				try{

					hiloComunicacion->start();

				}catch (std::runtime_error &e) {

					this->terminar();

				}

			}


		}catch (SocketException e) {

			this->stop();

		}



	}

	return NULL;

}

void HiloEscucha::vaciarHilos() {

	 std::vector<HiloComunicacion*>::iterator iterador = hilosComunicacion.begin();

	 while(iterador != hilosComunicacion.end()) {


		 HiloComunicacion* hilo= *iterador;

		 if (!hilo -> esta_Activo()) {

			 hilo->join();
			 delete hilo;
			 iterador = hilosComunicacion.erase(iterador);

	     }else{

	    	 ++iterador;

	     }

	 }

}

void HiloEscucha::terminar() {

	terminarHilos();
	socketEscuchando->shutdown();
	this->stop();

}

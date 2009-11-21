
#include "common_HiloComunicacion.h"

HiloComunicacion::HiloComunicacion(Protocolo* protocolo) {

	this->protocolo= protocolo;

}

HiloComunicacion::~HiloComunicacion() {

	delete this->protocolo;

}

void HiloComunicacion::terminar() {

	protocolo->shutdown();
	this->stop();
	std::cerr<<"Cliente Desconectado"<<std::endl;

}


void* HiloComunicacion::run() {

	while (this->esta_Activo()) {

		//TODO

	}
	return NULL;

}



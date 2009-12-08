
#include "common_HiloComunicacion.h"
#include "modelo/circuito/common_Circuito.h"

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



std::string HiloComunicacion::recibirPedido() {

	std::string ruta_pedido = "pedido.xml";

	//TODO recibir informacion de a lineas e ir guardandolas en ruta_pedido.

	return ruta_pedido;

}

void HiloComunicacion::responder(std::string &respuesta) {

	//TODO abrir archivo, enviarlo de a lineas.

}


void* HiloComunicacion::run() {

	while (this->esta_Activo()) {

		std::string ruta_pedido = recibirPedido();

		std::string ruta_respuesta = modelo.generarRespuesta(ruta_pedido);

		responder(ruta_respuesta);

	}
	return NULL;

}



#include "common_ManagerArchivos.h"
#include "../thread/common_Lock.h"

ManagerArchivos* ManagerArchivos::instancia= NULL;

ManagerArchivos* ManagerArchivos::crearInstancia() {

	if(instancia == NULL){

		instancia= new ManagerArchivos();

	}

	return instancia;

}

ManagerArchivos* ManagerArchivos::getInstancia() {

	return instancia;

}

ManagerArchivos::~ManagerArchivos() {

}


std::string ManagerArchivos::getNombrePedido() {

	Lock l(&mutexPedidos);

    std::stringstream converter;

    converter << contPedidos;

    std::string contPedidosAux = converter.str();

	std::string pedido = PATH_TEMP + PEDIDO + contPedidosAux;

	contPedidos++;

	return pedido;
}

std::string ManagerArchivos::getNombreRespuesta() {

	Lock l(&mutexRespuestas);

    std::stringstream converter;

    converter << contRespuestas;

    std::string contRespuetasAux = converter.str();

	std::string respuesta = PATH_TEMP + RESPUESTA + contRespuetasAux;

	contRespuestas++;

	return respuesta;
}

void ManagerArchivos::removerArchivo(std::string &archivo) {

	remove(archivo.c_str());

}

ManagerArchivos::ManagerArchivos() {

	contPedidos= 0;
	contRespuestas= 0;
}

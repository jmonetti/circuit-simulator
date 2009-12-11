

#include "common_ManagerArchivos.h"

int ManagerArchivos::contPedidos = 0;

int ManagerArchivos::contRespuestas = 0;

std::string ManagerArchivos::getNombrePedido() {

    std::stringstream converter;

    converter << contPedidos;

    std::string contPedidosAux = converter.str();

	std::string pedido = PATH_TEMP + PEDIDO + contPedidosAux;

	contPedidos++;

	return pedido;
}

std::string ManagerArchivos::getNombreRespuesta() {

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

#include "common_ManagerConexiones.h"
#include <vector>

bool ManagerConexiones::conectar(EntradaCompuerta* entrada,SalidaCompuerta* salida) {

	Posicion posicionEntrada= entrada->getPosicion();
	SENTIDO sentidoEntrada= entrada->getSentido();
	Posicion posicionSalida= salida->getPosicion();
	SENTIDO sentidoSalida= salida->getSentido();


	if (hayConexion(posicionEntrada,sentidoEntrada,posicionSalida,sentidoSalida)) {

		entrada->conectar(salida);
		salida->conectar(entrada);

		return true;

	}

	return false;

}

void ManagerConexiones::desconectar(Compuerta* compuerta) {

	EntradaCompuerta** entradas= compuerta->getEntradas();

	for (int var = 0; var < compuerta->getCantidadEntradas(); ++var) {

		desconectar(entradas[var]);

	}

	SalidaCompuerta** salidas= compuerta->getSalidas();

	for (int var = 0; var < compuerta->getCantidadSalidas(); ++var) {

		desconectar(salidas[var]);

	}

}


bool ManagerConexiones::hayConexion(Posicion posicionEntrada,SENTIDO sentidoEntrada, Posicion posicionSalida,SENTIDO sentidoSalida) {

	//TODO

	return false;

}

void ManagerConexiones::desconectar(EntradaCompuerta* entrada) {

	SalidaCompuerta* salida= entrada->getConexion();

	if (salida) {

		salida->desconectar(entrada);
		entrada->desconectar();

	}

}

void ManagerConexiones::desconectar(SalidaCompuerta* salida) {

	std::vector<EntradaCompuerta*> entradas= salida->getConexiones();

	for (unsigned int var = 0; var < entradas.size(); ++var) {

		entradas[var]->desconectar();

	}

	salida->desconectar();

}

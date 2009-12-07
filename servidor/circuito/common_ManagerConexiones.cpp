#include "common_ManagerConexiones.h"
#include <vector>
#include "../excepciones/common_ConexionException.h"

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

	switch (sentidoEntrada) {

		case NORTE:

			return verificarConexionNorte(posicionEntrada,posicionSalida,sentidoSalida);

			break;

		case ESTE:

			return verificarConexionEste(posicionEntrada,posicionSalida,sentidoSalida);

			break;

		case OESTE:

			return verificarConexionOeste(posicionEntrada,posicionSalida,sentidoSalida);

			break;

		case SUR:

			return verificarConexionSur(posicionEntrada,posicionSalida,sentidoSalida);

			break;

		default:

			return false;

			break;

	}

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

bool ManagerConexiones::verificarConexionNorte(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

			return (((xEntrada == xSalida) && (yEntrada == ySalida - 1)) ||
					((xEntrada == xSalida + 1) && (yEntrada == ySalida)));

			break;

		case OESTE:

			return (((xEntrada == xSalida) && (yEntrada == ySalida - 1)) ||
					((xEntrada == xSalida - 1) && (yEntrada == ySalida)));

			break;

		case NORTE:

			return ((xEntrada == xSalida) && (yEntrada == ySalida - 1));

			break;

		default:

			return false;

			break;

	}

	return false;

}

bool ManagerConexiones::verificarConexionEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

			return ((xEntrada == xSalida + 1) && (yEntrada == ySalida));

			break;

		case SUR:

			return (((xEntrada == xSalida + 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida + 1)));

			break;

		case NORTE:

			return (((xEntrada == xSalida + 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida - 1))) ;

			break;

		default:

			return false;

			break;

	}

	return false;

}

bool ManagerConexiones::verificarConexionOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case SUR:

			return (((xEntrada == xSalida - 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida + 1)));

			break;

		case OESTE:

			return ((xEntrada == xSalida - 1) && (yEntrada == ySalida));

			break;

		case NORTE:

			return (((xEntrada == xSalida - 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida - 1)));

			break;

		default:

			return false;

			break;

	}

	return false;

}

bool ManagerConexiones::verificarConexionSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

			return (((xEntrada == xSalida) && (yEntrada == ySalida + 1)) ||
					((xEntrada == xSalida + 1) && (yEntrada == ySalida)));

			break;

		case OESTE:

			return (((xEntrada == xSalida) && (yEntrada == ySalida + 1)) ||
					((xEntrada == xSalida - 1) && (yEntrada == ySalida)));

			break;

		case SUR:

			return ((xEntrada == xSalida) && (yEntrada == ySalida + 1));

			break;

		default:

			return false;

			break;

	}

	return false;

}

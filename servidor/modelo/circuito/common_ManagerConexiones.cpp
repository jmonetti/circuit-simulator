#include "common_ManagerConexiones.h"
#include <vector>
#include "../../excepciones/common_ConexionException.h"

bool ManagerConexiones::conectar(EntradaCompuerta* entrada,SalidaCompuerta* salida, std::vector<ConexionVertice>* conexiones) {

	Posicion posicionEntrada= entrada->getPosicion();
	SENTIDO sentidoEntrada= entrada->getSentido();

	Posicion posicionSalida= salida->getPosicion();
	SENTIDO sentidoSalida= salida->getSentido();

	if (hayConexion(posicionEntrada,sentidoEntrada,posicionSalida,sentidoSalida,conexiones)) {

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


bool ManagerConexiones::hayConexion(Posicion posicionEntrada,SENTIDO sentidoEntrada, Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

	switch (sentidoEntrada) {

		case NORTE:

			return verificarConexionNorte(posicionEntrada,posicionSalida,sentidoSalida, conexiones);

			break;

		case ESTE:

			return verificarConexionEste(posicionEntrada,posicionSalida,sentidoSalida, conexiones);

			break;

		case OESTE:

			return verificarConexionOeste(posicionEntrada,posicionSalida,sentidoSalida, conexiones);

			break;

		case SUR:

			return verificarConexionSur(posicionEntrada,posicionSalida,sentidoSalida, conexiones);

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

bool ManagerConexiones::verificarConexionNorte(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:
		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionSalida,NORTE);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,OESTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

		break;

		case OESTE:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionSalida,NORTE);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,ESTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

		break;

		case NORTE:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionEntrada,NORTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

		break;

		default:

			return false;

			break;

	}

	return false;

}

bool ManagerConexiones::verificarConexionEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

		{
			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,ESTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

			break;

		case SUR:

		{
			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,ESTE);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionEntrada,NORTE);
				conexiones->push_back(conexion);
				return true;

			}


		}

			break;

		case NORTE:
		{

			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,ESTE);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionEntrada,SUR);
				conexiones->push_back(conexion);
				return true;

			}


		}

			break;

		default:

			return false;

			break;

	}

	return false;

}

bool ManagerConexiones::verificarConexionOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case SUR:

		{

			if ((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,OESTE);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionEntrada,NORTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

			break;

		case OESTE:

		{

			if ((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,OESTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

			break;

		case NORTE:

		{

			if((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,OESTE);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionEntrada,SUR);
				conexiones->push_back(conexion);
				return true;

			}

		}

			break;

		default:

			return false;

			break;

	}

	return false;

}

bool ManagerConexiones::verificarConexionSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionSalida,SUR);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,OESTE);
				conexiones->push_back(conexion);
				return true;

			}
		}

			break;

		case OESTE:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionSalida,SUR);
				conexiones->push_back(conexion);
				return true;

			}

			if ((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada, ESTE);
				conexiones->push_back(conexion);
				return true;

			}

		}

			break;

		case SUR:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionEntrada,SUR);
				conexiones->push_back(conexion);
				return true;

			}

		}


			break;

		default:

			return false;

			break;

	}

	return false;

}

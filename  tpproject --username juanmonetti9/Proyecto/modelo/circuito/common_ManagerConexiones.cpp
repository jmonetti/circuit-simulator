#include "common_ManagerConexiones.h"
#include <vector>
#include "../../excepciones/common_ConexionException.h"

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

void ManagerConexiones::obtenerConexionVertice(EntradaCompuerta* entrada, SalidaCompuerta* salida, std::vector<ConexionVertice>* conexiones) {

	Posicion posicionEntrada= entrada->getPosicion();
	SENTIDO sentidoEntrada= entrada->getSentido();

	Posicion posicionSalida= salida->getPosicion();
	SENTIDO sentidoSalida= salida->getSentido();

	switch (sentidoEntrada) {

		case NORTE:

			obtenerConexionVerticeNorte(posicionEntrada,posicionSalida,sentidoSalida,conexiones);

			break;

		case ESTE:

			obtenerConexionVerticeEste(posicionEntrada,posicionSalida,sentidoSalida,conexiones);

			break;

		case OESTE:

			obtenerConexionVerticeOeste(posicionEntrada,posicionSalida,sentidoSalida,conexiones);

			break;

		case SUR:

			obtenerConexionVerticeSur(posicionEntrada,posicionSalida,sentidoSalida,conexiones);

			break;

		default:

			break;

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
		{

			return (((xEntrada == xSalida) && (yEntrada == ySalida - 1)) ||
					((xEntrada == xSalida + 1) && (yEntrada == ySalida)));

		}

		break;

		case OESTE:

		{

			return (((xEntrada == xSalida) && (yEntrada == ySalida - 1)) ||
					((xEntrada == xSalida - 1) && (yEntrada == ySalida)));

		}

		break;

		case NORTE:

		{

			return ((xEntrada == xSalida) && (yEntrada == ySalida - 1));

		}

		break;

		default:

			return false;

			break;

	}

}

bool ManagerConexiones::verificarConexionEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

		{

			return ((xEntrada == xSalida + 1) && (yEntrada == ySalida));

		}

		break;

		case SUR:

		{

			return (((xEntrada == xSalida + 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida + 1)));

		}

		break;

		case NORTE:

		{

			return (((xEntrada == xSalida + 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida - 1)));

		}

		break;

		default:

			return false;

			break;

	}


}

bool ManagerConexiones::verificarConexionOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case SUR:

		{

			return (((xEntrada == xSalida - 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida + 1)));

		}

		break;

		case OESTE:

		{

			return ((xEntrada == xSalida - 1) && (yEntrada == ySalida));

		}

		break;

		case NORTE:

		{

			return (((xEntrada == xSalida - 1) && (yEntrada == ySalida)) ||
					((xEntrada == xSalida) && (yEntrada == ySalida - 1)));

		}

		break;

		default:

			return false;

			break;

	}

}

bool ManagerConexiones::verificarConexionSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case ESTE:

		{

			return (((xEntrada == xSalida) && (yEntrada == ySalida + 1)) ||
					((xEntrada == xSalida + 1) && (yEntrada == ySalida)));

		}

		break;

		case OESTE:

		{

			return (((xEntrada == xSalida) && (yEntrada == ySalida + 1)) ||
					((xEntrada == xSalida - 1) && (yEntrada == ySalida)));

		}

		break;

		case SUR:

		{

			return ((xEntrada == xSalida) && (yEntrada == ySalida + 1));

		}

		break;

		default:

			return false;

			break;

	}

}

void ManagerConexiones::obtenerConexionVerticeNorte(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

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

			}

			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,OESTE);
				conexiones->push_back(conexion);

			}

		}

		break;

		case OESTE:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionSalida,NORTE);
				conexiones->push_back(conexion);


			}

			if ((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,ESTE);
				conexiones->push_back(conexion);

			}

		}

		break;

		default:

			break;

	}

}

void ManagerConexiones::obtenerConexionVerticeEste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

	unsigned int xEntrada= posicionEntrada.getX();
	unsigned int yEntrada= posicionEntrada.getY();

	unsigned int xSalida= posicionSalida.getX();
	unsigned int ySalida= posicionSalida.getY();

	switch (sentidoSalida) {

		case SUR:

		{
			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,ESTE);
				conexiones->push_back(conexion);

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionEntrada,NORTE);
				conexiones->push_back(conexion);

			}


		}

			break;

		case NORTE:
		{

			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,ESTE);
				conexiones->push_back(conexion);


			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionEntrada,SUR);
				conexiones->push_back(conexion);

			}


		}

			break;

		default:

			break;

	}


}

void ManagerConexiones::obtenerConexionVerticeOeste(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

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

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionEntrada,NORTE);
				conexiones->push_back(conexion);

			}

		}

		break;

		case NORTE:

		{

			if((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionSalida,OESTE);
				conexiones->push_back(conexion);

			}

			if ((xEntrada == xSalida) && (yEntrada == ySalida - 1)) {

				ConexionVertice conexion(posicionEntrada,SUR);
				conexiones->push_back(conexion);

			}

		}

			break;

		default:

			break;

	}

}

void ManagerConexiones::obtenerConexionVerticeSur(Posicion posicionEntrada,Posicion posicionSalida,SENTIDO sentidoSalida, std::vector<ConexionVertice>* conexiones) {

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

			}

			if ((xEntrada == xSalida + 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,OESTE);
				conexiones->push_back(conexion);

			}
		}

			break;

		case OESTE:

		{

			if ((xEntrada == xSalida) && (yEntrada == ySalida + 1)) {

				ConexionVertice conexion(posicionSalida,SUR);
				conexiones->push_back(conexion);

			}

			if ((xEntrada == xSalida - 1) && (yEntrada == ySalida)) {

				ConexionVertice conexion(posicionEntrada,ESTE);
				conexiones->push_back(conexion);

			}

		}

			break;

		default:

			break;

	}

}

#include "common_CajaNegra.h"

CajaNegra::CajaNegra(int id,EntradaCompuerta** entradas, SalidaCompuerta** salidas,int cantidadEntradas,
int cantidadSalidas, Posicion posicion,SENTIDO sentido, const std::string &nombreCircuito,Servidor servidor)
: Compuerta(id,posicion,sentido), nombreCircuito(nombreCircuito), servidor(servidor){

	this->entradas= entradas;
	this->salidas= salidas;
	this->cantidadEntradas= cantidadEntradas;
	this->cantidadSalidas= cantidadSalidas;

	actualizarEntradas();
	actualizarSalidas();

}

CajaNegra::~CajaNegra() {

	for (int i = 0; i < cantidadEntradas; ++i) {

		delete entradas[i];

	}

	for (int i = 0; i < cantidadSalidas; ++i) {

		delete salidas[i];

	}

	delete[] entradas;
	delete[] salidas;

}

void CajaNegra::actuarTiempo(int* tiempos) {

	int* tiempoSalidas= publicacion.calcularTiempoTransicion(nombreCircuito,servidor,tiempos,cantidadEntradas);

	for (int var = 0; var < cantidadSalidas; ++var) {

		salidas[var]->setValorSalida(tiempoSalidas[var]);

	}

	delete[] tiempoSalidas;

}

void CajaNegra::actuarSimular(bool* valores) {

	bool* valorSalidas= publicacion.simular(nombreCircuito,servidor,valores,cantidadEntradas);

	for (int var = 0; var < cantidadSalidas; ++var) {

		salidas[var]->setValorSalida(valores[var]);

	}

	delete[] valorSalidas;

}

TIPO_COMPUERTA CajaNegra::getTipo() const {

	return T_CAJANEGRA;

}


EntradaCompuerta** CajaNegra::getEntradas() {

	return entradas;

}

SalidaCompuerta** CajaNegra::getSalidas() {

	return salidas;

}

int CajaNegra::getCantidadEntradas() {

	return cantidadEntradas;

}

int CajaNegra::getCantidadSalidas() {

	return cantidadSalidas;

}

void CajaNegra::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("CajaNegra", tempStr, 99);
    DOMElement*   elem_CajaNegra = doc->createElement(tempStr);

    /******* ATRIBUTO ENTRADAS*****************/

    aux = "entradas";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,cantidadEntradas);

    /******* ATRIBUTO SALIDAS*****************/

    aux = "salidas";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,cantidadSalidas);

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getSentido());

    /******* ATRIBUTO NOMBRE *****************/

    aux = "nombre";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,nombreCircuito);

    /******* ATRIBUTO PUERTO *****************/

    aux = "puerto";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,servidor.getPuerto());

    /******* ATRIBUTO HOST *****************/

    aux = "host";
    std::string host = servidor.getHost();
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,host);

    padre->appendChild(elem_CajaNegra);
}

void CajaNegra::actualizarEntradas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();


	for (int var = 0; var < cantidadEntradas; ++var) {

		unsigned int xEntrada;
		unsigned int yEntrada;

		switch (getSentido()) {

			case ESTE:
			{

				xEntrada= xCompuerta - 1;
				yEntrada= yCompuerta - 1 + 2*var;
				break;

			}
			case SUR:
			{

				xEntrada= xCompuerta + 1 - 2*var;
				yEntrada= yCompuerta - 1;

			}

			case NORTE:
			{

				xEntrada= xCompuerta - 1 + 2*var;
				yEntrada= yCompuerta + 1;

			}

			case OESTE:
			{

				xEntrada= xCompuerta + 1;
				yEntrada= yCompuerta + 1 - 2*var;
			}

			default:

				break;

		}

		Posicion posicion(xEntrada,yEntrada);
		entradas[var]->mover(posicion);
		entradas[var]->rotar(getSentido());

	}

}

void CajaNegra::actualizarSalidas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();


	for (int var = 0; var < cantidadSalidas; ++var) {

		unsigned int xSalida;
		unsigned int ySalida;

		switch (getSentido()) {

			case ESTE:
			{

				xSalida= xCompuerta + 1;
				ySalida= yCompuerta - 1 + 2*var;
				break;

			}

			case SUR:
			{

				xSalida= xCompuerta + 1 - 2*var;
				ySalida= yCompuerta + 1;

			}

			case NORTE:
			{

				xSalida= xCompuerta - 1 + 2*var;
				ySalida= yCompuerta - 1;

			}

			case OESTE:
			{

				xSalida= xCompuerta - 1;
				ySalida= yCompuerta + 1 - 2*var;

			}

			default:

				break;

		}

		Posicion posicion(xSalida,ySalida);
		entradas[var]->mover(posicion);
		entradas[var]->rotar(getSentido());

	}

}

#include "common_NOT.h"

NOT::NOT(int id,int tiempoTransicion,EntradaCompuerta* entrada,SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido) {

	this->entrada= entrada;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

	actualizarEntradas();
	actualizarSalidas();

}

NOT::~NOT() {

	delete entrada;
	delete salida;

}

void NOT::actuarTiempo(int* tiempos) {

	this->salida->setTiempoTransicion(tiempos[0] + tiempoTransicion);

}

void NOT::actuarSimular(bool* valores) {

	this->salida->setValorSalida(!valores[0]);

}

TIPO_COMPUERTA NOT::getTipo() const{

	return T_NOT;

}

EntradaCompuerta** NOT::getEntradas() {

	return &entrada;

}

SalidaCompuerta** NOT::getSalidas() {

	return &salida;

}

int NOT::getCantidadEntradas() {

	return 1;

}

int NOT::getCantidadSalidas() {

	return 1;

}


void NOT::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("NOT", tempStr, 99);
    DOMElement*   elem_NOT = doc->createElement(tempStr);

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getPosicion().getX());


    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getPosicion().getY());


    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getSentido());


    padre->appendChild(elem_NOT);

}

void NOT::actualizarEntradas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();

	unsigned int xEntrada;
	unsigned int yEntrada;


	switch (getSentido()) {

		case NORTE:
		{

			xEntrada= xCompuerta;
			yEntrada= yCompuerta + 1;

			break;

		}
		case ESTE:
		{

			xEntrada= xCompuerta - 1;
			yEntrada= yCompuerta;

			break;

		}
		case SUR:
		{

			xEntrada= xCompuerta;
			yEntrada= yCompuerta - 1;

			break;

		}
		case OESTE:
		{

			xEntrada= xCompuerta + 1;
			yEntrada= yCompuerta;

			break;

		}
		default:

			break;

	}

	Posicion posicionEntrada(xEntrada,yEntrada);
	entrada->mover(posicionEntrada);
	entrada->rotar(getSentido());

}

void NOT::actualizarSalidas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();

	unsigned int xSalida;
	unsigned int ySalida;


	switch (getSentido()) {

		case NORTE:
		{

			xSalida= xCompuerta;
			ySalida= yCompuerta - 1;

			break;

		}
		case ESTE:
		{

			xSalida= xCompuerta + 1;
			ySalida= yCompuerta;

			break;

		}
		case SUR:
		{

			xSalida= xCompuerta;
			ySalida= yCompuerta + 1;

			break;

		}
		case OESTE:
		{

			xSalida= xCompuerta - 1;
			ySalida= yCompuerta;

			break;

		}
		default:

			break;

	}

	Posicion posicionSalida(xSalida,ySalida);
	salida->mover(posicionSalida);
	salida->rotar(getSentido());

}

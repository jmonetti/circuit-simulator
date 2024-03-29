
#include "common_AND.h"


AND::AND(int id,int tiempoTransicion,EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida,Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

	actualizarEntradas();
	actualizarSalidas();

}

AND::~AND() {

	delete entradas[0];
	delete entradas[1];
	delete salida;


}

void AND::actuarTiempo(int* tiempos) {

	if (tiempos[0] > tiempos[1]) {

		salida->setTiempoTransicion(tiempos[0] + this->tiempoTransicion);

	}else{

		salida->setTiempoTransicion(tiempos[1] + this->tiempoTransicion);

	}

}

void AND::actuarSimular(bool* valores) {

	salida->setValorSalida(valores[0] && valores[1]);

}

TIPO_COMPUERTA AND::getTipo() const{

	return T_AND;

}

EntradaCompuerta** AND::getEntradas() {

	return entradas;

}

SalidaCompuerta** AND::getSalidas() {

	return &salida;

}

int AND::getCantidadEntradas() {

	return 2;

}

int AND::getCantidadSalidas() {

	return 1;

}


void AND::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("AND", tempStr, 99);
    DOMElement*   elem_AND = doc->createElement(tempStr);

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_AND,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_AND,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_AND,aux,getSentido());


    padre->appendChild(elem_AND);

}

void AND::actualizarEntradas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();

	unsigned int xEntrada1 = 0;
	unsigned int yEntrada1 = 0;

	unsigned int xEntrada2 = 0;
	unsigned int yEntrada2 = 0;


	switch (getSentido()) {

		case NORTE:
		{

			xEntrada1= xCompuerta - 1;
			yEntrada1= yCompuerta + 1;
			xEntrada2= xCompuerta + 1;
			yEntrada2= yCompuerta + 1;

			break;

		}
		case ESTE:
		{

			xEntrada1= xCompuerta - 1;
			yEntrada1= yCompuerta - 1;
			xEntrada2= xCompuerta - 1;
			yEntrada2= yCompuerta + 1;

			break;

		}
		case SUR:
		{

			xEntrada1= xCompuerta + 1;
			yEntrada1= yCompuerta - 1;
			xEntrada2= xCompuerta - 1;
			yEntrada2= yCompuerta - 1;

			break;

		}
		case OESTE:
		{

			xEntrada1= xCompuerta + 1;
			yEntrada1= yCompuerta + 1;
			xEntrada2= xCompuerta + 1;
			yEntrada2= yCompuerta - 1;

			break;

		}
		default:

			break;

	}

	Posicion posicionEntrada1(xEntrada1,yEntrada1);
	entradas[0]->mover(posicionEntrada1);
	entradas[0]->rotar(getSentido());
	Posicion posicionEntrada2(xEntrada2,yEntrada2);
	entradas[1]->mover(posicionEntrada2);
	entradas[1]->rotar(getSentido());


}

void AND::actualizarSalidas() {

	unsigned int xCompuerta= getPosicion().getX();
	unsigned int yCompuerta= getPosicion().getY();

	unsigned int xSalida = 0;
	unsigned int ySalida = 0;


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


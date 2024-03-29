
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

	delete[] entradas;
	delete salida;

}

void AND::calcularTiempoTransicion() {


	int tiempoEntrada1= entradas[0]->calcularTiempoTransicion();
	int tiempoEntrada2= entradas[1]->calcularTiempoTransicion();

	if (tiempoEntrada1 > tiempoEntrada2) {

		salida->setTiempoTransicion(tiempoEntrada1 + this->tiempoTransicion);

	}else{

		salida->setTiempoTransicion(tiempoEntrada2 + this->tiempoTransicion);

	}


}

void AND::simular() {

	bool entrada1= entradas[0]->simular();
	bool entrada2= entradas[1]->simular();

	salida->setValorSalida(entrada1 && entrada2);

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

    /******* ATRIBUTO ID*****************/

    aux = "id";
    Persistencia::guardarElemento(doc,elem_AND,aux,getId());

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

	unsigned int xEntrada1;
	unsigned int yEntrada1;

	unsigned int xEntrada2;
	unsigned int yEntrada2;


	switch (getSentido()) {

		case NORTE:
		{

			xEntrada1= xCompuerta + 1;
			yEntrada1= yCompuerta + 1;
			xEntrada2= xCompuerta - 1;
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

			xEntrada1= xCompuerta - 1;
			yEntrada1= yCompuerta - 1;
			xEntrada2= xCompuerta + 1;
			yEntrada2= yCompuerta - 1;

			break;

		}
		case OESTE:
		{

			xEntrada1= xCompuerta + 1;
			yEntrada1= yCompuerta - 1;
			xEntrada2= xCompuerta + 1;
			yEntrada2= yCompuerta + 1;

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


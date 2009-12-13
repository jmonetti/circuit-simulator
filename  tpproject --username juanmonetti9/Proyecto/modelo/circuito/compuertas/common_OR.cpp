#include "common_OR.h"

OR::OR(int id, int tiempoTransicion, EntradaCompuerta* entrada1,EntradaCompuerta* entrada2, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

	actualizarEntradas();
	actualizarSalidas();

}

OR::~OR() {

	delete entradas[0];
	delete entradas[1];
	delete salida;

}

void OR::actuarTiempo(int* tiempos) {

	if (tiempos[0] > tiempos[1]) {

		this->salida->setTiempoTransicion(tiempos[0] + this->tiempoTransicion);

	}else{

		this->salida->setTiempoTransicion(tiempos[1] + this->tiempoTransicion);

	}

}

void OR::actuarSimular(bool* valores) {

	salida->setValorSalida(valores[0] || valores[1]);

}

TIPO_COMPUERTA OR::getTipo() const {

	return T_OR;

}

EntradaCompuerta** OR::getEntradas() {

	return entradas;

}

SalidaCompuerta** OR::getSalidas() {

	return &salida;

}

int OR::getCantidadEntradas() {

	return 2;

}

int OR::getCantidadSalidas() {

	return 1;

}


void OR::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("OR", tempStr, 99);
    DOMElement*   elem_OR = doc->createElement(tempStr);

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_OR,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_OR,aux,getPosicion().getY());


    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_OR,aux,getSentido());


    padre->appendChild(elem_OR);

}

void OR::actualizarEntradas() {

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

void OR::actualizarSalidas() {

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

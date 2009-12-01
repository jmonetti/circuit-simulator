
#include "common_XOR.h"

XOR::XOR(int id, int tiempoTransicion, EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entradas[0] = entrada1;
	this->entradas[1] = entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

	actualizarEntradas();
	actualizarSalidas();

}

XOR::~XOR() {

	delete[] entradas;
	delete salida;

}

void XOR::calcularTiempoTransicion() {

	int tiempo1= entradas[0]->calcularTiempoTransicion();
	int tiempo2= entradas[1]->calcularTiempoTransicion();

	if (tiempo1 > tiempo2) {

		this->salida->setTiempoTransicion(tiempo1 + this->tiempoTransicion);

	}else{

		this->salida->setTiempoTransicion(tiempo2 + this->tiempoTransicion);

	}

}

void XOR::simular() {

	bool valor1= entradas[0]->simular();
	bool valor2= entradas[1]->simular();

	this->salida->setValorSalida(valor1 ^ valor2);

}

TIPO_COMPUERTA XOR::getTipo() const{

	return T_XOR;

}

EntradaCompuerta** XOR::getEntradas() {

	return entradas;

}

SalidaCompuerta** XOR::getSalidas() {

	return &salida;

}

int XOR::getCantidadEntradas() {

	return 2;

}

int XOR::getCantidadSalidas() {

	return 1;

}


void XOR::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("XOR", tempStr, 99);
    DOMElement*   elem_XOR = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/

    aux = "id";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getId());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getSentido());

    padre->appendChild(elem_XOR);

}

void XOR::actualizarEntradas() {

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

void XOR::actualizarSalidas() {

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

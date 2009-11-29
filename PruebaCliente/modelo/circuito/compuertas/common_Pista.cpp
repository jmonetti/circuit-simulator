/**************************   Clase Pista **************************************/
/**************************     Grupo 8   **************************************/

#include "common_Pista.h"

Pista::Pista(int id, EntradaCompuerta* entrada, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entrada= entrada;
	this->salida= salida;

	actualizarEntradas();
	actualizarSalidas();


}

Pista::~Pista() {

	delete entrada;
	delete salida;

}

void Pista::calcularTiempoTransicion() {

	int tiempo= entrada->calcularTiempoTransicion();

	salida->setTiempoTransicion(tiempo);

}

void Pista::simular() {

	salida->setValorSalida(entrada->simular());

}

TIPO_COMPUERTA Pista::getTipo() const {

	return T_PISTA;

}

EntradaCompuerta** Pista::getEntradas() {

	return &entrada;

}

SalidaCompuerta** Pista::getSalidas() {

	return &salida;

}

int Pista::getCantidadEntradas() {

	return 1;

}

int Pista::getCantidadSalidas() {

	return 1;

}


void Pista::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Pista", tempStr, 99);
    DOMElement*   elem_Pista = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/

    aux = "id";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getId());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getSentido());

    padre->appendChild(elem_Pista);

}

void Pista::actualizarEntradas() {

	entrada->mover(getPosicion());
	entrada->rotar(getSentido());

}

void Pista::actualizarSalidas() {

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


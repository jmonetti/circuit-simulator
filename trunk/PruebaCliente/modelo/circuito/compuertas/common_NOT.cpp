#include "common_NOT.h"

NOT::NOT(int id,int tiempoTransicion,EntradaCompuerta* entrada,SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido) {

	this->entrada= entrada;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

}

NOT::~NOT() {

	delete entrada;
	delete salida;

}

void NOT::calcularTiempoTransicion() {

	int tiempo= this->entrada->calcularTiempoTransicion() + this->tiempoTransicion;
	this->salida->setTiempoTransicion(tiempo);

}

void NOT::simular() {

	bool valor= this->entrada->simular();

	this->salida->setValorSalida(!valor);

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

    /******* ATRIBUTO ID*****************/

    aux = "id";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getId());

    /******* ATRIBUTO ID-ENTRADA*****************/

    aux = "idEntrada";
    Persistencia::guardarElemento(doc,elem_NOT,aux,entrada->getId());


    /******* ATRIBUTO ID-SALIDA*****************/

    aux = "idSalida";
    Persistencia::guardarElemento(doc,elem_NOT,aux,salida->getId());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getX());


    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getY());


    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_NOT,aux,getSentido());


    padre->appendChild(elem_NOT);

}

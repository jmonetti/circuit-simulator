#include "common_OR.h"

OR::OR(int id, int tiempoTransicion, EntradaCompuerta* entrada1,EntradaCompuerta* entrada2, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

}

OR::~OR() {

	delete[] entradas;
	delete salida;

}

void OR::calcularTiempoTransicion() {

	int tiempo1= entradas[0]->calcularTiempoTransicion();
	int tiempo2= entradas[1]->calcularTiempoTransicion();

	if (tiempo1 > tiempo2) {

		this->salida->setTiempoTransicion(tiempo1 + this->tiempoTransicion);

	}else{

		this->salida->setTiempoTransicion(tiempo2 + this->tiempoTransicion);

	}

}

void OR::simular() {

	bool valor1= entradas[0]->simular();
	bool valor2= entradas[1]->simular();

	salida->setValorSalida(valor1 || valor2);

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

    /******* ATRIBUTO ID*****************/

    aux = "id";
    Persistencia::guardarElemento(doc,elem_OR,aux,getId());


    /******* ATRIBUTO ID-ENTRADA1*****************/

    aux = "idEntrada1";
    Persistencia::guardarElemento(doc,elem_OR,aux,entradas[0]->getId());


    /******* ATRIBUTO ID-ENTRADA1*****************/

    aux = "idEntrada2";
    Persistencia::guardarElemento(doc,elem_OR,aux,entradas[1]->getId());


    /******* ATRIBUTO ID-SALIDA*****************/

    aux = "idSalida";
    Persistencia::guardarElemento(doc,elem_OR,aux,salida->getId());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_OR,aux,getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_OR,aux,getY());


    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_OR,aux,getSentido());


    padre->appendChild(elem_OR);

}

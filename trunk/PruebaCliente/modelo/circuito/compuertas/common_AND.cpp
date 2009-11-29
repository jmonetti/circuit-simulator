
#include "common_AND.h"

AND::AND(int id,int tiempoTransicion,EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida,Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

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

    /******* ATRIBUTO ID-ENTRADA1*****************/

    aux = "idEntrada1";
    Persistencia::guardarElemento(doc,elem_AND,aux,entradas[0]->getId());

    /******* ATRIBUTO ID-ENTRADA2*****************/

    aux = "idEntrada2";
    Persistencia::guardarElemento(doc,elem_AND,aux,entradas[1]->getId());

    /******* ATRIBUTO ID-SALIDA*****************/

    aux = "idSalida";
    Persistencia::guardarElemento(doc,elem_AND,aux,salida->getId());

    /******* ATRIBUTO CONEXION ENTRADA 1*****************/

    aux = "conexionE1";
    Persistencia::guardarElemento(doc,elem_AND,aux,entradas[0]->getConexion());

    /******* ATRIBUTO CONEXION ENTRADA 2*****************/

    aux = "conexionE2";
    Persistencia::guardarElemento(doc,elem_AND,aux,entradas[1]->getConexion());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_AND,aux,getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_AND,aux,getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_AND,aux,getSentido());


    padre->appendChild(elem_AND);

}

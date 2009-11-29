
#include "common_XOR.h"

XOR::XOR(int id, int tiempoTransicion, EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entradas[0] = entrada1;
	this->entradas[1] = entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

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

    /******* ATRIBUTO ID-ENTRADA1*****************/

    aux = "idEntrada1";
    Persistencia::guardarElemento(doc,elem_XOR,aux,entradas[0]->getId());

    /******* ATRIBUTO ID-ENTRADA1*****************/

    aux = "idEntrada2";
    Persistencia::guardarElemento(doc,elem_XOR,aux,entradas[1]->getId());

    /******* ATRIBUTO ID-SALIDA*****************/

    aux = "idSalida";
    Persistencia::guardarElemento(doc,elem_XOR,aux,salida->getId());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_XOR,aux,getSentido());

    padre->appendChild(elem_XOR);

}

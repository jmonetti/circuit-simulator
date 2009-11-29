/**************************   Clase Pista **************************************/
/**************************     Grupo 8   **************************************/

#include "common_Pista.h"

Pista::Pista(int id, EntradaCompuerta* entrada, SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido)
: Compuerta(id,posicion,sentido){

	this->entrada= entrada;
	this->salida= salida;

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


    /******* ATRIBUTO ID-ENTRADA*****************/

    aux = "idEntrada";
    Persistencia::guardarElemento(doc,elem_Pista,aux,entrada->getId());


    /******* ATRIBUTO ID-SALIDA*****************/

    aux = "idSalida";
    Persistencia::guardarElemento(doc,elem_Pista,aux,salida->getId());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_Pista,aux,getSentido());

    padre->appendChild(elem_Pista);

}

#include "common_Salida.h"

Salida::Salida(int id, EntradaCompuerta* entrada) : Compuerta(id) {

	this->entrada= entrada;
	this->tiempoTransicion= 0;

}

Salida::~Salida() {

	delete entrada;

}

void Salida::calcularTiempoTransicion() {

	this->tiempoTransicion= entrada->calcularTiempoTransicion();

}

Salida* Salida::getSalida(){

	return this;

}

void Salida::simular() {

	this->valor= entrada->simular();

}

bool Salida::getValor() {

	return valor;

}

int Salida::getTiempoTransicion() {

	return tiempoTransicion;

}

void Salida::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Salida", tempStr, 99);
    DOMElement*   elem_Salida = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/
    XMLString::transcode("id", tempStr, 99);
    DOMAttr* atributo0 = doc->createAttribute(tempStr);

    std::stringstream converter0;
    converter0 << this->getId();
    aux = converter0.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo0->setNodeValue(tempStr);
    elem_Salida->setAttributeNode(atributo0);

    /******* ATRIBUTO ID-ENTRADA*****************/
    XMLString::transcode("idEntrada", tempStr, 99);
    DOMAttr* atributo1 = doc->createAttribute(tempStr);

    std::stringstream converter1;
    converter1 << this->entrada->getId();
    aux = converter1.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo1->setNodeValue(tempStr);
    elem_Salida->setAttributeNode(atributo1);

    /******* ATRIBUTO CONEXION ENTRADA *****************/
    XMLString::transcode("conexionE", tempStr, 99);
    DOMAttr* atributo2 = doc->createAttribute(tempStr);

    std::stringstream converter2;
    converter2 << entrada->getConexion();
    aux = converter2.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo2->setNodeValue(tempStr);
    elem_Salida->setAttributeNode(atributo2);

    /******* ATRIBUTO CONEXION ENTRADA *****************/
    XMLString::transcode("conexionE", tempStr, 99);
    DOMAttr* atributo3 = doc->createAttribute(tempStr);

    std::stringstream converter3;
    converter3 << entrada->getConexion();
    aux = converter3.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo3->setNodeValue(tempStr);
    elem_Salida->setAttributeNode(atributo3);

    padre->appendChild(elem_Salida);

}

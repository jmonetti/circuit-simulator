
#include "common_Entrada.h"

Entrada::Entrada(int id,SalidaCompuerta* salida, Posicion posicion, SENTIDO sentido, const std::string &nombre)
: Compuerta(id,posicion,sentido) , nombre(nombre){

	this->salida= salida;

}

Entrada::~Entrada() {

	delete salida;

}

void Entrada::calcularTiempoTransicion() {

	this->salida->setTiempoTransicion(0);

}

Entrada* Entrada::getEntrada(){

	return this;

}

void Entrada::simular() {

	this->salida->setValorSalida(valor);

}

void Entrada::setValorEntrada(bool valor) {

	this->valor= valor;

}

bool Entrada::getValorEntrada() const {

	return this->valor;

}

std::string Entrada::getNombre() const {

	return nombre;

}

TIPO_COMPUERTA Entrada::getTipo() const{

	return T_ENTRADA;

}


EntradaCompuerta** Entrada::getEntradas() {

	return NULL;

}

SalidaCompuerta** Entrada::getSalidas() {

	return &salida;

}

int Entrada::getCantidadEntradas() {

	return 0;

}

int Entrada::getCantidadSalidas() {

	return 1;

}


void Entrada::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Entrada", tempStr, 99);
    DOMElement*   elem_Entrada = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/
    XMLString::transcode("id", tempStr, 99);
    DOMAttr* atributo0 = doc->createAttribute(tempStr);

    std::stringstream converter0;
    converter0 << this->getId();
    aux = converter0.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo0->setNodeValue(tempStr);
    elem_Entrada->setAttributeNode(atributo0);

    /******* ATRIBUTO ID-SALIDA*****************/
    XMLString::transcode("idSalida", tempStr, 99);
    DOMAttr* atributo1 = doc->createAttribute(tempStr);
    int idSalida = this->salida->getId();

    std::stringstream converter1;
    converter1 << idSalida;
    aux = converter1.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo1->setNodeValue(tempStr);
    elem_Entrada->setAttributeNode(atributo1);

    padre->appendChild(elem_Entrada);

}
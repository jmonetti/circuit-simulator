#include "common_NOT.h"

NOT::NOT(int id,int tiempoTransicion,EntradaCompuerta* entrada,SalidaCompuerta* salida)
: Compuerta(id) {

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

void NOT::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("NOT", tempStr, 99);
    DOMElement*   elem_NOT = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/
    XMLString::transcode("id", tempStr, 99);
    DOMAttr* atributo0 = doc->createAttribute(tempStr);

    std::stringstream converter0;
    converter0 << this->getId();
    aux = converter0.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo0->setNodeValue(tempStr);
    elem_NOT->setAttributeNode(atributo0);

    /******* ATRIBUTO ID-ENTRADA*****************/
    XMLString::transcode("idEntrada", tempStr, 99);
    DOMAttr* atributo1 = doc->createAttribute(tempStr);
    int idEntrada = this->entrada->getId();

    std::stringstream converter1;
    converter1 << idEntrada;
    aux = converter1.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo1->setNodeValue(tempStr);
    elem_NOT->setAttributeNode(atributo1);

    /******* ATRIBUTO ID-SALIDA*****************/
    XMLString::transcode("idSalida", tempStr, 99);
    DOMAttr* atributo2 = doc->createAttribute(tempStr);
    int idSalida = this->salida->getId();

    std::stringstream converter2;
    converter2 << idSalida;
    aux = converter2.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo2->setNodeValue(tempStr);
    elem_NOT->setAttributeNode(atributo2);

    /******* ATRIBUTO Tiempo Transicion*****************/
    XMLString::transcode("tiempoTransicion", tempStr, 99);
    DOMAttr* atributo3 = doc->createAttribute(tempStr);

    std::stringstream converter3;
    converter3 << tiempoTransicion;
    aux = converter3.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo3->setNodeValue(tempStr);
    elem_NOT->setAttributeNode(atributo3);

    /******* ATRIBUTO CONEXION ENTRADA *****************/
    XMLString::transcode("conexionE", tempStr, 99);
    DOMAttr* atributo4 = doc->createAttribute(tempStr);

    std::stringstream converter4;
    converter4 << entrada->getConexion();
    aux = converter4.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo4->setNodeValue(tempStr);
    elem_NOT->setAttributeNode(atributo4);

    padre->appendChild(elem_NOT);

}

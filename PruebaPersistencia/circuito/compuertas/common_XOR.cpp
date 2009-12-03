
#include "common_XOR.h"

XOR::XOR(int id, EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida)
: Compuerta(id){

	this->entradas[0] = entrada1;
	this->entradas[1] = entrada2;
	this->salida= salida;
	this->tiempoTransicion= TIEMPOCOMPUERTA;

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

void XOR::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("XOR", tempStr, 99);
    DOMElement*   elem_XOR = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/
    XMLString::transcode("id", tempStr, 99);
    DOMAttr* atributo0 = doc->createAttribute(tempStr);

    std::stringstream converter0;
    converter0 << this->getId();
    aux = converter0.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo0->setNodeValue(tempStr);
    elem_XOR->setAttributeNode(atributo0);

    /******* ATRIBUTO ID-ENTRADA1*****************/
    XMLString::transcode("idEntrada1", tempStr, 99);
    DOMAttr* atributo1 = doc->createAttribute(tempStr);

    std::stringstream converter1;
    converter1 << this->entradas[0]->getId();
    aux = converter1.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo1->setNodeValue(tempStr);
    elem_XOR->setAttributeNode(atributo1);

    /******* ATRIBUTO ID-ENTRADA1*****************/
    XMLString::transcode("idEntrada2", tempStr, 99);
    DOMAttr* atributo2 = doc->createAttribute(tempStr);

    std::stringstream converter2;
    converter2 << this->entradas[1]->getId();
    aux = converter2.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo2->setNodeValue(tempStr);
    elem_XOR->setAttributeNode(atributo2);

    /******* ATRIBUTO ID-SALIDA*****************/
    XMLString::transcode("idSalida", tempStr, 99);
    DOMAttr* atributo3 = doc->createAttribute(tempStr);

    std::stringstream converter3;
    converter3 << this->salida->getId();
    aux = converter3.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo3->setNodeValue(tempStr);
    elem_XOR->setAttributeNode(atributo3);

    /******* ATRIBUTO CONEXION ENTRADA 1*****************/
    XMLString::transcode("conexionE1", tempStr, 99);
    DOMAttr* atributo5 = doc->createAttribute(tempStr);

    std::stringstream converter5;
    converter5 << entradas[0]->getConexion();
    aux = converter5.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo5->setNodeValue(tempStr);
    elem_XOR->setAttributeNode(atributo5);

    /******* ATRIBUTO CONEXION ENTRADA 2*****************/
    XMLString::transcode("conexionE2", tempStr, 99);
    DOMAttr* atributo6 = doc->createAttribute(tempStr);

    std::stringstream converter6;
    converter6 << entradas[1]->getConexion();
    aux = converter6.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo6->setNodeValue(tempStr);
    elem_XOR->setAttributeNode(atributo6);

    padre->appendChild(elem_XOR);

}
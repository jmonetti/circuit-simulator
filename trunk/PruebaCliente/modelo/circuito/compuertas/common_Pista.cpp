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

void Pista::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Pista", tempStr, 99);
    DOMElement*   elem_Pista = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/
    XMLString::transcode("id", tempStr, 99);
    DOMAttr* atributo0 = doc->createAttribute(tempStr);

    std::stringstream converter0;
    converter0 << this->getId();
    aux = converter0.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo0->setNodeValue(tempStr);
    elem_Pista->setAttributeNode(atributo0);

    /******* ATRIBUTO ID-ENTRADA*****************/
    XMLString::transcode("idEntrada", tempStr, 99);
    DOMAttr* atributo1 = doc->createAttribute(tempStr);
    int idEntrada = this->entrada->getId();

    std::stringstream converter1;
    converter1 << idEntrada;
    aux = converter1.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo1->setNodeValue(tempStr);
    elem_Pista->setAttributeNode(atributo1);

    /******* ATRIBUTO ID-SALIDA*****************/
    XMLString::transcode("idSalida", tempStr, 99);
    DOMAttr* atributo2 = doc->createAttribute(tempStr);
    int idSalida = this->salida->getId();

    std::stringstream converter2;
    converter2 << idSalida;
    aux = converter2.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo2->setNodeValue(tempStr);
    elem_Pista->setAttributeNode(atributo2);

    /******* ATRIBUTO CONEXION ENTRADA *****************/
    XMLString::transcode("conexionE", tempStr, 99);
    DOMAttr* atributo3 = doc->createAttribute(tempStr);

    std::stringstream converter3;
    converter3 << entrada->getConexion();
    aux = converter3.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo3->setNodeValue(tempStr);
    elem_Pista->setAttributeNode(atributo3);

    padre->appendChild(elem_Pista);

}

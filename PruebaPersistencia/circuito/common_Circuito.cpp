/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#include "common_Circuito.h"

Circuito::Circuito(int id) {

	this->contadorCompuertas= 0;
	this->contadorEntradasCompuertas= 0;
	this->contadorSalidasCompuertas= 0;
	this->id= id;

}

Circuito::~Circuito() {

	for (unsigned int i = 0; i < compuertas.size(); ++i) {

		delete compuertas[i];

	}

	for (unsigned int var = 0; var < salidasCompuerta.size(); ++var) {

		delete salidasCompuerta[var];

	}

	for (unsigned int var = 0; var < entradasCompuerta.size(); ++var) {

		delete entradasCompuerta[var];

	}

}

bool* Circuito::simular(bool* entradas) {

	this->setearEntradas(entradas);

	this->reset();

	bool* retorno= new bool[salidas.size()];

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->simular();

		retorno[var]= salidas[var]->getValor();

	}

	return retorno;

}

int* Circuito::calcularTiempoTransicion() {

	this->reset();

	int* retorno= new int[salidas.size()];

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->calcularTiempoTransicion();

		retorno[var]= salidas[var]->getTiempoTransicion();

	}

	return retorno;

}

void Circuito::agregarCompuerta(Compuerta* compuerta) {

	Entrada* entrada= compuerta->getEntrada();

	if (entrada) {

		entradas.push_back(entrada);

	} else {

		Salida* salida= compuerta->getSalida();

		if (salida) {

			salidas.push_back(salida);

		}

	}

	compuertas.push_back(compuerta);

	contadorCompuertas++;

}

void Circuito::agregarEntradaCompuerta(EntradaCompuerta* entrada) {

	entradasCompuerta.push_back(entrada);

	contadorEntradasCompuertas++;

}

void Circuito::agregarSalidaCompuerta(SalidaCompuerta* salida) {

	salidasCompuerta.push_back(salida);

	contadorSalidasCompuertas++;

}

unsigned int Circuito::getCantidadEntradas() const{

	return entradas.size();

}

unsigned int Circuito::getCantidadSalidas() const{

	return salidas.size();

}

int Circuito::getContadorCompuertas() {

	return contadorCompuertas;

}

int Circuito::getContadorSalidasCompuerta() {

	return contadorSalidasCompuertas;

}

int Circuito::getContadorEntradasCompuerta() {

	return contadorEntradasCompuertas;

}

void Circuito::conectar(int idSalida,int idEntrada) {

	SalidaCompuerta* salida= NULL;
	EntradaCompuerta* entrada= NULL;

	for (unsigned int var = 0; var < salidasCompuerta.size(); ++var) {

		if (salidasCompuerta[var]->getId() == idSalida) {

			salida= salidasCompuerta[var];
			break;

		}

	}

	for (unsigned int var = 0; var < entradasCompuerta.size(); ++var) {

		if (entradasCompuerta[var] -> getId() == idEntrada) {

			entrada= entradasCompuerta[var];
			break;

		}

	}

	if (entrada && salida) {

		salida->setSalida(entrada);
		entrada->setEntrada(salida);

	}else{
		//TODO
	}

}

int Circuito::getId() const{

	return id;

}

void Circuito::setearEntradas(bool* entradas) {

	for (unsigned int i = 0; i < this->entradas.size(); ++i) {

		this->entradas[i]->setValorEntrada(entradas[i]);

	}

}

void Circuito::reset() {

	for (unsigned int i = 0; i < salidasCompuerta.size(); ++i) {

		salidasCompuerta[i]->reset();

	}

}

void Circuito::guardar(DOMDocument* doc, DOMNode* padre) const{

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Circuito", tempStr, 99);
    DOMElement*   elem_circuito = doc->createElement(tempStr);

    /******* ATRIBUTO ID-ENTRADA*****************/
    XMLString::transcode("id", tempStr, 99);
    DOMAttr* atributo = doc->createAttribute(tempStr);

    std::stringstream converter;
    converter << this->getId();
    aux = converter.str();

    XMLString::transcode(aux.c_str(),tempStr,99);
    atributo->setNodeValue(tempStr);
    elem_circuito->setAttributeNode(atributo);

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		compuertas[var]->guardar(doc, elem_circuito);

	}

	padre->appendChild(elem_circuito);

}



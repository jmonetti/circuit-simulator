/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#include "common_Circuito.h"
#include <iterator>
#include "../../excepciones/common_CircuitoException.h"

Circuito::Circuito(int id,const std::string &nombre) : nombre(nombre) {

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

void Circuito::eliminarCompuerta(int idCompuerta) {

	Compuerta* compuerta= NULL;

	std::vector<Compuerta*>::iterator iterador= compuertas.begin();

	while ( iterador != compuertas.end() ) {

		if ( (*iterador)->getId() == idCompuerta) {

			compuerta= *iterador;
			compuertas.erase(iterador);
			break;

		}else {

			++iterador;

		}

	}

	if (compuerta) {

		//TODO

	}else{

		throw CircuitoException("No se pudo eliminar compuerta. Compuerta invalida");

	}

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

int Circuito::getContadorCompuertas() const{

	return contadorCompuertas;

}

int Circuito::getContadorSalidasCompuerta() const{

	return contadorSalidasCompuertas;

}

int Circuito::getContadorEntradasCompuerta() const{

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

		throw CircuitoException("No se pudo realizar la conexion entre compuertas. Entrada/Salida invalida");

	}

}

void Circuito::desconectar(int idSalida,int idEntrada) {



}

int Circuito::getId() const{

	return id;

}

std::string Circuito::getNombre() const{

	return this->nombre;

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

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		compuertas[var]->guardar(doc, elem_circuito);

	}

	padre->appendChild(elem_circuito);

}

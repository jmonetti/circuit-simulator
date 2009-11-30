/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#include "common_Circuito.h"
#include <iterator>
#include "../../excepciones/common_CircuitoException.h"
#include "../../excepciones/common_ConexionException.h"
#include "common_ManagerConexiones.h"

Circuito::Circuito(int id,const std::string &nombre) : nombre(nombre) {

	this->contadorCompuertas= 0;
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

		try {

			salidas[var]->simular();

		} catch (CircuitoException e) {

			delete[] retorno;

			throw e;
		}

		retorno[var]= salidas[var]->getValor();

	}

	return retorno;

}

int* Circuito::calcularTiempoTransicion() {

	this->reset();

	int* retorno= new int[salidas.size()];

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		try {

			salidas[var]->calcularTiempoTransicion();

		} catch (CircuitoException e) {

			delete[] retorno;

			throw e;

		}


		retorno[var]= salidas[var]->getTiempoTransicion();

	}

	return retorno;

}

void Circuito::mover(int idCompuerta,Posicion posicion) {

	Compuerta* compuerta= obtenerCompuerta(idCompuerta);

	if (compuerta) {

		Posicion posicionAnterior= compuerta->getPosicion();

		compuerta->mover(posicion);

		ManagerConexiones::desconectar(compuerta);

		try {

			verificarConexiones(compuerta);

		} catch (ConexionException e) {

			compuerta->mover(posicion);
			ManagerConexiones::desconectar(compuerta);
			verificarConexiones(compuerta);

			throw e;

		}

	}else {

		throw CircuitoException("No se pudo mover. Compuerta invalida");

	}


}

void Circuito::rotar(int idCompuerta,DIRECCION direccion) {

	Compuerta* compuerta= obtenerCompuerta(idCompuerta);

	if (compuerta) {

		DIRECCION direccionContraria= DERECHA;

		if (direccion == DERECHA) {

			direccionContraria= IZQUIERDA;

		}

		compuerta->rotar(direccion);

		ManagerConexiones::desconectar(compuerta);

		try {

			verificarConexiones(compuerta);

		} catch (ConexionException e) {

			compuerta->rotar(direccionContraria);
			ManagerConexiones::desconectar(compuerta);
			verificarConexiones(compuerta);

			throw e;

		}


	}else {

		throw CircuitoException("No se pudo rotar. Compuerta invalida");

	}

}

void Circuito::agregarCompuerta(Compuerta* compuerta) {

	try {

		agregarEntradasCompuerta(compuerta);
		agregarSalidasCompuerta(compuerta);

	} catch (ConexionException e) {

		eliminarEntradasCompuerta(compuerta);
		eliminarSalidasCompuerta(compuerta);
		delete compuerta;

		throw e;

	}

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

		ManagerConexiones::desconectar(compuerta);

		eliminarEntradasCompuerta(compuerta);

		eliminarSalidasCompuerta(compuerta);

		if (compuerta->getEntrada()) {

			eliminarEntrada(compuerta->getEntrada());

		}else if (compuerta->getSalida()){

			eliminarSalida(compuerta->getSalida());

		}

		delete compuerta;

	}else{

		throw CircuitoException("No se pudo eliminar compuerta. Compuerta invalida");

	}

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

std::vector<Entrada*>& Circuito::getEntradas() {

	return entradas;

}

std::vector<Salida*>& Circuito::getSalidas() {

	return salidas;

}

int Circuito::getId() const{

	return id;

}

std::string Circuito::getNombre() const{

	return this->nombre;

}

void Circuito::guardar(DOMDocument* doc) const{

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("Circuito", tempStr, 99);
    DOMElement*   elem_circuito = doc->createElement(tempStr);

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		compuertas[var]->guardar(doc, elem_circuito);

	}
    DOMNode* nodoDoc = doc->getFirstChild();
	nodoDoc->appendChild(elem_circuito);

}

void Circuito::agregarEntradasCompuerta(Compuerta* compuerta) {

	EntradaCompuerta** entradas= compuerta->getEntradas();

	for (int var = 0; var < compuerta->getCantidadEntradas(); ++var) {

		establecerConexion(entradas[var]);

		entradasCompuerta.push_back(entradas[var]);


	}

}

void Circuito::agregarSalidasCompuerta(Compuerta* compuerta) {

	SalidaCompuerta** salidas= compuerta->getSalidas();

	for (int var = 0; var < compuerta->getCantidadSalidas(); ++var) {

		establecerConexion(salidas[var]);

		salidasCompuerta.push_back(salidas[var]);


	}

}


Compuerta* Circuito::obtenerCompuerta(int idCompuerta) {

	for (unsigned int var = 0; var < compuertas.size(); ++var) {

		if (compuertas[var] -> getId() == idCompuerta) {

			return entradas[var];

		}

	}

	return NULL;

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

void Circuito::verificarConexiones(Compuerta* compuerta) {

	EntradaCompuerta** entradas= compuerta->getEntradas();

	for (int var = 0; var < compuerta->getCantidadEntradas(); ++var) {

		establecerConexion(entradas[var]);

	}

	SalidaCompuerta** salidas= compuerta->getSalidas();

	for (int var = 0; var < compuerta->getCantidadSalidas(); ++var) {

		establecerConexion(salidas[var]);

	}

}


void Circuito::establecerConexion(EntradaCompuerta* entrada) {

	SalidaCompuerta* salida;

	for (unsigned int var = 0; var < salidasCompuerta.size(); ++var) {

		salida= salidasCompuerta[var];

		if (ManagerConexiones::conectar(entrada,salida)) {

			return;

		}

	}

}


void Circuito::establecerConexion(SalidaCompuerta* salida) {

	EntradaCompuerta* entrada;

	for (unsigned int var = 0; var < entradasCompuerta.size(); ++var) {

		entrada= entradasCompuerta[var];

		ManagerConexiones::conectar(entrada,salida);

	}

}

void Circuito::eliminarEntradasCompuerta(Compuerta* compuerta) {

	EntradaCompuerta** entradas= compuerta->getEntradas();

	for (int var = 0; var < compuerta->getCantidadEntradas(); ++var) {

		eliminarEntradaCompuerta(entradas[var]);

	}

}

void Circuito::eliminarSalidasCompuerta(Compuerta* compuerta) {

	SalidaCompuerta** salidas= compuerta->getSalidas();

	for (int var = 0; var < compuerta->getCantidadSalidas(); ++var) {

		eliminarSalidaCompuerta(salidas[var]);

	}

}

void Circuito::eliminarEntradaCompuerta(EntradaCompuerta* entrada) {

	std::vector<EntradaCompuerta*>::iterator iterador= entradasCompuerta.begin();

	while ( iterador != entradasCompuerta.end() ) {

		if ( *iterador == entrada) {

			entradasCompuerta.erase(iterador);
			return;

		}else {

			++iterador;

		}

	}

}

void Circuito::eliminarSalidaCompuerta(SalidaCompuerta* salida) {

	std::vector<SalidaCompuerta*>::iterator iterador= salidasCompuerta.begin();

	while ( iterador != salidasCompuerta.end() ) {

		if ( *iterador == salida) {

			salidasCompuerta.erase(iterador);
			return;

		}else {

			++iterador;

		}

	}

}

void Circuito::eliminarEntrada(Entrada* entrada) {

	std::vector<Entrada*>::iterator iterador= entradas.begin();

	while ( iterador != entradas.end() ) {

		if ( *iterador == entrada) {

			entradas.erase(iterador);
			return;

		}else {

			++iterador;

		}

	}

}

void Circuito::eliminarSalida(Salida* salida) {

	std::vector<Salida*>::iterator iterador= salidas.begin();

	while ( iterador != salidas.end() ) {

		if ( *iterador == salida) {

			salidas.erase(iterador);
			return;

		}else {

			++iterador;

		}

	}

}


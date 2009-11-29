#include "common_CajaNegra.h"

CajaNegra::CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas,Posicion posicion,SENTIDO sentido,
const std::string &nombreCircuito,Servidor servidor) : Compuerta(id,posicion,sentido), nombreCircuito(nombreCircuito), servidor(servidor){

	this->entradas= entradas;
	this->salidas= salidas;

	actualizarEntradas();
	actualizarSalidas();

}

CajaNegra::~CajaNegra() {

	for (unsigned int i = 0; i < entradas.size(); ++i) {

		delete entradas[i];

	}

	for (unsigned int i = 0; i < salidas.size(); ++i) {

		delete salidas[i];

	}
}

void CajaNegra::calcularTiempoTransicion() {

	int* tiempoEntradas= new int[entradas.size()];

	for (unsigned int var = 0; var < entradas.size(); ++var) {

		tiempoEntradas[var]= entradas[var]->calcularTiempoTransicion();

	}

	int* tiempoSalidas= publicacion.calcularTiempoTransicion(nombreCircuito,servidor,tiempoEntradas);

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->setValorSalida(tiempoSalidas[var]);

	}

	delete[] tiempoEntradas;
	delete[] tiempoSalidas;

}

void CajaNegra::simular() {

	bool* valorEntradas= new bool[entradas.size()];

	for (unsigned int var = 0; var < entradas.size(); ++var) {

		valorEntradas[var]= entradas[var]->simular();

	}

	bool* valorSalidas= publicacion.simular(nombreCircuito,servidor,valorEntradas);

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->setValorSalida(valorSalidas[var]);

	}

	delete[] valorEntradas;
	delete[] valorSalidas;

}

TIPO_COMPUERTA CajaNegra::getTipo() const {

	return T_CAJANEGRA;

}


EntradaCompuerta** CajaNegra::getEntradas() {

	return NULL; //TODO entradas._M_allocate(entradas.size());

}

SalidaCompuerta** CajaNegra::getSalidas() {

	return NULL; //TODO salidas._M_allocate(salidas.size());

}

int CajaNegra::getCantidadEntradas() {

	return entradas.size();

}

int CajaNegra::getCantidadSalidas() {

	return salidas.size();

}

void CajaNegra::guardar(DOMDocument* doc, DOMNode* padre) {

	XMLCh tempStr[100];
	std::string aux;

    XMLString::transcode("CajaNegra", tempStr, 99);
    DOMElement*   elem_CajaNegra = doc->createElement(tempStr);

    /******* ATRIBUTO ID*****************/

    aux = "id";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getId());

    /******* ATRIBUTO ENTRADAS*****************/

    aux = "entradas";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,entradas.size());

    /******* ATRIBUTO SALIDAS*****************/

    aux = "salidas";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,salidas.size());

    /******* ATRIBUTO POSICION X *****************/

    aux = "x";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getPosicion().getX());

    /******* ATRIBUTO POSICION Y *****************/

    aux = "y";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getPosicion().getY());

    /******* ATRIBUTO SENTIDO *****************/

    aux = "sentido";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,getSentido());

    /******* ATRIBUTO NOMBRE *****************/

    aux = "nombre";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,nombreCircuito);

    /******* ATRIBUTO PUERTO *****************/

    aux = "puerto";
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,servidor.getPuerto());

    /******* ATRIBUTO HOST *****************/

    aux = "host";
    std::string host = servidor.getHost();
    Persistencia::guardarElemento(doc,elem_CajaNegra,aux,host);

    padre->appendChild(elem_CajaNegra);
}

void CajaNegra::actualizarEntradas() {

}

void CajaNegra::actualizarSalidas() {

}

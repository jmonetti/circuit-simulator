#include "common_OR.h"

OR::OR(int id, int tiempoTransicion, EntradaCompuerta* entrada1,EntradaCompuerta* entrada2, SalidaCompuerta* salida)
: Compuerta(id){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

}

OR::~OR() {

	delete[] entradas;
	delete salida;

}

void OR::actuarSimular(bool* entradas) {

	salida->setValorSalida(entradas[0] || entradas[1]);

}

void OR::actuarTiempo(int tiempo) {

	salida->setTiempoTransicion(tiempo + tiempoTransicion);

}

EntradaCompuerta** OR::getEntradasCompuerta() {

	return entradas;

}

int OR::getCantidadEntradas() {

	return 2;

}

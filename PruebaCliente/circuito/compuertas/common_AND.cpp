
#include "common_AND.h"

AND::AND(int id,int tiempoTransicion,EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida)
: Compuerta(id){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

}

AND::~AND() {

	delete[] entradas;
	delete salida;

}

EntradaCompuerta** AND::getEntradasCompuerta() {

	return entradas;

}

int AND::getCantidadEntradas() {

	return 2;

}

void AND::actuarSimular(bool* entradas) {

	salida->setValorSalida(entradas[0] && entradas[1]);

}

void AND::actuarTiempo(int tiempo) {

	salida->setTiempoTransicion(tiempo + tiempoTransicion);

}

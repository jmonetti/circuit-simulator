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

void NOT::actuarSimular(bool* entradas) {

	salida->setValorSalida(!*entradas);

}

void NOT::actuarTiempo(int tiempo) {

	salida->setTiempoTransicion(tiempo + tiempoTransicion);

}

EntradaCompuerta** NOT::getEntradasCompuerta() {

	return &entrada;

}

int NOT::getCantidadEntradas() {

	return 1;

}

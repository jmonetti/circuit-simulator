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

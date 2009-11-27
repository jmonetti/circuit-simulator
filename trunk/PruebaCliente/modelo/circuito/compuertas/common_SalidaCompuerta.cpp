
#include "common_SalidaCompuerta.h"

SalidaCompuerta::SalidaCompuerta(int id) {

	validoValor= false;
	validoTiempo= false;
	this->id= id;

}

int SalidaCompuerta::calcularTiempoTransicion() {

	if (!validoTiempo) {

		compuerta->calcularTiempoTransicion();

	}


	return tiempoTransicion;

}

bool SalidaCompuerta::simular() {

	if (!validoValor) {

		compuerta->simular();

	}

	return valor;

}

void SalidaCompuerta::reset() {

	validoValor= false;
	validoTiempo= false;

}

void SalidaCompuerta::setValorSalida(bool valor) {

	this->valor = valor;
	validoValor= true;

}

void SalidaCompuerta::setTiempoTransicion(int tiempo) {

	this->tiempoTransicion= tiempo;
	validoTiempo= true;

}

void SalidaCompuerta::setCompuerta(Compuerta* compuerta) {

	this->compuerta= compuerta;

}

void SalidaCompuerta::setSalida(EntradaCompuerta* salida) {

	this->salida= salida;

}

int SalidaCompuerta::getId() {

	return id;

}

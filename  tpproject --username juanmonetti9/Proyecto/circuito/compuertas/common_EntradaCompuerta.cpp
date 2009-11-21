#include "common_EntradaCompuerta.h"

EntradaCompuerta::EntradaCompuerta(int id) {

	this->id= id;

}

int EntradaCompuerta::calcularTiempoTransicion() {

	return entrada->calcularTiempoTransicion();

}

bool EntradaCompuerta::simular() {

	return entrada->simular();

}

void EntradaCompuerta::setCompuerta(Compuerta* compuerta) {

	this->compuerta= compuerta;

}

void EntradaCompuerta::setEntrada(SalidaCompuerta* entrada) {

	this->entrada= entrada;

}

int EntradaCompuerta::getId() {

	return id;

}

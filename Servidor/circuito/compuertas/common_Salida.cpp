#include "common_Salida.h"

Salida::Salida(int id, EntradaCompuerta* entrada) : Compuerta(id) {

	this->entrada= entrada;
	this->tiempoTransicion= 0;

}

Salida::~Salida() {

	delete entrada;

}

void Salida::calcularTiempoTransicion() {

	this->tiempoTransicion= entrada->calcularTiempoTransicion();

}

Salida* Salida::getSalida(){

	return this;

}

void Salida::simular() {

	this->valor= entrada->simular();

}

bool Salida::getValor() {

	return valor;

}

int Salida::getTiempoTransicion() {

	return tiempoTransicion;

}

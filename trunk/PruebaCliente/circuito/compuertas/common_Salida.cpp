#include "common_Salida.h"

Salida::Salida(int id, EntradaCompuerta* entrada) : Compuerta(id) {

	this->entrada= entrada;
	this->tiempoTransicion= 0;

}

Salida::~Salida() {

	delete entrada;

}

Salida* Salida::getSalida(){

	return this;

}

bool Salida::getValor() {

	return valor;

}

int Salida::getTiempoTransicion() {

	return tiempoTransicion;

}

void Salida::actuarSimular(bool* entradas) {

	valor= *entradas;

}

void Salida::actuarTiempo(int tiempo) {

	tiempoTransicion= tiempo;

}

EntradaCompuerta** Salida::getEntradasCompuerta() {

	return &entrada;

}

int Salida::getCantidadEntradas() {

	return 1;

}

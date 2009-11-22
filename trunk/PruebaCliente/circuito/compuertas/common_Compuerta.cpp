#include "common_Compuerta.h"

Compuerta::Compuerta(int id) {

	this->id= id;

}

Entrada* Compuerta::getEntrada(){

	return NULL;

}

Salida* Compuerta::getSalida(){

	return NULL;

}

int Compuerta::getId() {

	return id;

}

void Compuerta::simular() {

	EntradaCompuerta** entradas= getEntradasCompuerta();

	int cantidadEntradas= getCantidadEntradas();

	bool* valores= new bool[cantidadEntradas];

	for (int var = 0; var < cantidadEntradas; ++var) {

		valores[var]= entradas[var]->simular();

	}

	actuarSimular(valores);

	delete[] valores;

}

void Compuerta::calcularTiempoTransicion() {

	EntradaCompuerta** entradas= getEntradasCompuerta();

	int cantidadEntradas= getCantidadEntradas();

	int tiempoMax= 0;

	int aux;

	for (int var = 0; var < cantidadEntradas; ++var) {

		aux= entradas[var]->calcularTiempoTransicion();

		if (tiempoMax < aux) {

			tiempoMax= aux;

		}

	}

	actuarTiempo(tiempoMax);

}

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

void OR::calcularTiempoTransicion() {

	int tiempo1= entradas[0]->calcularTiempoTransicion();
	int tiempo2= entradas[1]->calcularTiempoTransicion();

	if (tiempo1 > tiempo2) {

		this->salida->setTiempoTransicion(tiempo1 + this->tiempoTransicion);

	}else{

		this->salida->setTiempoTransicion(tiempo2 + this->tiempoTransicion);

	}

}

void OR::simular() {

	bool valor1= entradas[0]->simular();
	bool valor2= entradas[1]->simular();

	salida->setValorSalida(valor1 || valor2);

}


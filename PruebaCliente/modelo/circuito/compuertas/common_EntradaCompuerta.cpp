#include "common_EntradaCompuerta.h"
#include "../../../excepciones/common_CircuitoException.h"

EntradaCompuerta::EntradaCompuerta(int id) {

	this->id= id;

}

int EntradaCompuerta::calcularTiempoTransicion() {

	if (!entrada) {

		throw CircuitoException("Circuito Incompleto");

	}


	return entrada->calcularTiempoTransicion();

}

bool EntradaCompuerta::simular() {

	if (!entrada) {

		throw CircuitoException("Circuito Incompleto");

	}


	return entrada->simular();

}

void EntradaCompuerta::setEntrada(SalidaCompuerta* entrada) {

	this->entrada= entrada;

}

int EntradaCompuerta::getId() {

	return id;

}

int EntradaCompuerta::getConexion() {

	if (entrada) {

		return entrada->getId();

	}

	return -1;

}


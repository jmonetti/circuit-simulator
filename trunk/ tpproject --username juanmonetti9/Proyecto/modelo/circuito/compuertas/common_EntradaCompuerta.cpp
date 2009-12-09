#include "common_EntradaCompuerta.h"
#include "../../../excepciones/common_CircuitoException.h"
#include "../../../excepciones/common_ConexionException.h"

EntradaCompuerta::EntradaCompuerta() {

	entrada= NULL;

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

void EntradaCompuerta::mover(Posicion posicion) {

	this->posicion= posicion;

}

void EntradaCompuerta::rotar(SENTIDO sentido) {

	this->sentido= sentido;

}

void EntradaCompuerta::conectar(SalidaCompuerta* entrada) {

	if (this->entrada) {

		throw ConexionException("No se pudo conectar. Ya tiene una entrada asignada");

	}

	this->entrada= entrada;

}

void EntradaCompuerta::desconectar() {

	this->entrada= NULL;

}

SalidaCompuerta* EntradaCompuerta::getConexion() {

	return entrada;

}

Posicion EntradaCompuerta::getPosicion() const{

	return posicion;

}

SENTIDO EntradaCompuerta::getSentido() const{

	return sentido;

}

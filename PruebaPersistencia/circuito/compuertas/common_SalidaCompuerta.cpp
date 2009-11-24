
#include "common_SalidaCompuerta.h"
#include "common_EntradaCompuerta.h"

SalidaCompuerta::SalidaCompuerta(int id) {

	validoValor= false;
	validoTiempo= false;
	this->id= id;

}

int SalidaCompuerta::calcularTiempoTransicion() {

	if (!validoTiempo) {

		compuerta->calcularTiempoTransicion();

	}

	validoTiempo= true;
	return tiempoTransicion;

}

bool SalidaCompuerta::simular() {

	if (!validoValor) {

		compuerta->simular();

	}

	validoValor= true;
	return valor;

}

void SalidaCompuerta::reset() {

	validoValor= false;
	validoTiempo= false;

}

void SalidaCompuerta::setValorSalida(bool valor) {

	this->valor = valor;

}

void SalidaCompuerta::setTiempoTransicion(int tiempo) {

	this->tiempoTransicion= tiempo;

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

void SalidaCompuerta::guardar(DOMDocument* doc, DOMNode* padre) {

    this->compuerta->guardar(doc, padre);

}

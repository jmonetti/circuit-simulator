#include "common_EntradaCompuerta.h"
#include "common_SalidaCompuerta.h"

EntradaCompuerta::EntradaCompuerta(int id) {

	this->id= id;

}

int EntradaCompuerta::calcularTiempoTransicion() {

	return entrada->calcularTiempoTransicion();

}

bool EntradaCompuerta::simular() {

	return entrada->simular();

}

void EntradaCompuerta::setEntrada(SalidaCompuerta* entrada) {

	this->entrada= entrada;

}

int EntradaCompuerta::getId() {

	return id;

}

int EntradaCompuerta::getConexion() {

	return entrada->getId();
}

void EntradaCompuerta::guardar(DOMDocument* doc, DOMNode* padre) {

    this->entrada->guardar(doc, padre);

}

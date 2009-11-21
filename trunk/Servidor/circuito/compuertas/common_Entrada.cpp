
#include "common_Entrada.h"

Entrada::Entrada(int id,SalidaCompuerta* salida) : Compuerta(id){

	this->salida= salida;

}

Entrada::~Entrada() {

	delete salida;

}

void Entrada::calcularTiempoTransicion() {

	this->salida->setTiempoTransicion(0);

}

Entrada* Entrada::getEntrada(){

	return this;

}

void Entrada::simular() {

	this->salida->setValorSalida(valor);

}

void Entrada::setValorEntrada(bool valor) {

	this->valor= valor;

}

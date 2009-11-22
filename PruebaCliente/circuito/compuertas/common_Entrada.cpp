
#include "common_Entrada.h"

Entrada::Entrada(int id,SalidaCompuerta* salida) : Compuerta(id){

	this->salida= salida;

}

Entrada::~Entrada() {

	delete salida;

}

Entrada* Entrada::getEntrada(){

	return this;

}

void Entrada::setValorEntrada(bool valor) {

	this->valor= valor;

}

void Entrada::actuarSimular(bool* entradas) {

	salida->setValorSalida(valor);

}

void Entrada::actuarTiempo(int tiempo) {

	salida->setTiempoTransicion(tiempo);

}

EntradaCompuerta** Entrada::getEntradasCompuerta() {

	return NULL;

}

int Entrada::getCantidadEntradas() {

	return 0;

}


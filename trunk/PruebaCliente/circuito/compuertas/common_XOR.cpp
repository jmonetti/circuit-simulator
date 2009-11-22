
#include "common_XOR.h"

XOR::XOR(int id, int tiempoTransicion, EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida)
: Compuerta(id){

	this->entradas[0] = entrada1;
	this->entradas[1] = entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

}

XOR::~XOR() {

	delete[] entradas;
	delete salida;

}

void XOR::actuarSimular(bool* entradas) {

	salida->setValorSalida(entradas[0] ^ entradas[1]);

}

void XOR::actuarTiempo(int tiempo) {

	salida->setTiempoTransicion(tiempo + tiempoTransicion);

}

EntradaCompuerta** XOR::getEntradasCompuerta() {

	return entradas;

}

int XOR::getCantidadEntradas() {

	return 2;

}

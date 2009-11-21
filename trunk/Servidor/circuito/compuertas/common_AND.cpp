
#include "common_AND.h"

AND::AND(int id,int tiempoTransicion,EntradaCompuerta* entrada1, EntradaCompuerta* entrada2, SalidaCompuerta* salida)
: Compuerta(id){

	this->entradas[0]= entrada1;
	this->entradas[1]= entrada2;
	this->salida= salida;
	this->tiempoTransicion= tiempoTransicion;

}

AND::~AND() {

	delete[] entradas;
	delete salida;

}

void AND::calcularTiempoTransicion() {


	int tiempoEntrada1= entradas[0]->calcularTiempoTransicion();
	int tiempoEntrada2= entradas[1]->calcularTiempoTransicion();

	if (tiempoEntrada1 > tiempoEntrada2) {

		salida->setTiempoTransicion(tiempoEntrada1 + this->tiempoTransicion);

	}else{

		salida->setTiempoTransicion(tiempoEntrada2 + this->tiempoTransicion);

	}


}

void AND::simular() {

	bool entrada1= entradas[0]->simular();
	bool entrada2= entradas[1]->simular();

	salida->setValorSalida(entrada1 && entrada2);

}


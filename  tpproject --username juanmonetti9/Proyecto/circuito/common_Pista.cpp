/**************************   Clase Pista **************************************/
/**************************     Grupo 8   **************************************/

#include "common_Pista.h"

Pista::Pista(int id, EntradaCompuerta* entrada, SalidaCompuerta* salida) : Compuerta(id){

	this->entrada= entrada;
	this->salida= salida;

}

Pista::~Pista() {

	delete entrada;
	delete salida;

}

void Pista::calcularTiempoTransicion() {

	int tiempo= entrada->calcularTiempoTransicion();

	salida->setTiempoTransicion(tiempo);

}

void Pista::simular() {

	salida->setValorSalida(entrada->simular());

}

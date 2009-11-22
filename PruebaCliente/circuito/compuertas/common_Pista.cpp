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

void Pista::actuarSimular(bool* entradas) {

	salida->setValorSalida(*entradas);

}

void Pista::actuarTiempo(int tiempo) {

	salida->setTiempoTransicion(tiempo);

}

EntradaCompuerta** Pista::getEntradasCompuerta() {

	return &entrada;

}

int Pista::getCantidadEntradas() {

	return 1;

}

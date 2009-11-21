#include "common_ResultadoTiempo.h"

ResultadoTiempo::ResultadoTiempo(int* tiempos,unsigned int cantidad) {

	this->tiempos= tiempos;
	this->cantidad= cantidad;

}

ResultadoTiempo::~ResultadoTiempo() {

	delete[] tiempos;

}

int* ResultadoTiempo::getTiempos() {

	return tiempos;

}

unsigned int ResultadoTiempo::getCantidad() const {

	return cantidad;

}

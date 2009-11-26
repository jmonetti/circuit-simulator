
#include "common_ResultadoSimulacion.h"

ResultadoSimulacion::ResultadoSimulacion(bool* entradas, bool* salidas,unsigned int cantEntradas,unsigned int cantSalidas) {

	this->entradas= entradas;
	this->salidas= salidas;

	this->cantEntradas= cantEntradas;
	this->cantSalidas= cantSalidas;

}

ResultadoSimulacion::~ResultadoSimulacion() {

	delete[] entradas;
	delete[] salidas;

}

bool* ResultadoSimulacion::getEntradas() {

	return entradas;

}

bool* ResultadoSimulacion::getSalidas() {

	return salidas;

}

unsigned int ResultadoSimulacion::getCantidadEntradas() const{

	return cantEntradas;

}

unsigned int ResultadoSimulacion::getCantidadSalidas() const {

	return cantSalidas;

}

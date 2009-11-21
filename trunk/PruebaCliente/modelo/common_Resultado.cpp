
#include "common_Resultado.h"

Resultado::Resultado(bool* entradas, bool* salidas,unsigned int cantEntradas,unsigned int cantSalidas) {

	this->entradas= entradas;
	this->salidas= salidas;

	this->cantEntradas= cantEntradas;
	this->cantSalidas= cantSalidas;

}

Resultado::~Resultado() {

	delete[] entradas;
	delete[] salidas;

}

bool* Resultado::getEntradas() {

	return entradas;

}

bool* Resultado::getSalidas() {

	return salidas;

}

unsigned int Resultado::getCantidadEntradas() const{

	return cantEntradas;

}

unsigned int Resultado::getCantidadSalidas() const {

	return cantSalidas;

}

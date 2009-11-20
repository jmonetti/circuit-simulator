
#include "common_Resultado.h"

Resultado::Resultado(bool* entradas, bool* salidas) {

	this->entradas= entradas;
	this->salidas= salidas;

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

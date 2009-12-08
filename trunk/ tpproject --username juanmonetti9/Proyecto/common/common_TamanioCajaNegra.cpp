#include "common_TamanioCajaNegra.h"

TamanioCajaNegra::TamanioCajaNegra(int cantEntradas,int cantSalidas) {

	this->cantEntradas= cantEntradas;
	this->cantSalidas= cantSalidas;

}

TamanioCajaNegra::~TamanioCajaNegra() {

}

int TamanioCajaNegra::getCantEntradas() const{

	return cantEntradas;

}

int TamanioCajaNegra::getCantSalidas() const{

	return cantSalidas;

}

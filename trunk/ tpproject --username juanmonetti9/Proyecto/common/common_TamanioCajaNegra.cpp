#include "common_TamanioCajaNegra.h"

TamanioCajaNegra::TamanioCajaNegra(int cantEntradas,int cantSalidas) {

	this->cantEntradas= cantEntradas;
	this->cantSalidas= cantSalidas;

}

int TamanioCajaNegra::getCantEntradas() const{

	return cantEntradas;

}

int TamanioCajaNegra::getCantSalidas() const{

	return cantSalidas;

}

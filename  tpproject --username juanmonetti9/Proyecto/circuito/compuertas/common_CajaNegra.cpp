#include "common_CajaNegra.h"

CajaNegra::CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas)
: Compuerta(id){

	this->entradas= entradas;
	this->salidas= salidas;

}

CajaNegra::~CajaNegra() {

	for (unsigned int i = 0; i < entradas.size(); ++i) {

		delete entradas[i];

	}

	for (unsigned int i = 0; i < salidas.size(); ++i) {

		delete salidas[i];

	}
}

void CajaNegra::calcularTiempoTransicion() {

	//TODO

}

void CajaNegra::simular() {

	//TODO

}

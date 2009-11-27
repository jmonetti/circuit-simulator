#include "common_CajaNegra.h"

CajaNegra::CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas,Posicion posicion,SENTIDO sentido,
const std::string &nombreCircuito,Servidor servidor) : Compuerta(id,posicion,sentido), nombreCircuito(nombreCircuito), servidor(servidor){

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

	int* tiempoEntradas= new int[entradas.size()];

	for (unsigned int var = 0; var < entradas.size(); ++var) {

		tiempoEntradas[var]= entradas[var]->calcularTiempoTransicion();

	}

	int* tiempoSalidas= publicacion.calcularTiempoTransicion(nombreCircuito,servidor,tiempoEntradas);

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->setValorSalida(tiempoSalidas[var]);

	}

	delete[] tiempoEntradas;
	delete[] tiempoSalidas;

}

void CajaNegra::simular() {

	bool* valorEntradas= new bool[entradas.size()];

	for (unsigned int var = 0; var < entradas.size(); ++var) {

		valorEntradas[var]= entradas[var]->simular();

	}

	bool* valorSalidas= publicacion.simular(nombreCircuito,servidor,valorEntradas);

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->setValorSalida(valorSalidas[var]);

	}

	delete[] valorEntradas;
	delete[] valorSalidas;

}

TIPO_COMPUERTA CajaNegra::getTipo() const {

	return T_CAJANEGRA;

}

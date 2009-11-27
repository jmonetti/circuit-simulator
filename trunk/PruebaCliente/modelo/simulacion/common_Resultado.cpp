#include "common_Resultado.h"

Resultado::Resultado(std::vector<ResultadoSimulacion*>* resultadoSimulacion,ResultadoTiempo* resultadoTiempo) {

	this->resultadoSimulacion= resultadoSimulacion;
	this->resultadoTiempo= resultadoTiempo;

}

Resultado::~Resultado() {

	delete resultadoTiempo;

	for (unsigned int var = 0; var < resultadoSimulacion->size(); ++var) {

		delete (*resultadoSimulacion)[var];

	}

	delete resultadoSimulacion;

}

std::vector<ResultadoSimulacion*>* Resultado::getResultadoSimulacion() {

	return resultadoSimulacion;

}

ResultadoTiempo* Resultado::getResultadoTiempo() {

	return resultadoTiempo;

}

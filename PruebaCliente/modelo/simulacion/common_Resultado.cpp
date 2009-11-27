#include "common_Resultado.h"

Resultado::Resultado(std::vector<ResultadoSimulacion*>* resultadoSimulacion,ResultadoTiempo* resultadoTiempo,
std::vector<std::string>* nombreEntradas, std::vector<std::string>* nombreSalidas) {

	this->resultadoSimulacion= resultadoSimulacion;
	this->resultadoTiempo= resultadoTiempo;
	this->nombreEntradas= nombreEntradas;
	this->nombreSalidas= nombreSalidas;

}

Resultado::~Resultado() {

	delete resultadoTiempo;

	for (unsigned int var = 0; var < resultadoSimulacion->size(); ++var) {

		delete (*resultadoSimulacion)[var];

	}

	delete resultadoSimulacion;

	delete nombreEntradas;

	delete nombreSalidas;

}

std::vector<ResultadoSimulacion*>* Resultado::getResultadoSimulacion() {

	return resultadoSimulacion;

}

ResultadoTiempo* Resultado::getResultadoTiempo() {

	return resultadoTiempo;

}

std::vector<std::string>* Resultado::getNombreEntradas() {

	return nombreEntradas;

}

std::vector<std::string>* Resultado::getNombreSalidas() {

	return nombreSalidas;

}

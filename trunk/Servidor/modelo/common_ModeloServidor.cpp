
#include "common_ModeloServidor.h"

ModeloServidor::ModeloServidor() {
	// TODO Auto-generated constructor stub

}

ModeloServidor::~ModeloServidor() {

	// TODO Auto-generated destructor stub

}

void ModeloServidor::guardar() {

}

void ModeloServidor::recuperar() {

}

bool* ModeloServidor::simular(const std::string &nombreCircuito,bool* entradas) {

	Circuito* circuito= persistencia.recuperar(nombreCircuito);

	bool* salidas= circuito->simular(entradas);

	delete circuito;

	return salidas;

}

int* ModeloServidor::calcularTiempoTransicion(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(nombreCircuito);

	int* tiempos= circuito->calcularTiempoTransicion();

	delete tiempos;

	return tiempos;

}

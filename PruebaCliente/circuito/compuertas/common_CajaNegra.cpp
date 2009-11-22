#include "common_CajaNegra.h"
#include "../../modelo/common_ResultadoSimulacion.h"

CajaNegra::CajaNegra(int id,std::vector<EntradaCompuerta*> &entradas, std::vector<SalidaCompuerta*> &salidas,Servidor &servidor)
: Compuerta(id), servidor(servidor){

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

void CajaNegra::actuarSimular(bool* entradas) {

	bool* resultado= publicacion.simular(nombre,servidor,entradas);

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->setValorSalida(resultado[var]);

	}

}

EntradaCompuerta** CajaNegra::getEntradasCompuerta() {

	return entradas._M_allocate(entradas.size());

}

int CajaNegra::getCantidadEntradas() {

	return entradas.size();

}



#include "common_ModeloCliente.h"
#include "../circuito/common_FactoryCompuerta.h"

ModeloCliente::ModeloCliente() {

	contadorId= 0;

}

ModeloCliente::~ModeloCliente() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}
}

int ModeloCliente::crearNuevo() {

	Circuito* circuito= new Circuito(contadorId);
	circuitos.push_back(circuito);
	contadorId++;
	return contadorId - 1;

}

int ModeloCliente::agregarCompuerta(int idCircuito,TIPO_COMPUERTA tipo,int tiempoTransicion) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	int idCompuerta= circuito->getContadorCompuertas();

	FactoryCompuerta::crearCompuerta(tipo, *circuito, tiempoTransicion);

	return idCompuerta;

}


std::vector<ResultadoSimulacion*>* ModeloCliente::simular(int idCircuito) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	return simulador.simular(*circuito);

}

ResultadoTiempo* ModeloCliente::calcularTiempoTransicion(int idCircuito) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	return new ResultadoTiempo(circuito->calcularTiempoTransicion(),circuito->getCantidadSalidas());

}

void ModeloCliente::conectar(int idCircuito,int idSalida,int idEntrada) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	circuito->conectar(idSalida,idEntrada);

}

void ModeloCliente::guardar(int idCircuito) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	persistencia.guardar(*circuito);

}

void ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(nombreCircuito);

	circuitos.push_back(circuito);

}

void ModeloCliente::enviar(const std::string &nombreCircuito,const Servidor &servidor) {

	publicacion.enviar(nombreCircuito,servidor);

}

CajaNegra* ModeloCliente::recibir(const std::string &nombreCircuito,const Servidor &servidor) {

	return publicacion.recibir(nombreCircuito,servidor);

}

Circuito* ModeloCliente::obtenerCircuito(int idCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (circuitos[var]->getId() == idCircuito) {

			return circuitos[var];

		}

	}

	return NULL;

}

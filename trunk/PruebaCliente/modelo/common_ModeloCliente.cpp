
#include "common_ModeloCliente.h"
#include <iterator>
#include "circuito/common_FactoryCompuerta.h"

ModeloCliente::ModeloCliente() {

	contadorId= 0;

}

ModeloCliente::~ModeloCliente() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}
}

void ModeloCliente::crearNuevo() {

	Circuito* circuito= new Circuito(contadorId);
	circuitos.push_back(circuito);
	contadorId++;

}

void ModeloCliente::eliminar(int idCircuito) {

	std::vector<Circuito*>::iterator iterador= circuitos.begin();

	while (iterador != circuitos.end()) {

		Circuito* circuito= *iterador;

		if (circuito->getId() == idCircuito) {

			iterador= circuitos.erase(iterador);
			delete circuito;
			return;

		}else{

			++iterador;

		}

	}

}

void ModeloCliente::agregarCompuerta(int idCircuito,TIPO_COMPUERTA tipo,int tiempoTransicion) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	FactoryCompuerta::crearCompuerta(tipo, *circuito, tiempoTransicion);

}

void ModeloCliente::eliminarCompuerta(int idCircuito,int idCompuerta) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	circuito->eliminarCompuerta(idCompuerta);

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

void ModeloCliente::guardar(int idCircuito, std::string &ruta) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	persistencia.guardar(*circuito, ruta);

}

void ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(contadorId, nombreCircuito);

	circuitos.push_back(circuito);

}

void ModeloCliente::enviar(const std::string &nombreCircuito,const Servidor &servidor) {

	publicacion.enviar(nombreCircuito,servidor);

}

void ModeloCliente::recibir(int idCircuito, const std::string &nombreCircuito,const Servidor &servidor) {

	CajaNegra* compuerta= publicacion.recibir(nombreCircuito,servidor);

	Circuito* circuito= obtenerCircuito(idCircuito);

	circuito->agregarCompuerta(compuerta);

}

Circuito* ModeloCliente::obtenerCircuito(int idCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (circuitos[var]->getId() == idCircuito) {

			return circuitos[var];

		}

	}

	return NULL;

}

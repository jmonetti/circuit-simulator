
#include "common_ModeloCliente.h"
#include <iterator>
#include "circuito/common_FactoryCompuerta.h"
#include "../excepciones/common_CircuitoException.h"

#include <iostream>

ModeloCliente::ModeloCliente() {

	contadorId= 0;
	circuitoActual= NULL;

}

ModeloCliente::~ModeloCliente() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}
}

int ModeloCliente::crearNuevo(const std::string &nombre) {

	Circuito* circuito= new Circuito(contadorId,nombre);
	circuitos.push_back(circuito);
	circuitoActual= circuito;
	contadorId++;

	return contadorId - 1;
}

void ModeloCliente::cambiarCircuitoActual(int idCircuito) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	if (circuito) {

		circuitoActual= circuito;

	}else {

		throw CircuitoException("No se pudo cambiar circuito actual. Circuito Invalido");

	}

}

void ModeloCliente::eliminar() {

	std::vector<Circuito*>::iterator iterador= circuitos.begin();

	while (iterador != circuitos.end()) {

		if (*iterador == circuitoActual) {

			circuitos.erase(iterador);
			delete circuitoActual;
			circuitoActual= NULL;
			return;

		}else{

			++iterador;

		}

	}

}

int ModeloCliente::agregarCompuerta(TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido) {

	return FactoryCompuerta::crearCompuerta(tipo, *circuitoActual, posicion,sentido);

}

int ModeloCliente::agregarEntrada(Posicion posicion, const string &nombre, SENTIDO sentido) {

	std::cout<<"agregarentrada"<<std::endl;
	return FactoryCompuerta::crearEntrada(*circuitoActual,posicion,nombre,sentido);

}

int ModeloCliente::agregarSalida(Posicion posicion, const string &nombre, SENTIDO sentido) {

	std::cout<<"agregarsalida"<<std::endl;
	return FactoryCompuerta::crearSalida(*circuitoActual,posicion,nombre,sentido);

}




void ModeloCliente::eliminarCompuerta(int idCompuerta) {

	circuitoActual->eliminarCompuerta(idCompuerta);

}


Resultado* ModeloCliente::simular() {

	return simulador.simular(*circuitoActual);

}

void ModeloCliente::rotar(int idCompuerta,DIRECCION direccion) {

	circuitoActual->rotar(idCompuerta, direccion);

}

void ModeloCliente::mover(int idCompuerta,Posicion posicion) {

	circuitoActual->mover(idCompuerta,posicion);

}

void ModeloCliente::guardar() {

	std::cout<<"guardar"<<std::endl;

	persistencia.guardar(*circuitoActual);

}

int ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(contadorId, nombreCircuito);

	circuitos.push_back(circuito);

	circuitoActual= circuito;

	contadorId++;

	return contadorId - 1;

}

void ModeloCliente::enviar(const std::string &nombreCircuito,Servidor servidor) {

	publicacion.enviar(nombreCircuito,servidor);

}

int ModeloCliente::recibir(const std::string &nombreCircuito,Servidor servidor) {

	CajaNegra* compuerta= publicacion.recibir(nombreCircuito,servidor);

	return circuitoActual->agregarCompuerta(compuerta);

}

Circuito* ModeloCliente::obtenerCircuito(int idCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (circuitos[var]->getId() == idCircuito) {

			return circuitos[var];

		}

	}

	return NULL;

}

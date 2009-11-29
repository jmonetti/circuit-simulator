
#include "common_ModeloCliente.h"
#include <iterator>
#include "circuito/common_FactoryCompuerta.h"
#include "../excepciones/common_CircuitoException.h"

ModeloCliente::ModeloCliente() {

	contadorId= 0;
	circuitoActual= NULL;

}

ModeloCliente::~ModeloCliente() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}
}

void ModeloCliente::crearNuevo(const std::string &nombre) {

	Circuito* circuito= new Circuito(contadorId,nombre);
	circuitos.push_back(circuito);
	circuitoActual= circuito;
	contadorId++;

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

void ModeloCliente::agregarCompuerta(TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido) {

	FactoryCompuerta::crearCompuerta(tipo, *circuitoActual, posicion,sentido);

}

void ModeloCliente::agregarEntrada(Posicion posicion, const string &nombre, SENTIDO sentido) {

	FactoryCompuerta::crearEntrada(*circuitoActual,posicion,nombre,sentido);

}

void ModeloCliente::agregarSalida(Posicion posicion, const string &nombre, SENTIDO sentido) {

	FactoryCompuerta::crearSalida(*circuitoActual,posicion,nombre,sentido);

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

	persistencia.guardar(*circuitoActual);

}

void ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(contadorId, nombreCircuito);

	circuitos.push_back(circuito);

	circuitoActual= circuito;

	contadorId++;

}

void ModeloCliente::enviar(const std::string &nombreCircuito,Servidor servidor) {

	publicacion.enviar(nombreCircuito,servidor);

}

void ModeloCliente::recibir(const std::string &nombreCircuito,Servidor servidor) {

	CajaNegra* compuerta= publicacion.recibir(nombreCircuito,servidor);

	circuitoActual->agregarCompuerta(compuerta);

}

Circuito* ModeloCliente::obtenerCircuito(int idCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (circuitos[var]->getId() == idCircuito) {

			return circuitos[var];

		}

	}

	return NULL;

}

int ModeloCliente::getUltimo() const {

	return contadorId-1;

}

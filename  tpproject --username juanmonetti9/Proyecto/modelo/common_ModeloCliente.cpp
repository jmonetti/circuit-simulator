
#include "common_ModeloCliente.h"
#include <iterator>
#include "circuito/common_FactoryCompuerta.h"
#include "../excepciones/common_CircuitoException.h"
#include "../common/common_Utils.h"

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


	return FactoryCompuerta::crearEntrada(*circuitoActual,posicion,nombre,sentido);

}

int ModeloCliente::agregarSalida(Posicion posicion, const string &nombre, SENTIDO sentido) {


	return FactoryCompuerta::crearSalida(*circuitoActual,posicion,nombre,sentido);

}


int ModeloCliente::agregarCajaNegra(Posicion posicion,const std::string &nombre, SENTIDO sentido,Servidor servidor, TamanioCajaNegra tamanio) {

	return FactoryCompuerta::crearCajaNegra(*circuitoActual, posicion, nombre, sentido, servidor, tamanio.getCantEntradas(),tamanio.getCantSalidas());

}

void ModeloCliente::eliminarCompuerta(int idCompuerta) {

	circuitoActual->eliminarCompuerta(idCompuerta);

}


Resultado* ModeloCliente::simular() {

	if (circuitoActual) {

		return simulador.simular(*circuitoActual);

	}

	throw CircuitoException("No existe circuito para simular");

}

void ModeloCliente::rotar(int idCompuerta,DIRECCION direccion) {

	circuitoActual->rotar(idCompuerta, direccion);

}

void ModeloCliente::mover(int idCompuerta,Posicion posicion) {

	circuitoActual->mover(idCompuerta,posicion);

}

void ModeloCliente::guardar() {

	if (circuitoActual) {

		persistencia.guardarCircuito(*circuitoActual);

	}else {

		throw CircuitoException("No hay circuito para guardar");
	}

}

std::vector<char*>* ModeloCliente::obtenerCircuitosGuardados() {

	std::vector<char*>* circuitos= new std::vector<char*>();

	Utils::obtenerArchivos(PATH_SAVES,circuitos);

	return circuitos;

}

void ModeloCliente::obtenerCircuitosServidor(Servidor servidor, std::vector<char*>* circuitos) {

	return publicacion.obtenerCircuitos(servidor,circuitos);

}

Circuito* ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(contadorId, nombreCircuito);

	circuitos.push_back(circuito);

	circuitoActual= circuito;

	contadorId++;

	return circuito;

}

void ModeloCliente::enviar(const std::string &nombreCircuito,Servidor servidor) {

	publicacion.enviar(nombreCircuito,servidor);

}

TamanioCajaNegra ModeloCliente::recibir(const std::string &nombreCircuito,Servidor servidor) {

	return publicacion.recibir(nombreCircuito,servidor);

}

int ModeloCliente::getId() {

	return contadorId;

}

bool ModeloCliente::hayCircuito() {

	return circuitoActual;

}

void ModeloCliente::getConexionVertice(int idCompuerta,std::vector<ConexionVertice>* conexiones) {

	circuitoActual->getConexionVertice(idCompuerta,conexiones);

}

Circuito* ModeloCliente::obtenerCircuito(int idCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (circuitos[var]->getId() == idCircuito) {

			return circuitos[var];

		}

	}

	return NULL;

}


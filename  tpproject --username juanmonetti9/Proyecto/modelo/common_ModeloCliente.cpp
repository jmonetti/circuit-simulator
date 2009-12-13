
#include "common_ModeloCliente.h"
#include <iterator>
#include "circuito/common_FactoryCompuerta.h"
#include "../excepciones/common_CircuitoException.h"
#include "../common/common_Utils.h"
#include "circuito/compuertas/common_CajaNegra.h"

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

	if (circuitoActual) {

		return FactoryCompuerta::crearCompuerta(tipo, *circuitoActual, posicion,sentido);

	}

	throw CircuitoException("No existe circuito para agregar compuerta");

}

int ModeloCliente::agregarEntrada(Posicion posicion, const string &nombre, SENTIDO sentido) {

	if (circuitoActual) {

		return FactoryCompuerta::crearEntrada(*circuitoActual,posicion,nombre,sentido);

	}

	throw CircuitoException("No existe circuito para agregar compuerta");

}

int ModeloCliente::agregarSalida(Posicion posicion, const string &nombre, SENTIDO sentido) {

	if (circuitoActual) {

		return FactoryCompuerta::crearSalida(*circuitoActual,posicion,nombre,sentido);

	}

	throw CircuitoException("No existe circuito para agregar compuerta");

}


int ModeloCliente::agregarCajaNegra(Posicion posicion,const std::string &nombre, SENTIDO sentido,Servidor servidor, TamanioCajaNegra tamanio) {

	if (circuitoActual) {

		return FactoryCompuerta::crearCajaNegra(*circuitoActual, posicion, nombre, sentido, servidor, tamanio);

	}

	throw CircuitoException("No existe circuito para agregar compuerta");

}

void ModeloCliente::eliminarCompuerta(int idCompuerta) {

	if (circuitoActual) {

		circuitoActual->eliminarCompuerta(idCompuerta);

	}else {

		throw CircuitoException("No existe circuito para eliminar compuerta");

	}

}


Resultado* ModeloCliente::simular() {

	if (circuitoActual) {

		return simulador.simular(*circuitoActual);

	}

	throw CircuitoException("No existe circuito para simular");

}

void ModeloCliente::rotar(int idCompuerta,DIRECCION direccion) {

	if (circuitoActual) {

		circuitoActual->rotar(idCompuerta, direccion);

	}else {

		throw CircuitoException("No existe circuito para rotar compuerta");

	}

}

void ModeloCliente::mover(int idCompuerta,Posicion posicion) {

	if (circuitoActual) {

		circuitoActual->mover(idCompuerta,posicion);

	}else {

		throw CircuitoException("No existe circuito para mover compuerta");

	}

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
	Utils::obtenerArchivos(PATH_SAVES.c_str(),circuitos);
	return circuitos;

}

void ModeloCliente::obtenerCircuitosServidor(Servidor servidor, std::vector<char*>* circuitos) {

	return publicacion.obtenerCircuitos(servidor,circuitos);

}

Circuito* ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperarCircuito(contadorId, nombreCircuito);

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

Circuito* ModeloCliente::obtenerCircuitoServidor(int id) {

	Compuerta* compuerta= circuitoActual->obtenerCompuerta(id);

	if (compuerta->getTipo() == T_CAJANEGRA) {

		CajaNegra* cajaNegra= (CajaNegra*) compuerta;
		return publicacion.verCajaNegra(cajaNegra->getNombre(),cajaNegra->getServidor());

	}else{

		throw CircuitoException ("Error al obtener circuito del servidor. No es Caja Negra");

	}

}

int ModeloCliente::getId() {

	return contadorId;

}

bool ModeloCliente::hayCircuito() {

	return circuitoActual;

}

void ModeloCliente::getConexionVertice(std::vector<ConexionVertice>* conexiones) {

	circuitoActual->getConexionVertice(conexiones);

}

std::vector<Compuerta*>& ModeloCliente::getCompuertas() {

	return circuitoActual->getCompuertas();

}

Circuito* ModeloCliente::obtenerCircuito(int idCircuito) {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		if (circuitos[var]->getId() == idCircuito) {

			return circuitos[var];

		}

	}

	return NULL;

}


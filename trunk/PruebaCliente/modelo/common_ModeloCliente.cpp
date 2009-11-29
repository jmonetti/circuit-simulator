
#include "common_ModeloCliente.h"
#include <iterator>
#include "circuito/common_FactoryCompuerta.h"
#include "../excepciones/common_CircuitoException.h"

ModeloCliente::ModeloCliente() {

	contadorId= 0;

}

ModeloCliente::~ModeloCliente() {

	for (unsigned int var = 0; var < circuitos.size(); ++var) {

		delete circuitos[var];

	}
}

void ModeloCliente::crearNuevo(const std::string &nombre) {

	Circuito* circuito= new Circuito(contadorId,nombre);
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

	throw CircuitoException("No se pudo eliminar el circuito. Circuito invalido");

}

void ModeloCliente::agregarCompuerta(int idCircuito,TIPO_COMPUERTA tipo,Posicion posicion,SENTIDO sentido) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	FactoryCompuerta::crearCompuerta(tipo, *circuito, posicion,sentido);

}

void ModeloCliente::agregarEntrada(int idCircuito,Posicion posicion, const string &nombre, SENTIDO sentido) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	FactoryCompuerta::crearEntrada(*circuito,posicion,nombre,sentido);

}

void ModeloCliente::agregarSalida(int idCircuito,Posicion posicion, const string &nombre, SENTIDO sentido) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	FactoryCompuerta::crearSalida(*circuito,posicion,nombre,sentido);

}




void ModeloCliente::eliminarCompuerta(int idCircuito,int idCompuerta) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	circuito->eliminarCompuerta(idCompuerta);

}


Resultado* ModeloCliente::simular(int idCircuito) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	return simulador.simular(*circuito);

}

void ModeloCliente::conectar(int idCircuito,int idSalida,int idEntrada) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	circuito->conectar(idSalida,idEntrada);

}

void ModeloCliente::desconectar(int idCircuito,int idSalida,int idEntrada) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	circuito->desconectar(idSalida, idEntrada);
}

void ModeloCliente::guardar(int idCircuito) {

	Circuito* circuito= obtenerCircuito(idCircuito);

	persistencia.guardar(*circuito);

}

void ModeloCliente::recuperar(const std::string &nombreCircuito) {

	Circuito* circuito= persistencia.recuperar(contadorId, nombreCircuito);

	circuitos.push_back(circuito);

}

void ModeloCliente::enviar(const std::string &nombreCircuito,Servidor servidor) {

	publicacion.enviar(nombreCircuito,servidor);

}

void ModeloCliente::recibir(int idCircuito, const std::string &nombreCircuito,Servidor servidor) {

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

int ModeloCliente::getUltimo() const {

	return contadorId-1;

}

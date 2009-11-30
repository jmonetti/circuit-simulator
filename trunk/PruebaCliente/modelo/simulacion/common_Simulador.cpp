
#include "common_Simulador.h"
#include "../../excepciones/common_CircuitoException.h"
#include <math.h>

Resultado* Simulador::simular(Circuito &circuito) {

	std::vector<ResultadoSimulacion*>* resultadoSimulacion= calcularSimulacion(circuito);

	ResultadoTiempo* resultadoTiempo= calcularTiempo(circuito);

	std::vector<std::string>* nombreEntradas= new vector<std::string>();

	for (unsigned int var = 0; var < circuito.getEntradas().size(); ++var) {

		nombreEntradas->push_back(circuito.getEntradas()[var]->getNombre());

	}

	std::vector<std::string>* nombreSalidas= new vector<std::string>();

	for (unsigned int var = 0; var < circuito.getSalidas().size(); ++var) {

		nombreSalidas->push_back(circuito.getSalidas()[var]->getNombre());

	}



	return new Resultado(resultadoSimulacion,resultadoTiempo,nombreEntradas,nombreSalidas);


}


std::vector<ResultadoSimulacion*>* Simulador::calcularSimulacion(Circuito &circuito) {

	std::vector<ResultadoSimulacion*>* resultadoSimulacion= new std::vector<ResultadoSimulacion*>();
	unsigned int cantidadEntradas= circuito.getCantidadEntradas();
	unsigned int cantidadSalidas= circuito.getCantidadSalidas();

	bool* salidas;
	bool* entradas= new bool[cantidadEntradas];

	for (unsigned int var = 0; var < cantidadEntradas; ++var) {

		entradas[var]= false;

	}

	int potencia= pow(2,(double) cantidadEntradas);

	for (int i= 0; i < potencia; ++i) {

		try {

			salidas= circuito.simular(entradas);

		} catch (CircuitoException e) {

			delete[] entradas;

			vaciarResultadoSimulacion(resultadoSimulacion);

			throw e;

		}


		ResultadoSimulacion* resultado = new ResultadoSimulacion(entradas,salidas,cantidadEntradas,cantidadSalidas);
		resultadoSimulacion->push_back(resultado);

		if (i < potencia - 1) {

			entradas= generarEntradas(i, cantidadEntradas, entradas);

		}


	}



	return resultadoSimulacion;

}

ResultadoTiempo* Simulador::calcularTiempo(Circuito &circuito) {

	int* tiempos= circuito.calcularTiempoTransicion();

	return new ResultadoTiempo(tiempos,circuito.getCantidadSalidas());

}

bool* Simulador::generarEntradas(int i,unsigned int cantidadEntradas,const bool* entradasAnt) {

	bool* entradas= new bool[cantidadEntradas];

	for (unsigned int var = 0; var < cantidadEntradas; ++var) {

		int potencia= pow(2,(double) cantidadEntradas - var -1);
		if ((i + 1) % (potencia) == 0) {

			entradas[var]= !entradasAnt[var];

		}else{

			entradas[var]= entradasAnt[var];

		}

	}

	return entradas;

}

void Simulador::vaciarResultadoSimulacion(std::vector<ResultadoSimulacion*>* resultado) {

	for (unsigned int var = 0; var < resultado->size(); ++var) {

		delete (*resultado)[var];

	}

	delete resultado;

}

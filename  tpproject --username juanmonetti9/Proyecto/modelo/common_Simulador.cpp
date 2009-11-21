
#include "common_Simulador.h"
#include <math.h>

std::vector<Resultado*>* Simulador::simular(Circuito &circuito) {

	std::vector<Resultado*>* retorno= new std::vector<Resultado*>();

	unsigned int cantidadEntradas= circuito.getCantidadEntradas();
	unsigned int cantidadSalidas= circuito.getCantidadSalidas();

	bool* salidas;
	bool* entradas= new bool[cantidadEntradas];

	for (unsigned int var = 0; var < cantidadEntradas; ++var) {

		entradas[var]= false;

	}

	int potencia= pow(2,(double) cantidadEntradas);

	for (int i= 0; i < potencia; ++i) {

		salidas= circuito.simular(entradas);

		Resultado* resultado = new Resultado(entradas,salidas,cantidadEntradas,cantidadSalidas);
		retorno->push_back(resultado);

		if (i < potencia - 1) {

			entradas= generarEntradas(i, cantidadEntradas, entradas);

		}


	}

	return retorno;

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

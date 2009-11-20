#include "circuito/common_Circuito.h"
#include "circuito/common_FactoryCompuerta.h"
#include <vector>
#include "circuito/common_Simulador.h"
#include "circuito/common_Resultado.h"
#include <iostream>
#include "pruebas.h"

void imprimir(Circuito &circuito) {

	std::vector<Resultado*>* resultados= Simulador::simular(circuito);

		Resultado* resultado;

		for (unsigned int var = 0; var < resultados->size(); ++var) {

			resultado= resultados->at(var);

			std::cout<<"Entrada: ";

			for (unsigned int j = 0; j < circuito.getCantidadEntradas(); ++j) {

				std::cout<<resultado->getEntradas()[j];

			}

			std::cout<<std::endl;

			std::cout<<"Salida: ";

			for (unsigned int j = 0; j < circuito.getCantidadSalidas(); ++j) {

				std::cout<<resultado->getSalidas()[j];

			}

			std::cout<<std::endl;

			delete resultado;

		}

		delete resultados;


}


void pruebaCircuitosSeparados() {

	Circuito circuito;

	for (int i = 0; i < 3; ++i) {

		FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
		FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
		switch (i) {

		case 0:
			FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);
			break;
		case 1:
			FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);
			break;
		case 2:
			FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_XOR,circuito,10);

		}
		FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);

		circuito.conectar(3*i,3*i);
		circuito.conectar(3*i+1,3*i+1);
		circuito.conectar(3*i+2,3*i+2);

	}

	for (int i = 0; i < 2; ++i) {

		FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
		switch (i) {

		case 0:
			FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);
			break;

		case 1:

			FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_PISTA,circuito);

		}
		FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);

		circuito.conectar(9 + 2*i,9 + 2*i);
		circuito.conectar(9 + 2*i+1,9 + 2*i+1);
		circuito.conectar(9 + 2*i+2,9 + 2*i+2);

	}


	imprimir(circuito);

}

void pruebaSumaDeUnBit() {

	Circuito circuito;

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_XOR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);

	circuito.conectar(0,0);
	circuito.conectar(1,1);
	circuito.conectar(2,2);
	circuito.conectar(0,3);
	circuito.conectar(1,4);
	circuito.conectar(3,5);

	imprimir(circuito);

}

void pruebaSumaTresEntradas() {

	Circuito circuito;

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_XOR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_XOR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);

	circuito.conectar(0,0);
	circuito.conectar(1,1);
	circuito.conectar(0,2);
	circuito.conectar(1,3);
	circuito.conectar(3,4);
	circuito.conectar(3,7);
	circuito.conectar(2,5);
	circuito.conectar(2,6);
	circuito.conectar(5,11);
	circuito.conectar(4,9);
	circuito.conectar(6,8);
	circuito.conectar(7,10);

	imprimir(circuito);

}

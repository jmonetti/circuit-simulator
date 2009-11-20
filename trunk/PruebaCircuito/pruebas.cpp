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

void pruebaAlarmas() {

	Circuito circuito;

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);


	circuito.conectar(0,0);
	circuito.conectar(6,1);
	circuito.conectar(2,2);
	circuito.conectar(1,3);
	circuito.conectar(1,4);
	circuito.conectar(4,5);
	circuito.conectar(5,6);
	circuito.conectar(0,7);
	circuito.conectar(1,8);
	circuito.conectar(7,9);
	circuito.conectar(8,10);
	circuito.conectar(0,11);
	circuito.conectar(1,12);
	circuito.conectar(9,13);
	circuito.conectar(10,14);
	circuito.conectar(2,15);
	circuito.conectar(11,16);
	circuito.conectar(3,17);
	circuito.conectar(1,18);
	circuito.conectar(12,19);


	imprimir(circuito);


}


void pruebaTablero() {

	Circuito circuito;

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_ENTRADA,circuito);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_XOR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_XOR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_OR,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_NOT,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_AND,circuito,10);

	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);
	FactoryCompuerta::crearCompuerta(FactoryCompuerta::T_SALIDA,circuito);


	circuito.conectar(0,0);
	circuito.conectar(3,1);
	circuito.conectar(2,2);
	circuito.conectar(4,3);
	circuito.conectar(6,4);
	circuito.conectar(0,5);
	circuito.conectar(1,6);
	circuito.conectar(5,7);
	circuito.conectar(8,8);
	circuito.conectar(0,9);
	circuito.conectar(1,10);
	circuito.conectar(0,11);
	circuito.conectar(9,12);
	circuito.conectar(2,13);
	circuito.conectar(10,14);
	circuito.conectar(12,15);
	circuito.conectar(0,16);
	circuito.conectar(1,17);
	circuito.conectar(11,18);
	circuito.conectar(14,19);

	circuito.conectar(0,20);
	circuito.conectar(1,21);
	circuito.conectar(0,22);
	circuito.conectar(15,23);
	circuito.conectar(1,24);
	circuito.conectar(16,25);
	circuito.conectar(2,26);
	circuito.conectar(17,27);
	circuito.conectar(20,28);
	circuito.conectar(0,29);
	circuito.conectar(19,30);
	circuito.conectar(1,31);
	circuito.conectar(1,32);
	circuito.conectar(21,33);
	circuito.conectar(23,34);
	circuito.conectar(2,35);
	circuito.conectar(22,36);
	circuito.conectar(0,37);
	circuito.conectar(0,38);
	circuito.conectar(7,39);

	circuito.conectar(13,40);
	circuito.conectar(18,41);
	circuito.conectar(0,42);
	circuito.conectar(24,43);
	circuito.conectar(0,44);

	imprimir(circuito);

}


#include <iostream>
#include "Cliente.h"
#include <vector>
#include "modelo/common_ResultadoSimulacion.h"
#include "modelo/common_ResultadoTiempo.h"

void imprimirSimulacion(std::vector<ResultadoSimulacion*>* resultados) {

	ResultadoSimulacion* resultado;

	for (unsigned int var = 0; var < resultados->size(); ++var) {

		resultado= resultados->at(var);

		std::cout<<"Entrada: ";

		for (unsigned int j = 0; j < resultado->getCantidadEntradas(); ++j) {

			std::cout<<resultado->getEntradas()[j];

		}

		std::cout<<std::endl;

		std::cout<<"Salida: ";

		for (unsigned int j = 0; j < resultado->getCantidadSalidas(); ++j) {

			std::cout<<resultado->getSalidas()[j];

		}

		std::cout<<std::endl;

		delete resultado;

	}

	delete resultados;

}

void imprimirTiempo(ResultadoTiempo* resultado) {

	int* tiempos= resultado->getTiempos();

	for (unsigned int var = 0; var < resultado->getCantidad(); ++var) {

		std::cout << "Tiempo: "  << tiempos[var] << std::endl;

	}

	delete resultado;

}

int main(int argc, char **argv) {

	Cliente cliente;

	cliente.crearCircuitos();

	std::cout << "Presione Enter para comenzar las pruebas... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuitos Separados: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularCircuitosSeparados());

	std::cout << std::endl;

	imprimirTiempo(cliente.calcularTiempoCircuitosSeparados());



	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Suma De Un Bit: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularSumaDeUnBit());

	std::cout << std::endl;

	imprimirTiempo(cliente.calcularTiempoSumaDeUnBit());

	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Suma Con Tres Entradas: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularSumaTresEntradas());

	std::cout << std::endl;

	imprimirTiempo(cliente.calcularTiempoSumaTresEntradas());


	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Alarmas: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularAlarmas());

	std::cout << std::endl;

	imprimirTiempo(cliente.calcularTiempoAlarmas());



	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Tablero: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularTablero());

	std::cout << std::endl;

	imprimirTiempo(cliente.calcularTiempoTablero());



	std::cout << std::endl << "Presione Enter para finalizar... " << std::endl;

	std::cin.get();

}

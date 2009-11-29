
#include <iostream>
#include "Cliente.h"
#include <vector>
#include "modelo/simulacion/common_ResultadoSimulacion.h"
#include "modelo/simulacion/common_ResultadoTiempo.h"
#include "modelo/simulacion/common_Resultado.h"

void imprimirSimulacion(Resultado* resultados) {

	ResultadoSimulacion* resultado;

	for (unsigned int var = 0; var < resultados->getResultadoSimulacion()->size(); ++var) {

		resultado= resultados->getResultadoSimulacion()->at(var);

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

	}

	std::cout<<std::endl<<std::endl;

	int* tiempos= resultados->getResultadoTiempo()->getTiempos();

	for (unsigned int var = 0; var < resultados->getResultadoTiempo()->getCantidad(); ++var) {

		std::cout << "Tiempo: "  << tiempos[var] << std::endl;

	}

	delete resultados;

}

void imprimirTiempo(ResultadoTiempo* resultado) {



}

int main(int argc, char **argv) {

	Cliente cliente;

	cliente.crearCircuitos();


	std::cout << "Presione Enter para comenzar las pruebas... " << std::endl;

	std::cin.get();



	std::cout << "Prueba De Circuitos Separados: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularCircuitosSeparados());

	cliente.guardarCircuitosSeparados(); //TODO

	std::cout << std::endl;

	std::string ruta= "Circuitos Separados";

	cliente.recuperarCircuito(ruta);

	imprimirSimulacion(cliente.simularCircuitosSeparados());

	std::cout << std::endl;


/*
	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Suma De Un Bit: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularSumaDeUnBit());

	cliente.guardarSumaDeUnBit(); //TODO

	std::cout << std::endl;

	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Suma Con Tres Entradas: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularSumaTresEntradas());

	cliente.guardarSumaTresEntradas(); //TODO

	std::cout << std::endl;


	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Alarmas: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularAlarmas());

	cliente.guardarAlarmas(); //TODO

	std::cout << std::endl;



	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Tablero: " << std::endl << std::endl;

	imprimirSimulacion(cliente.simularTablero());

	cliente.guardarTablero(); //TODO

	std::cout << std::endl;
*/

	std::cout << std::endl << "Presione Enter para finalizar... " << std::endl;

	std::cin.get();

}

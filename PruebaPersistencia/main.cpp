
#include <iostream>
#include "Cliente.h"
#include <vector>
#include "modelo/common_Resultado.h"

void imprimir(std::vector<Resultado*>* resultados) {

	Resultado* resultado;

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

int main(int argc, char **argv) {

	Cliente cliente;

	cliente.crearCircuitos();

	std::cout << "Presione Enter para comenzar las pruebas... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuitos Separados: " << std::endl << std::endl;

	imprimir(cliente.simularCircuitoBasico());

	std::cout << "Ingrese el nombre del archivo donde se guardara (Ej: miCircuito.xml): " << std::endl;

	std::string ruta;

	cin >> ruta;

	cliente.guardarCircuitoBasico(ruta);

	std::cout << "Circuito Guardado Correctamente..." << std::endl;

	std::cout << std::endl << "Presione Enter para finalizar... " << std::endl;

	std::cin.get();

}

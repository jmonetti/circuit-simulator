#include "pruebas.h"
#include <iostream>

int main(int argc, char **argv) {

	std::cout << "Presione Enter para comenzar las pruebas... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuitos Separados: " << std::endl << std::endl;

	pruebaCircuitosSeparados();

	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Suma De Un Bit: " << std::endl << std::endl;

	pruebaSumaDeUnBit();

	std::cout << std::endl << "Presione Enter para continuar con la proxima prueba... " << std::endl;

	std::cin.get();

	std::cout << std::endl << std::endl;

	std::cout << "Prueba De Suma Con Tres Entradas: " << std::endl << std::endl;

	pruebaSumaTresEntradas();


	std::cout << std::endl << "Presione Enter para finalizar... " << std::endl;

	std::cin.get();

}


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

	std::string ruta;

	cliente.crearCircuitos();

	std::cout << "Presione Enter para comenzar las pruebas... " << std::endl;

	std::cin.get();

	//std::cout << "Prueba De Circuito Basico: " << std::endl << std::endl;

	//imprimir(cliente.simularCircuitoBasico());

	//ruta = "miCircuitoBasico.xml";

	//cliente.guardarCircuitoBasico(ruta);

	//std::cout << "Presione Enter para continuar con el siguiente circuito... " << std::endl;

	//std::cin.get();

	std::cout << "Prueba De Circuito NOT: " << std::endl << std::endl;

	imprimir(cliente.simularCircuitoNOT());

	ruta = "miCircuitoNOT.xml";

	cliente.guardarCircuitoNOT(ruta);

	std::cout << "Presione Enter para continuar con el siguiente circuito... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuito AND: " << std::endl << std::endl;

	imprimir(cliente.simularCircuitoAND());

	ruta = "miCircuitoAND.xml";

	cliente.guardarCircuitoAND(ruta);

	std::cout << "Presione Enter para continuar con el siguiente circuito... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuito Suma de un Bit: " << std::endl << std::endl;

	imprimir(cliente.simularSumaDeUnBit());

	ruta = "miSumaDeUnBit.xml";

	cliente.guardarSumaDeUnBit(ruta);

	std::cout << "Presione Enter para continuar con el siguiente circuito... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuitos Separados " << std::endl << std::endl;

	imprimir(cliente.simularCircuitosSeparados());

	ruta = "misCircuitosSeparados.xml";

	cliente.guardarCircuitosSeparados(ruta);

	std::cout << "Presione Enter para continuar con el siguiente circuito... " << std::endl;

	std::cin.get();

	std::cout << "Prueba De Circuitos Suma de tres Entradas " << std::endl << std::endl;

	imprimir(cliente.simularSumaTresEntradas());

	ruta = "miSumaTresEntradas.xml";

	cliente.guardarSumaTresEntradas(ruta);

	std::cout << "Presione Enter para cargar el Circuito Basico ... " << std::endl;

	std::cin.get();

	std::cout << "Recuperando y probando Circuito Basico... " << std::endl << std::endl;

	ruta = 	"miCircuitoBasico.xml";

	cliente.recuperarCircuito(ruta);

	//imprimir(cliente.simularCircuitoBasico());

	std::cout << std::endl << "Presione Enter para finalizar... " << std::endl;

	std::cin.get();

}

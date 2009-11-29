
#include "Cliente.h"
#include "common/constantes.h"
#include "common/common_Posicion.h"

Cliente::Cliente() {
	// TODO Auto-generated constructor stub

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

void Cliente::crearCircuitos() {

	idCircuitos[0]= crearCircuitosSeparados();
	idCircuitos[1]= crearSumaDeUnBit();
	idCircuitos[2]= crearSumaTresEntradas();
	idCircuitos[3]= crearAlarmas();
	idCircuitos[4]= crearTablero();
}

int Cliente::crearCircuitosSeparados() {

	modelo.crearNuevo("Circuitos Separados");

	Posicion posicion;

	int id= 0;

	std::string nom("");

	for (int i = 0; i < 3; ++i) {

		modelo.agregarEntrada(posicion,nom,ESTE);
		modelo.agregarEntrada(posicion,nom,ESTE);
		switch (i) {

		case 0:
			modelo.agregarCompuerta(T_AND,posicion,ESTE);
			break;
		case 1:
			modelo.agregarCompuerta(T_OR,posicion,ESTE);
			break;
		case 2:
			modelo.agregarCompuerta(T_XOR,posicion,ESTE);

		}
		modelo.agregarSalida(posicion,nom,ESTE);

	}

	for (int i = 0; i < 2; ++i) {

		modelo.agregarEntrada(posicion,nom,ESTE);
		switch (i) {

		case 0:
			modelo.agregarCompuerta(T_NOT,posicion,ESTE);
			break;

		case 1:

			modelo.agregarCompuerta(T_PISTA,posicion,ESTE);

		}
		modelo.agregarSalida(posicion,nom,ESTE);

	}

	return id;

}

int Cliente::crearSumaDeUnBit() {

	modelo.crearNuevo("Suma De Un Bit");

	int id= 1;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(posicion,nom,ESTE);

	modelo.agregarEntrada(posicion,nom,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarSalida(posicion,nom,ESTE);

	modelo.agregarCompuerta(T_XOR,posicion,ESTE);

	modelo.agregarSalida(posicion,nom,ESTE);

	return id;

}

int Cliente::crearSumaTresEntradas() {

	modelo.crearNuevo("Suma Tres Entradas");

	int id= 2;

	Posicion posicion;

	std::string nom;

	modelo.agregarEntrada(posicion,nom,ESTE);
	modelo.agregarEntrada(posicion,nom,ESTE);
	modelo.agregarEntrada(posicion,nom,ESTE);

	modelo.agregarCompuerta(T_XOR,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_XOR,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarSalida(posicion,nom,ESTE);

	modelo.agregarSalida(posicion,nom,ESTE);

	return id;

}

int Cliente::crearAlarmas() {

	modelo.crearNuevo("Alarmas");

	int id= 3;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(posicion,nom,ESTE);
	modelo.agregarEntrada(posicion,nom,ESTE);
	modelo.agregarEntrada(posicion,nom,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);


	return id;

}

int Cliente::crearTablero() {

	modelo.crearNuevo("Tablero");

	int id= 4;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(posicion,nom,ESTE);
	modelo.agregarEntrada(posicion,nom,ESTE);
	modelo.agregarEntrada(posicion,nom,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_XOR,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_XOR,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_OR,posicion,ESTE);

	modelo.agregarCompuerta(T_NOT,posicion,ESTE);

	modelo.agregarCompuerta(T_AND,posicion,ESTE);

	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);
	modelo.agregarSalida(posicion,nom,ESTE);

	return id;

}

Resultado* Cliente::simularCircuitosSeparados() {

	modelo.cambiarCircuitoActual(0);
	return modelo.simular();

}

Resultado* Cliente::simularSumaDeUnBit() {

	modelo.cambiarCircuitoActual(1);
	return modelo.simular();

}

Resultado* Cliente::simularSumaTresEntradas() {

	modelo.cambiarCircuitoActual(2);
	return modelo.simular();

}

Resultado* Cliente::simularAlarmas() {

	modelo.cambiarCircuitoActual(3);
	return modelo.simular();

}

Resultado* Cliente::simularTablero() {

	modelo.cambiarCircuitoActual(0);
	return modelo.simular();

}

Resultado* Cliente::simularCircuitoNuevo() {

	modelo.cambiarCircuitoActual(modelo.getUltimo());
	return modelo.simular();

}

void Cliente::guardarCircuitosSeparados() {

	modelo.cambiarCircuitoActual(0);
	modelo.guardar();

}

void Cliente::guardarSumaDeUnBit() {

	modelo.cambiarCircuitoActual(1);
	modelo.guardar();

}

void Cliente::guardarSumaTresEntradas() {

	modelo.cambiarCircuitoActual(2);
	modelo.guardar();

}

void Cliente::guardarAlarmas() {

	modelo.cambiarCircuitoActual(3);
	modelo.guardar();

}

void Cliente::guardarTablero() {

	modelo.cambiarCircuitoActual(4);
	modelo.guardar();

}

void Cliente::recuperarCircuito(std::string &ruta) {

	modelo.recuperar(ruta);

}

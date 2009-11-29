
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

		modelo.agregarEntrada(id,posicion,nom);
		modelo.agregarEntrada(id,posicion,nom);
		switch (i) {

		case 0:
			modelo.agregarCompuerta(id,T_AND,posicion);
			break;
		case 1:
			modelo.agregarCompuerta(id,T_OR,posicion);
			break;
		case 2:
			modelo.agregarCompuerta(id,T_XOR,posicion);

		}
		modelo.agregarSalida(id,posicion,nom);

		modelo.conectar(id,3*i,3*i);
		modelo.conectar(id,3*i+1,3*i+1);
		modelo.conectar(id,3*i+2,3*i+2);

	}

	for (int i = 0; i < 2; ++i) {

		modelo.agregarEntrada(id,posicion,nom);
		switch (i) {

		case 0:
			modelo.agregarCompuerta(id,T_NOT,posicion);
			break;

		case 1:

			modelo.agregarCompuerta(id,T_PISTA,posicion);

		}
		modelo.agregarSalida(id,posicion,nom);

		modelo.conectar(id,9 + 2*i,9 + 2*i);
		modelo.conectar(id,9 + 2*i+1,9 + 2*i+1);

	}

	return id;

}

int Cliente::crearSumaDeUnBit() {

	modelo.crearNuevo("Suma De Un Bit");

	int id= 1;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(id,posicion,nom);

	modelo.agregarEntrada(id,posicion,nom);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarSalida(id,posicion,nom);

	modelo.agregarCompuerta(id,T_XOR,posicion);

	modelo.agregarSalida(id,posicion,nom);

	modelo.conectar(id,0,0);
	modelo.conectar(id,1,1);
	modelo.conectar(id,2,2);
	modelo.conectar(id,0,3);
	modelo.conectar(id,1,4);
	modelo.conectar(id,3,5);

	return id;

}

int Cliente::crearSumaTresEntradas() {

	modelo.crearNuevo("Suma Tres Entradas");

	int id= 2;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(id,posicion,nom);
	modelo.agregarEntrada(id,posicion,nom);
	modelo.agregarEntrada(id,posicion,nom);

	modelo.agregarCompuerta(id,T_XOR,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_XOR,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarSalida(id,posicion,nom);

	modelo.agregarSalida(id,posicion,nom);

	modelo.conectar(id,0,0);
	modelo.conectar(id,1,1);
	modelo.conectar(id,0,2);
	modelo.conectar(id,1,3);
	modelo.conectar(id,3,4);
	modelo.conectar(id,3,7);
	modelo.conectar(id,2,5);
	modelo.conectar(id,2,6);
	modelo.conectar(id,5,11);
	modelo.conectar(id,4,9);
	modelo.conectar(id,6,8);
	modelo.conectar(id,7,10);

	return id;

}

int Cliente::crearAlarmas() {

	modelo.crearNuevo("Alarmas");

	int id= 3;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(id,posicion,nom);
	modelo.agregarEntrada(id,posicion,nom);
	modelo.agregarEntrada(id,posicion,nom);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);


	modelo.conectar(id,0,0);
	modelo.conectar(id,6,1);
	modelo.conectar(id,2,2);
	modelo.conectar(id,1,3);
	modelo.conectar(id,1,4);
	modelo.conectar(id,4,5);
	modelo.conectar(id,5,6);
	modelo.conectar(id,0,7);
	modelo.conectar(id,1,8);
	modelo.conectar(id,7,9);
	modelo.conectar(id,8,10);
	modelo.conectar(id,0,11);
	modelo.conectar(id,1,12);
	modelo.conectar(id,9,13);
	modelo.conectar(id,10,14);
	modelo.conectar(id,2,15);
	modelo.conectar(id,11,16);
	modelo.conectar(id,3,17);
	modelo.conectar(id,1,18);
	modelo.conectar(id,12,19);

	return id;

}

int Cliente::crearTablero() {

	modelo.crearNuevo("Tablero");

	int id= 4;

	Posicion posicion;

	std::string nom("");

	modelo.agregarEntrada(id,posicion,nom);
	modelo.agregarEntrada(id,posicion,nom);
	modelo.agregarEntrada(id,posicion,nom);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_XOR,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_XOR,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_OR,posicion);

	modelo.agregarCompuerta(id,T_NOT,posicion);

	modelo.agregarCompuerta(id,T_AND,posicion);

	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);
	modelo.agregarSalida(id,posicion,nom);


	modelo.conectar(id,0,0);
	modelo.conectar(id,3,1);
	modelo.conectar(id,2,2);
	modelo.conectar(id,4,3);
	modelo.conectar(id,6,4);
	modelo.conectar(id,0,5);
	modelo.conectar(id,1,6);
	modelo.conectar(id,5,7);
	modelo.conectar(id,8,8);
	modelo.conectar(id,0,9);
	modelo.conectar(id,1,10);
	modelo.conectar(id,0,11);
	modelo.conectar(id,9,12);
	modelo.conectar(id,2,13);
	modelo.conectar(id,10,14);
	modelo.conectar(id,12,15);
	modelo.conectar(id,0,16);
	modelo.conectar(id,1,17);
	modelo.conectar(id,11,18);
	modelo.conectar(id,14,19);

	modelo.conectar(id,0,20);
	modelo.conectar(id,1,21);
	modelo.conectar(id,0,22);
	modelo.conectar(id,15,23);
	modelo.conectar(id,1,24);
	modelo.conectar(id,16,25);
	modelo.conectar(id,2,26);
	modelo.conectar(id,17,27);;
	modelo.conectar(id,20,28);
	modelo.conectar(id,0,29);
	modelo.conectar(id,19,30);
	modelo.conectar(id,1,31);
	modelo.conectar(id,1,32);
	modelo.conectar(id,21,33);
	modelo.conectar(id,23,34);
	modelo.conectar(id,2,35);
	modelo.conectar(id,22,36);
	modelo.conectar(id,0,37);
	modelo.conectar(id,0,38);
	modelo.conectar(id,7,39);

	modelo.conectar(id,13,40);
	modelo.conectar(id,18,41);
	modelo.conectar(id,0,42);
	modelo.conectar(id,24,43);
	modelo.conectar(id,0,44);

	return id;

}

Resultado* Cliente::simularCircuitosSeparados() {

	return modelo.simular(idCircuitos[0]);

}

Resultado* Cliente::simularSumaDeUnBit() {

	return modelo.simular(idCircuitos[1]);

}

Resultado* Cliente::simularSumaTresEntradas() {

	return modelo.simular(idCircuitos[2]);

}

Resultado* Cliente::simularAlarmas() {

	return modelo.simular(idCircuitos[3]);

}

Resultado* Cliente::simularTablero() {

	return modelo.simular(idCircuitos[4]);

}

Resultado* Cliente::simularCircuitoNuevo() {

	return modelo.simular(modelo.getUltimo());

}

void Cliente::guardarCircuitosSeparados() {

	modelo.guardar(idCircuitos[0]);

}

void Cliente::guardarSumaDeUnBit() {

	modelo.guardar(idCircuitos[1]);

}

void Cliente::guardarSumaTresEntradas() {

	modelo.guardar(idCircuitos[2]);

}

void Cliente::guardarAlarmas() {

	modelo.guardar(idCircuitos[3]);

}

void Cliente::guardarTablero() {

	modelo.guardar(idCircuitos[4]);

}

void Cliente::recuperarCircuito(std::string &ruta) {

	modelo.recuperar(ruta);

}

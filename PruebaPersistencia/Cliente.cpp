
#include "Cliente.h"
#include "common/constantes.h"

Cliente::Cliente() {
	// TODO Auto-generated constructor stub

}

Cliente::~Cliente() {
	// TODO Auto-generated destructor stub
}

void Cliente::crearCircuitos() {

	idCircuitos[0]= crearCircuitoBasico();
	idCircuitos[0]= crearCircuitoNOT();
	idCircuitos[1]= crearCircuitoAND();
	idCircuitos[2]= crearSumaDeUnBit();
	idCircuitos[3]= crearCircuitosSeparados();
	idCircuitos[4]= crearSumaTresEntradas();
}

int Cliente::crearCircuitoBasico() {

	int id= modelo.crearNuevo();
	modelo.agregarCompuerta(id,T_ENTRADA);

	modelo.agregarCompuerta(id,T_SALIDA);

	modelo.conectar(id,0,0);

	return id;

}

int Cliente::crearCircuitoNOT() {

	int id= modelo.crearNuevo();
	modelo.agregarCompuerta(id,T_ENTRADA);

	modelo.agregarCompuerta(id,T_NOT);

	modelo.agregarCompuerta(id,T_SALIDA);

	modelo.conectar(id,0,0);
	modelo.conectar(id,1,1);

	return id;
}

int Cliente::crearCircuitoAND() {

	int id= modelo.crearNuevo();
	modelo.agregarCompuerta(id,T_ENTRADA);
	modelo.agregarCompuerta(id,T_ENTRADA);

	modelo.agregarCompuerta(id,T_AND);

	modelo.agregarCompuerta(id,T_SALIDA);

	modelo.conectar(id,0,0);
	modelo.conectar(id,1,1);
	modelo.conectar(id,2,2);

	return id;
}

int Cliente::crearSumaDeUnBit() {

	int id= modelo.crearNuevo();
	modelo.agregarCompuerta(id,T_ENTRADA);

	modelo.agregarCompuerta(id,T_ENTRADA);

	modelo.agregarCompuerta(id,T_AND,10);

	modelo.agregarCompuerta(id,T_SALIDA);

	modelo.agregarCompuerta(id,T_XOR,10);

	modelo.agregarCompuerta(id,T_SALIDA);

	modelo.conectar(id,0,0);
	modelo.conectar(id,1,1);
	modelo.conectar(id,2,2);
	modelo.conectar(id,0,3);
	modelo.conectar(id,1,4);
	modelo.conectar(id,3,5);

	return id;

}

int Cliente::crearCircuitosSeparados() {

	int id= modelo.crearNuevo();

	for (int i = 0; i < 3; ++i) {

		modelo.agregarCompuerta(id,T_ENTRADA);
		modelo.agregarCompuerta(id,T_ENTRADA);
		switch (i) {

		case 0:
			modelo.agregarCompuerta(id,T_AND,10);
			break;
		case 1:
			modelo.agregarCompuerta(id,T_OR,10);
			break;
		case 2:
			modelo.agregarCompuerta(id,T_XOR,10);

		}
		modelo.agregarCompuerta(id,T_SALIDA);

		modelo.conectar(id,3*i,3*i);
		modelo.conectar(id,3*i+1,3*i+1);
		modelo.conectar(id,3*i+2,3*i+2);

	}

	for (int i = 0; i < 2; ++i) {

		modelo.agregarCompuerta(id,T_ENTRADA);
		switch (i) {

		case 0:
			modelo.agregarCompuerta(id,T_NOT,10);
			break;

		case 1:

			modelo.agregarCompuerta(id,T_PISTA);

		}
		modelo.agregarCompuerta(id,T_SALIDA);

		modelo.conectar(id,9 + 2*i,9 + 2*i);
		modelo.conectar(id,9 + 2*i+1,9 + 2*i+1);

	}

	return id;

}

int Cliente::crearSumaTresEntradas() {

	int id= modelo.crearNuevo();

	modelo.agregarCompuerta(id,T_ENTRADA);
	modelo.agregarCompuerta(id,T_ENTRADA);
	modelo.agregarCompuerta(id,T_ENTRADA);

	modelo.agregarCompuerta(id,T_XOR,10);

	modelo.agregarCompuerta(id,T_AND,10);

	modelo.agregarCompuerta(id,T_XOR,10);

	modelo.agregarCompuerta(id,T_AND,10);

	modelo.agregarCompuerta(id,T_OR,10);

	modelo.agregarCompuerta(id,T_SALIDA);

	modelo.agregarCompuerta(id,T_SALIDA);

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

std::vector<Resultado*>* Cliente::simularCircuitoBasico() {

	return modelo.simular(idCircuitos[0]);

}

std::vector<Resultado*>* Cliente::simularCircuitoNOT() {

	return modelo.simular(idCircuitos[0]);

}

std::vector<Resultado*>* Cliente::simularCircuitoAND() {

	return modelo.simular(idCircuitos[1]);

}

std::vector<Resultado*>* Cliente::simularSumaDeUnBit() {

	return modelo.simular(idCircuitos[2]);

}

std::vector<Resultado*>* Cliente::simularCircuitosSeparados() {

	return modelo.simular(idCircuitos[3]);

}

std::vector<Resultado*>* Cliente::simularSumaTresEntradas() {

	return modelo.simular(idCircuitos[4]);

}

void Cliente::guardarCircuitoBasico(std::string &ruta) {

	modelo.guardar(idCircuitos[0], ruta);
}

void Cliente::guardarCircuitoNOT(std::string &ruta) {

	modelo.guardar(idCircuitos[0], ruta);
}

void Cliente::guardarCircuitoAND(std::string &ruta) {

	modelo.guardar(idCircuitos[1], ruta);
}

void Cliente::guardarSumaDeUnBit(std::string &ruta) {

	modelo.guardar(idCircuitos[2], ruta);
}

void Cliente::guardarCircuitosSeparados(std::string &ruta) {

	modelo.guardar(idCircuitos[3], ruta);
}

void Cliente::guardarSumaTresEntradas(std::string &ruta) {

	modelo.guardar(idCircuitos[4], ruta);
}

void Cliente::recuperarCircuito(std::string &ruta) {

	modelo.recuperar(ruta);

}


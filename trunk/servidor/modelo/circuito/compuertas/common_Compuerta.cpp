#include "common_Compuerta.h"

Compuerta::Compuerta(int id, Posicion posicion, SENTIDO sentido) : posicion(posicion){

	this->id= id;
	this->sentido= sentido;

}

Compuerta::~Compuerta() {


}

Entrada* Compuerta::getEntrada(){

	return NULL;

}

Salida* Compuerta::getSalida(){

	return NULL;

}

int Compuerta::getId() {

	return id;

}

void Compuerta::mover(Posicion posicion) {

	this->posicion= posicion;

	actualizarEntradas();
	actualizarSalidas();

}

void Compuerta::rotar(DIRECCION direccion) {

	switch (direccion) {

		case IZQUIERDA:

			rotarIzquierda();
			break;

		case DERECHA:

			rotarDerecha();
			break;

		default:

			break;

	}

	actualizarEntradas();
	actualizarSalidas();

}

void Compuerta::simular() {

	EntradaCompuerta** entradas= getEntradas();

	bool* valores= new bool[getCantidadEntradas()];

	for (int var = 0; var < getCantidadEntradas(); ++var) {

		valores[var]= entradas[var]->simular();

	}

	actuarSimular(valores);

	delete[] valores;

}

void Compuerta::calcularTiempoTransicion() {

	EntradaCompuerta** entradas= getEntradas();

	int* tiempos= new int[getCantidadEntradas()];

	for (int var = 0; var < getCantidadEntradas(); ++var) {

		tiempos[var]= entradas[var]->calcularTiempoTransicion();

	}

	actuarTiempo(tiempos);

	delete[] tiempos;

}

Posicion Compuerta::getPosicion() const {

	return posicion;

}


SENTIDO Compuerta::getSentido() const {

	return sentido;

}

void Compuerta::rotarDerecha() {

	switch (sentido) {

	case NORTE:

		sentido= ESTE;
		break;

	case ESTE:

		sentido= SUR;
		break;

	case SUR:

		sentido= OESTE;
		break;

	case OESTE:

		sentido= NORTE;
		break;

	}

}

void Compuerta::rotarIzquierda() {

	switch (sentido) {

	case NORTE:

		sentido= OESTE;
		break;

	case ESTE:

		sentido= NORTE;
		break;

	case SUR:

		sentido= ESTE;
		break;

	case OESTE:

		sentido= SUR;
		break;

	}

}


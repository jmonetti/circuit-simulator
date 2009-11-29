#include "common_Compuerta.h"

Compuerta::Compuerta(int id, Posicion posicion, SENTIDO sentido) : posicion(posicion){

	this->id= id;
	this->sentido= sentido;

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

void Compuerta::mover(unsigned int x,unsigned int y) {

	posicion.setX(x);
	posicion.setY(y);

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

int Compuerta::getX() const {

	return posicion.getX();

}

int Compuerta::getY() const {

	return posicion.getY();

}

SENTIDO Compuerta::getSentido() const {

	return sentido;

}

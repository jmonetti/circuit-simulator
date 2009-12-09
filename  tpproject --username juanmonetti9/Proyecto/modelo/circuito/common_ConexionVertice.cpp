#include "common_ConexionVertice.h"

ConexionVertice::ConexionVertice(Posicion posicion,SENTIDO sentido) {

	this->posicion= posicion;
	this->sentido= sentido;

}

Posicion ConexionVertice::getPosicion()const {

	return posicion;

}

SENTIDO ConexionVertice::getSentido()const{

	return sentido;

}


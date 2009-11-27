
#include "common_Posicion.h"

Posicion::Posicion(unsigned int x, unsigned int y) {

	this->x= x;

	this->y= y;

}

unsigned int Posicion::getX() const{

	return x;

}

unsigned int Posicion::getY() const{

	return y;

}

void Posicion::setX(unsigned int x) {

	this->x= x;

}

void Posicion::setY(unsigned int y) {

	this->y= y;

}

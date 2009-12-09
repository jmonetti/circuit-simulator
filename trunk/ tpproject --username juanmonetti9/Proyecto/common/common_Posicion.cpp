
#include "common_Posicion.h"

Posicion::Posicion(unsigned int x, unsigned int y) {

	if (x == 0) {

		this->x= 1;

	}else{

		this->x= x;

	}

	if (y == 0) {

		this->y= 1;

	}else{

		this->y= y;

	}

}

unsigned int Posicion::getX() const{

	return x;

}

unsigned int Posicion::getY() const{

	return y;

}

bool Posicion::operator==(const Posicion &posicion) const{

	return ((this->x == posicion.x) && (this->y == posicion.y));

}

Posicion& Posicion::operator =(const Posicion &posicion) {

	this->x=posicion.x;
	this->y=posicion.y;

	return *this;

}


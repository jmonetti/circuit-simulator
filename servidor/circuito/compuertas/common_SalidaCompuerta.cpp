
#include "common_SalidaCompuerta.h"

SalidaCompuerta::SalidaCompuerta() {

	validoValor= false;
	validoTiempo= false;
	compuerta= NULL;

}

int SalidaCompuerta::calcularTiempoTransicion() {

	if (!validoTiempo) {

		compuerta->calcularTiempoTransicion();

	}


	return tiempoTransicion;

}

bool SalidaCompuerta::simular() {

	if (!validoValor) {

		compuerta->simular();

	}

	return valor;

}

void SalidaCompuerta::mover(Posicion posicion) {

	this->posicion= posicion;

}

void SalidaCompuerta::rotar(SENTIDO sentido) {

	this->sentido= sentido;

}

void SalidaCompuerta::conectar(EntradaCompuerta* salida) {

	this->salidas.push_back(salida);

}

void SalidaCompuerta::desconectar(EntradaCompuerta* entrada) {

	if (entrada) {

		std::vector<EntradaCompuerta*>::iterator iterador= salidas.begin();

		while (iterador != salidas.end()) {

			if (entrada == *iterador) {

				salidas.erase(iterador);

				return;

			}else{

				iterador++;

			}

		}

	}else {

		this->salidas.clear();

	}

}

std::vector<EntradaCompuerta*>& SalidaCompuerta::getConexiones() {

	return salidas;

}


void SalidaCompuerta::reset() {

	validoValor= false;
	validoTiempo= false;

}

void SalidaCompuerta::setValorSalida(bool valor) {

	this->valor = valor;
	validoValor= true;

}

void SalidaCompuerta::setTiempoTransicion(int tiempo) {

	this->tiempoTransicion= tiempo;
	validoTiempo= true;

}

void SalidaCompuerta::setCompuerta(Compuerta* compuerta) {

	this->compuerta= compuerta;

}

Posicion SalidaCompuerta::getPosicion() const{

	return posicion;

}

SENTIDO SalidaCompuerta::getSentido() const {

	return sentido;

}

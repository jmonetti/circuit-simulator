/**************************   Clase Circuito **************************************/
/**************************      Grupo 8     **************************************/

#include "common_Circuito.h"
#include <iostream>

Circuito::Circuito() {

	this->contadorCompuertas= 0;
	this->contadorEntradasCompuertas= 0;
	this->contadorSalidasCompuertas= 0;

}

Circuito::~Circuito() {

	for (unsigned int i = 0; i < compuertas.size(); ++i) {

		delete compuertas[i];

	}

}

void Circuito::simular(bool* entradas) {

	this->setearEntradas(entradas);

	this->reset();

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->simular();

		std::cout<<"Salida: "<<salidas[var]->getValor()<<std::endl;

	}

}

void Circuito::calcularTiempoTransicion() {

	this->reset();

	for (unsigned int var = 0; var < salidas.size(); ++var) {

		salidas[var]->calcularTiempoTransicion();

		std::cout<<"Salida: "<<salidas[var]->getTiempoTransicion()<<std::endl;

	}

}

void Circuito::agregarCompuerta(Compuerta* compuerta) {

	Entrada* entrada= compuerta->getEntrada();

	if (entrada) {

		entradas.push_back(entrada);

	} else {

		Salida* salida= compuerta->getSalida();

		if (salida) {

			salidas.push_back(salida);

		}

	}

	compuertas.push_back(compuerta);

	contadorCompuertas++;

}

void Circuito::agregarEntradaCompuerta(EntradaCompuerta* entrada) {

	entradasCompuerta.push_back(entrada);

	contadorEntradasCompuertas++;

}

void Circuito::agregarSalidaCompuerta(SalidaCompuerta* salida) {

	salidasCompuerta.push_back(salida);

	contadorSalidasCompuertas++;

}

int Circuito::getContadorCompuertas() {

	return contadorCompuertas;

}

int Circuito::getContadorSalidasCompuerta() {

	return contadorSalidasCompuertas;

}

int Circuito::getContadorEntradasCompuerta() {

	return contadorEntradasCompuertas;

}
void Circuito::setearEntradas(bool* entradas) {

	for (unsigned int i = 0; i < this->entradas.size(); ++i) {

		this->entradas[i]->setValorEntrada(entradas[i]);

	}

}

void Circuito::reset() {

	for (unsigned int i = 0; i < salidasCompuerta.size(); ++i) {

		salidasCompuerta[i]->reset();

	}

}



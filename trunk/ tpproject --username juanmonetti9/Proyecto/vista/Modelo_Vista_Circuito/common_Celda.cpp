/*
 * common_Celda.cpp
 *
 *  Created on: 22/11/2009
 *      Author: juanm
 */

#include "common_Celda.h"
#include "common_Modelo_vista_circuito.h"
#include <stdlib.h>

Celda::Celda(Modelo_vista_circuito* _grilla,unsigned int _fila,unsigned int _col){

	grilla=_grilla;
	fila= _fila;
	colum=_col;
	entorno=NULL;
	ocupada=false;

}

bool Celda::agregar_compuerta_XOR(){

	bool agregada=false;

	if(!esta_ocupada()){
		//TODO por hacer


	}

	return agregada;
}

void Celda::ocupar_celda(){
	//TODO por hacer
}

void Celda::desocupar_celda(){
	//TODO por hacer
}


bool Celda::esta_ocupada(){
	return true;
	//TODO por hacer
}

Celda::~Celda() {

}

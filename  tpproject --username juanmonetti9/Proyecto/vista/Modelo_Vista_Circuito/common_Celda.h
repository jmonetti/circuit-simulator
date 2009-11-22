/*
 * common_Celda.h
 *
 *  Created on: 22/11/2009
 *      Author: juanm
 */
#include "common_Entorno.h"

#ifndef COMMON_CELDA_H_
#define COMMON_CELDA_H_

class Modelo_vista_circuito; //declaracion forward

class Celda {

private:

	Modelo_vista_circuito* grilla;//Grilla en la cual se encuentra la celda
	Entorno* entorno;	//Puntero al entorno de la celda
	bool ocupada;		//Representa si la celda ya esta ocupada
	unsigned int fila; 	//Fila de la celda
	unsigned int colum;	//columna de la celda
	unsigned int fila_padre;  	//Fila del padre de la celda
	unsigned int colum_padre;	//columna del padre de la celda


	bool agregar_entorno_compuerta();


public:

	Celda(Modelo_vista_circuito* _grilla,unsigned int _fila,unsigned int _col);

	/**
	 * Agrega una compuerta xor a la grilla, utilizando esta celda
	 * como celda padre, seteando su entorno y los valores de las
	 * celdas que integran el entorno
	 * @return (true) en caso de haber agregado la celda
	 * 		   (false) en caso de que no se pueda agregar
	 */

	bool agregar_compuerta_XOR();

	/**
	 * Setea el valor del atributo ocupada en true
	 */
	void ocupar_celda();

	/**
	 * Setea el valor del atributo ocupada en false
	 */
	void desocupar_celda();

	/**
	 * @return (true) si la celda esta ocupada
	 */
	bool esta_ocupada();


	virtual ~Celda();
};

#endif /* COMMON_CELDA_H_ */

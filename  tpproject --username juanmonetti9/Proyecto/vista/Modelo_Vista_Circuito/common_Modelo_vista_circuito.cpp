/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/


#include "common_Modelo_vista_circuito.h"
#include "common_Celda.h"

Modelo_vista_circuito::Modelo_vista_circuito() {

	modelo_grilla = new Dato_circuito* [FILAS_MODELO]; //creo las filas

	for (int j = 0; j < FILAS_MODELO; j++)
		modelo_grilla[j] = new Dato_circuito[COLUMNAS_MODELO]; //creo las columnas

	// pongo en NULL todas las posiciones
	for (int i = 0; i < FILAS_MODELO; i++){
		for (int j = 0; j < COLUMNAS_MODELO; j++){
			modelo_grilla[i][j] = new Celda(this,(unsigned int)i,(unsigned int)j);
		}
	}

}


Modelo_vista_circuito::~Modelo_vista_circuito() {

}

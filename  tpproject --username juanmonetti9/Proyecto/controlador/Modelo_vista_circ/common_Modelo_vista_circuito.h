/**************************   Modelo Circuito  ***********************/
/**************************   	Grupo 8        ***********************/
#ifndef COMMON_MODELO_VISTA_CIRCUITO_H_
#define COMMON_MODELO_VISTA_CIRCUITO_H_


#include "common_Celda.h"

#include <string.h>
#include <gtkmm.h>

// declaracion foward
//todo class Celda;

//defino al dato del modelo
typedef struct Celda* Dato_circuito;


//Constantes del tamanio del modelo
const int PIXELES_WIDTH= 1200;
const int PIXELES_HEIGHT= 780;
const int FILAS_MODELO= 65;
const int COLUMNAS_MODELO= 100;

class Modelo_vista_circuito {

private:

	Dato_circuito  modelo_grilla[COLUMNAS_MODELO][FILAS_MODELO];


public:

	Modelo_vista_circuito();

	bool agregar_compuerta(int* x,int* y,TIPO_COMPUERTA _tipo);

	bool hay_componente(int* x,int* y,TIPO_COMPUERTA* tipo);

	bool eliminar_componente(int x,int y);

	Celda* get_celda(int fila,int colum);

	int de_pixel_a_fila(int x);

	int de_pixel_a_col(int y);

	virtual ~Modelo_vista_circuito();
};

#endif /* COMMON_MODELO_VISTA_CIRCUITO_H_ */

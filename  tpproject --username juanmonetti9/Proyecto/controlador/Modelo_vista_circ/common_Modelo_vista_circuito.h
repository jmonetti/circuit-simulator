/**************************   Modelo Circuito  ***********************/
/**************************   	Grupo 8        ***********************/
#ifndef COMMON_MODELO_VISTA_CIRCUITO_H_
#define COMMON_MODELO_VISTA_CIRCUITO_H_


#include "common_Celda.h"
#include "../../common/constantes.h"
#include <string.h>
#include <gtkmm.h>

//defino al dato del modelo
typedef struct Celda* Dato_circuito;

class Modelo_vista_circuito {

private:

	Dato_circuito  modelo_grilla[FILAS_MODELO][COLUMNAS_MODELO];

public:

	Modelo_vista_circuito();

	bool agregar_componente(int* x,int* y,TIPO_COMPUERTA _tipo,int id,SENTIDO sentido);

	bool agregar_caja_negra(int* x,int* y,int id,int cant_entradas,int cant_salidas);

	bool hay_componente(int* x,int* y,TIPO_COMPUERTA* tipo);

	void eliminar_componente(int x,int y);

	Celda* get_celda(int fila,int colum);

	Celda* get_celda_px(int x,int y);

	Celda* get_celda_px(int* x,int* y);

	virtual ~Modelo_vista_circuito();

	/**
	 * Metodos estaticos para el traspaso de filas y columas a pixeles
	 **/

	static int de_pixel_a_fila(int x);

	static int de_pixel_a_col(int y);

    static int de_fila_a_pixel(int fila);

	static int de_col_a_pixel(int col);


};

#endif /* COMMON_MODELO_VISTA_CIRCUITO_H_ */

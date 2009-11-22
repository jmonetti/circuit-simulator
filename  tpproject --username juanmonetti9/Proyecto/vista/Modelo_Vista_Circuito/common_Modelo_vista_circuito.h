/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#ifndef COMMON_MODELO_VISTA_CIRCUITO_H_
#define COMMON_MODELO_VISTA_CIRCUITO_H_

#include "common_compuerta.h"

#include <string.h>


class Celda; // declaracion foward
//defino al dato del modelo
typedef struct Celda* Dato_circuito;
typedef struct Celda  Dato_circuito_base;

//Constantes del tamanio del modelo
const int PIXELES_WITH= 1170;
const int PIXELES_HEIGHT= 800;
const int FILAS_MODELO= 80;
const int COLUMNAS_MODELO= 90;

class Modelo_vista_circuito {

private:

	Dato_circuito** modelo_grilla;

public:

	Modelo_vista_circuito();

	virtual ~Modelo_vista_circuito();
};

#endif /* COMMON_MODELO_VISTA_CIRCUITO_H_ */

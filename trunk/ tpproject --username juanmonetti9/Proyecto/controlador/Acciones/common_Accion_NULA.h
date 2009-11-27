/**************************   Clase Accion_NULA         *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_NULA_H_
#define COMMON_ACCION_NULA_H_

#include "common_Accion.h"

class Accion_NULA: public Accion {

public:

	Accion_NULA(Controlador* controlador);

	void ejecutar(gdouble x, gdouble y);

	virtual ~Accion_NULA();
};

#endif /* COMMON_ACCION_NULA_H_ */

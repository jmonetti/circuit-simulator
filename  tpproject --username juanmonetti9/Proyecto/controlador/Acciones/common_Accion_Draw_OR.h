/**************************   Clase Accion_Draw_OR      *************/
/**************************   	Grupo 8                 *************/
#ifndef COMMON_ACCION_OR_H_
#define COMMON_ACCION_OR_H_

#include "common_Accion.h"

class Accion_OR: public Accion {

public:
	Accion_OR(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_OR();
};

#endif /* COMMON_ACCION_OR_H_ */

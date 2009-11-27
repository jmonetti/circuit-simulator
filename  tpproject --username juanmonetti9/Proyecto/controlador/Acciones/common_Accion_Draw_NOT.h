/**************************   Clase Accion_Draw_NOT     *************/
/**************************   	Grupo 8                 *************/


#ifndef COMMON_ACCION_NOT_H_
#define COMMON_ACCION_NOT_H_

#include "common_Accion.h"

class Accion_NOT: public Accion {
public:
	Accion_NOT(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_NOT();
};

#endif /* COMMON_ACCION_NOT_H_ */

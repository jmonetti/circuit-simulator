/**************************   Clase Accion_Draw_AND     *************/
/**************************   	Grupo 8                 *************/


#ifndef COMMON_ACCION_DRAW_AND_H_
#define COMMON_ACCION_DRAW_AND_H_

#include "common_Accion.h"

class Accion_Draw_AND: public Accion {

public:

	Accion_Draw_AND(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_Draw_AND();
};

#endif /* COMMON_ACCION_DRAW_AND_H_ */

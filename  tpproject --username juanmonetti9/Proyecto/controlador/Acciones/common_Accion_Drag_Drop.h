/**************************   Clase Accion_Drag_Drop    *************/
/**************************   	Grupo 8                 *************/


#ifndef COMMON_ACCION_DRAG_DROP_H_
#define COMMON_ACCION_DRAG_DROP_H_

#include "common_Accion.h"

class Accion_Drag_Drop: public Accion {

public:

	Accion_Drag_Drop(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_Drag_Drop();
};

#endif /* COMMON_ACCION_DRAG_DROP_H_ */

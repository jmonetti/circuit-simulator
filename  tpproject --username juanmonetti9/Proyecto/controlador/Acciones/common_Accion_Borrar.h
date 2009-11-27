/**************************   Clase Accion_Borrar       *************/
/**************************   	Grupo 8                 *************/


#ifndef COMMON_ACCION_BORRAR_H_
#define COMMON_ACCION_BORRAR_H_

#include "common_Accion.h"

class Accion_Borrar: public Accion {

public:

	Accion_Borrar(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_Borrar();
};

#endif /* COMMON_ACCION_BORRAR_H_ */

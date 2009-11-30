/**************************   Clase Accion_new_Salida   *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_NEW_SALIDA_H_
#define COMMON_ACCION_NEW_SALIDA_H_

#include "common_Accion.h"

class Accion_new_salida: public Accion {

public:

	Accion_new_salida(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_new_salida();
};

#endif /* COMMON_ACCION_NEW_SALIDA_H_ */

/**************************   Clase Accion_Invertir     *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_INVERTIR_LEFT_H_
#define COMMON_ACCION_INVERTIR_LEFT_H_

#include "common_Accion.h"

class Accion_invertir_left: public Accion {

public:

	Accion_invertir_left(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_invertir_left();
};

#endif /* COMMON_ACCION_INVERTIR_LEFT_H_ */

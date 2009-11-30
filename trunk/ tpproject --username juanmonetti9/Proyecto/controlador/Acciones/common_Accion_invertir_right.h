/**************************   Clase Accion_Invertir     *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_INVERTIR_RIGTH_H_
#define COMMON_ACCION_INVERTIR_RIGHT_H_

#include "common_Accion.h"

class Accion_invertir_right: public Accion {

public:

	Accion_invertir_right(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_invertir_right();
};

#endif /* COMMON_ACCION_INVERTIR_RIGHT_H_ */

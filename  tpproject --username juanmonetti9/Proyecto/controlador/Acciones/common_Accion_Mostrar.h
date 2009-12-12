#ifndef COMMON_ACCION_MOSTRAR_H_
#define COMMON_ACCION_MOSTRAR_H_

#include "common_Accion.h"

class Accion_Mostrar: public Accion {

public:

	Accion_Mostrar(Controlador* controlador);

	virtual ~Accion_Mostrar();

	void ejecutar(gdouble x,gdouble y);

};

#endif /* COMMON_ACCION_MOSTRAR_H_ */

/**************************   Clase Accion_new_entrada  *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_NEW_ENTRADA_H_
#define COMMON_ACCION_NEW_ENTRADA_H_

#include "common_Accion.h"

class Accion_new_entrada: public Accion {

public:

	Accion_new_entrada(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_new_entrada();
};

#endif /* COMMON_ACCION_NEW_ENTRADA_H_ */

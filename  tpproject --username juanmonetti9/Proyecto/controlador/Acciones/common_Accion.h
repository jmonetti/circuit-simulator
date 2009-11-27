/**************************   Clase Accion              *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_H_
#define COMMON_ACCION_H_
#include <gtkmm.h>
#include "../../common/constantes.h"


class Controlador; // declaracion forward

class Accion {

private:
	Controlador* controlador;

public:

	Accion(Controlador* control_);

	virtual void ejecutar(gdouble x,gdouble y)=0;

	Controlador* get_controlador()const;

	virtual ~Accion();
};

#endif /* COMMON_ACCION_H_ */

/**************************   Clase Accion_Draw_pista   *************/
/**************************   	Grupo 8                 *************/

#ifndef COMMON_ACCION_DRAW_PISTA_H_
#define COMMON_ACCION_DRAW_PISTA_H_

#include "common_Accion.h"

class Accion_Draw_pista: public Accion {

public:

	Accion_Draw_pista(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_Draw_pista();
};

#endif /* COMMON_ACCION_DRAW_PISTA_H_ */

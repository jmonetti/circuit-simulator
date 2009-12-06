#ifndef COMMON_ACCION_DRAW_CAJA_NEGRA_H_
#define COMMON_ACCION_DRAW_CAJA_NEGRA_H_

#include "common_Accion.h"

class Accion_Draw_Caja_Negra: public Accion {

public:

	Accion_Draw_Caja_Negra(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_Draw_Caja_Negra();

};

#endif /* COMMON_ACCION_DRAW_CAJA_NEGRA_H_ */

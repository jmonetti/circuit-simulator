/**************************   Clase Accion_Draw_XOR     *************/
/**************************   	Grupo 8                 *************/


#ifndef COMMON_ACCION_DRAW_XOR_H_
#define COMMON_ACCION_DRAW_XOR_H_

#include "common_Accion.h"

class Accion_Draw_XOR: public Accion {

public:

	Accion_Draw_XOR(Controlador* controlador);

	void ejecutar(gdouble x,gdouble y);

	virtual ~Accion_Draw_XOR();
};

#endif /* COMMON_ACCION_DRAW_XOR_H_ */

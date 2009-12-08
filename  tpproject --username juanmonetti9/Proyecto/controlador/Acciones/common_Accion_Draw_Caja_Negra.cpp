#include "common_Accion_Draw_Caja_Negra.h"
#include "../common_Controlador.h"

Accion_Draw_Caja_Negra::Accion_Draw_Caja_Negra(Controlador* controlador):Accion(controlador) {


}

void Accion_Draw_Caja_Negra::ejecutar(gdouble x,gdouble y){

	get_controlador()->agregar_caja_negra(x,y);

}


Accion_Draw_Caja_Negra::~Accion_Draw_Caja_Negra() {

}

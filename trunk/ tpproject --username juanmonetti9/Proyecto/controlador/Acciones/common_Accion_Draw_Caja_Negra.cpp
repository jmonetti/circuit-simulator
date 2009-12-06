#include "common_Accion_Draw_Caja_Negra.h"
#include "../common_Controlador.h"

Accion_Draw_Caja_Negra::Accion_Draw_Caja_Negra(Controlador* controlador):Accion(controlador) {


}

void Accion_Draw_Caja_Negra::ejecutar(gdouble x,gdouble y){

	get_controlador()->agregar_componente(x,y,T_CAJANEGRA);

}


Accion_Draw_Caja_Negra::~Accion_Draw_Caja_Negra() {

}

/**************************   Clase Accion_Draw_XOR     *************/
/**************************   	Grupo 8                 *************/


#include "common_Accion_Draw_XOR.h"
#include "../common_Controlador.h"

Accion_Draw_XOR::Accion_Draw_XOR(Controlador* controlador):Accion(controlador) {


}

void Accion_Draw_XOR::ejecutar(gdouble x,gdouble y){

	get_controlador()->agregar_componente(x,y,T_XOR);

}
Accion_Draw_XOR::~Accion_Draw_XOR() {

}

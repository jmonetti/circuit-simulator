/**************************   Clase Accion_Draw_NOT     *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_Draw_NOT.h"
#include "../common_Controlador.h"

Accion_NOT::Accion_NOT(Controlador* controlador):Accion(controlador) {

}

void Accion_NOT::ejecutar(gdouble x,gdouble y){

	get_controlador()->agregar_componente(x,y,T_NOT);
}
Accion_NOT::~Accion_NOT() {

}

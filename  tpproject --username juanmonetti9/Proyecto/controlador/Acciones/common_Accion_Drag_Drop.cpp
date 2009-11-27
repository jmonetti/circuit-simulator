/**************************   Clase Accion_Drag_Drop    *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_Drag_Drop.h"
#include "../common_Controlador.h"

Accion_Drag_Drop::Accion_Drag_Drop(Controlador* controlador):Accion(controlador){

}

void Accion_Drag_Drop::ejecutar(gdouble x,gdouble y){

	get_controlador()->set_pos_x_click(x);
	get_controlador()->set_pos_y_click(y);

}


Accion_Drag_Drop::~Accion_Drag_Drop() {

}

/**************************   Clase Accion_Invertir     *************/
/**************************   	Grupo 8                 *************/


#include "common_Accion_invertir_right.h"
#include "../common_Controlador.h"

Accion_invertir_right::Accion_invertir_right(Controlador* controlador):Accion(controlador) {


}

void Accion_invertir_right::ejecutar(gdouble x,gdouble y){

	get_controlador()->rotar_right(x,y);

}
Accion_invertir_right::~Accion_invertir_right() {

}

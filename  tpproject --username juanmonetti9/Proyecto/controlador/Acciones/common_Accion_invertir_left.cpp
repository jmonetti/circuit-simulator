/**************************   Clase Accion_Invertir     *************/
/**************************   	Grupo 8                 *************/


#include "common_Accion_invertir_left.h"
#include "../common_Controlador.h"

Accion_invertir_left::Accion_invertir_left(Controlador* controlador):Accion(controlador) {


}

void Accion_invertir_left::ejecutar(gdouble x,gdouble y){

	get_controlador()->rotar(x,y,IZQUIERDA);

}
Accion_invertir_left::~Accion_invertir_left() {

}

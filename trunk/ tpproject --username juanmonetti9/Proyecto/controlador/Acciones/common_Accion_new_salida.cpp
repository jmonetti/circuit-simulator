/**************************   Clase Accion_new_Salida   *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_new_salida.h"
#include "../common_Controlador.h"

Accion_new_salida::Accion_new_salida(Controlador* controlador):Accion(controlador) {


}

void Accion_new_salida::ejecutar(gdouble x,gdouble y){

	get_controlador()->agregar_componente(x,y,T_SALIDA);


}

Accion_new_salida::~Accion_new_salida() {

}

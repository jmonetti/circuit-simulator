/**************************   Clase Accion_new_entrada  *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_new_entrada.h"
#include "../common_Controlador.h"

Accion_new_entrada::Accion_new_entrada(Controlador* controlador):Accion(controlador) {


}

void Accion_new_entrada::ejecutar(gdouble x,gdouble y){
	get_controlador()->agregar_componente(x,y,T_ENTRADA);

}
Accion_new_entrada::~Accion_new_entrada() {

}

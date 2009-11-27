/**************************   Clase Accion_Draw_AND     *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_Draw_AND.h"
#include "../common_Controlador.h"

Accion_Draw_AND::Accion_Draw_AND(Controlador* controlador):Accion(controlador) {


}

void Accion_Draw_AND::ejecutar(gdouble x,gdouble y){

	get_controlador()->agregar_componente(x,y,T_AND);
}

Accion_Draw_AND::~Accion_Draw_AND() {

}

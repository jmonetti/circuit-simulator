/**************************   Clase Accion_Draw_OR      *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_Draw_OR.h"
#include "../common_Controlador.h"

Accion_OR::Accion_OR(Controlador* controlador):Accion(controlador) {


}

void Accion_OR::ejecutar(gdouble x,gdouble y){
	get_controlador()->agregar_componente(x,y,T_OR);
}

Accion_OR::~Accion_OR() {

}

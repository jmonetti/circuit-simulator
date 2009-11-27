/**************************   Clase Accion              *************/
/**************************   	Grupo 8                 *************/


#include "common_Accion.h"


Accion::Accion(Controlador* control_) {

	controlador=control_;

}

Controlador* Accion::get_controlador()const{

	return controlador;

}

Accion::~Accion() {

}

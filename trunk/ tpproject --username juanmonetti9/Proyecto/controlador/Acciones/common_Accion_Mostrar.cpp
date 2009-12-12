#include "common_Accion_Mostrar.h"
#include "../common_Controlador.h"

Accion_Mostrar::Accion_Mostrar(Controlador* controlador) : Accion(controlador) {


}

Accion_Mostrar::~Accion_Mostrar() {

}

void Accion_Mostrar::ejecutar(gdouble x,gdouble y) {

	get_controlador()->mostrar_caja_negra(x,y);

}

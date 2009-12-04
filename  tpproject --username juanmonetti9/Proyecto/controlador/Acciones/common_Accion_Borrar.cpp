/**************************   Clase Accion_Borrar       *************/
/**************************   	Grupo 8                 *************/

#include "common_Accion_Borrar.h"
#include "../common_Controlador.h"

Accion_Borrar::Accion_Borrar(Controlador* controlador):Accion(controlador) {


}
void Accion_Borrar::ejecutar(gdouble x,gdouble y){

	get_controlador()->eliminar_componente(x,y);
	//get_controlador()->agregar_componente(x,y,T_PISTA,NORTE);//TODO solo de prueba
}

Accion_Borrar::~Accion_Borrar() {

}

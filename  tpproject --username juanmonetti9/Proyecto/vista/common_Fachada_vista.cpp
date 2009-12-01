/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/

#include "common_Fachada_vista.h"

Fachada_vista::Fachada_vista(Box_Ventana_Interna* ventana_int) {

	ventana_interna=ventana_int;
}


void Fachada_vista::dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo,SENTIDO sentido){

	ventana_interna->dibujar_componente(x,y,tipo,sentido);
};


void Fachada_vista::activar_dnd(){

	ventana_interna->connect_dnd();
}

void Fachada_vista::completar_grilla(Resultado* resultado){

	ventana_interna->completar_tabla_actual(resultado);


}

void Fachada_vista::agregar_grilla(int id){

	ventana_interna->agregar_grilla(id);

}

int Fachada_vista::cambiar_grilla(int index){

	return ventana_interna->cambiar_grilla_actual(index);

}

void Fachada_vista::eliminar_grilla(){

	ventana_interna->eliminar_grilla_actual();

}

void Fachada_vista::desactivar_dnd(){

	ventana_interna->disconnect_dnd();

}

int Fachada_vista::getIdActual() const{

	return ventana_interna->getGrillaActual();

}

/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/

#include "common_Fachada_vista.h"

Fachada_vista::Fachada_vista(Box_Ventana_Interna* ventana_int) {

	ventana_interna=ventana_int;
}


void Fachada_vista::dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo){

	ventana_interna->dibujar_compuerta(x,y,tipo);
};


void Fachada_vista::activar_dnd(){

	ventana_interna->connect_dnd();
}

void Fachada_vista::desactivar_dnd(){

	ventana_interna->disconnect_dnd();

}

/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/

#include "common_Fachada_vista.h"

Fachada_vista::Fachada_vista(Box_Ventana_Interna* ventana_int) {

	ventana_interna=ventana_int;
}


void Fachada_vista::dibujar_componente(gdouble x,gdouble y,EstadoCelda estado){

	ventana_interna->dibujar_compuerta_xor(x,y);
};

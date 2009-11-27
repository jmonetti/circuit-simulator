/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/


#ifndef COMMON_FACHADA_VISTA_H_
#define COMMON_FACHADA_VISTA_H_

#include "common_Box_Ventana_Interna.h"
#include <gtkmm.h>
#include "../common/constantes.h"

class Fachada_vista {

private:

	Box_Ventana_Interna* ventana_interna;


public:

	Fachada_vista(Box_Ventana_Interna* ventata_int);

	void dibujar_componente(gdouble x,gdouble y,TIPO_COMPUERTA tipo);

	void activar_dnd();

	void desactivar_dnd();

};

#endif /* COMMON_FACHADA_VISTA_H_ */

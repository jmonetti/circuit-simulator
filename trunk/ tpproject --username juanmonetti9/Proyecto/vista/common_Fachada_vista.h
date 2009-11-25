/**************************   Clase Fachada_Vista      ************************/
/**************************   Grupo 8                  ************************/


#ifndef COMMON_FACHADA_VISTA_H_
#define COMMON_FACHADA_VISTA_H_

#include "common_Decorador_Menu.h"
#include "common_Decorador_Box_ventana.h"
class Fachada_vista {

private:

	Decorador_Menu* Menu;
	Decorador_Box_ventana* Ventana;

public:

	Fachada_vista();

	virtual ~Fachada_vista();
};

#endif /* COMMON_FACHADA_VISTA_H_ */

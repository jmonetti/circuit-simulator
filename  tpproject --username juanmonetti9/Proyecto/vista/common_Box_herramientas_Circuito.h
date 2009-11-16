/*****************   Clase Box herramientas circuito ****************/
/*****************   	   Grupo 8                   ****************/


#ifndef COMMON_BOX_HERRAMIENTAS_OPTIONS_H_
#define COMMON_BOX_HERRAMIENTAS_OPTIONS_H_

#include "common_Componente_Visual.h"
#include "gtkmm.h"
#include "botones/common_Boton_AND.h"
#include "botones/common_Boton_OR.h"
#include "botones/common_Boton_XOR.h"
#include "botones/common_Boton_NOT.h"
#include "botones/common_Boton_Pista.h"
#include "botones/common_Boton_Delete.h"
#include "botones/common_Boton_Invertir.h"

class Box_herramientas_Circuito: public Componente_Visual {

private:

	GtkWidget* _panel;

	Boton_OR OR;
	Boton_AND AND;
	Boton_NOT NOT;
	Boton_Pista PISTA;
	Boton_XOR XOR;
	Boton_Invertir invert;
	//Boton_Delete Delete;


public:

	Box_herramientas_Circuito();

	void show();

	void escalar(int _fa);

	GtkWidget* getWidget();

	virtual ~Box_herramientas_Circuito();
};

#endif /* COMMON_BOX_HERRAMIENTAS_CIRCUITO_H_ */

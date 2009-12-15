/*****************   Clase Box herramientas circuito ****************/
/*****************   	   Grupo 8                   ****************/


#ifndef COMMON_BOX_HERRAMIENTAS_CIRCUITO_H_
#define COMMON_BOX_HERRAMIENTAS_CIRCUITO_H_

#include "common_Componente_Visual.h"

#include "gtkmm.h"

#include "botones/common_Boton_Imprimir.h"
#include "botones/common_Boton_guardar.h"
#include "botones/common_Boton_Nuevo.h"
#include "botones/common_Boton_Abrir.h"



class Box_herramientas_Options: public Componente_Visual {

private:

	GtkWidget* _panel;
	GtkWidget* _panel_box1;
	GtkWidget* _panel_box2;


	Boton_Abrir abrir;
	Boton_guardar guardar;
	Boton_Nuevo nuevo;
	Boton_Imprimir imprimir;




public:

	Box_herramientas_Options();

	void show();

	void hide();

	void escalar(int _fa);

	GtkWidget* getWidget();

	virtual ~Box_herramientas_Options();
};

#endif /* COMMON_BOX_HERRAMIENTAS_OPTIONS_H_ */

/*****************   Clase Box herramientas circuito ****************/
/*****************   	   Grupo 8                   ****************/


#ifndef COMMON_BOX_HERRAMIENTAS_CIRCUITO_H_
#define COMMON_BOX_HERRAMIENTAS_CIRCUITO_H_

#include "common_Componente_Visual.h"

#include "gtkmm.h"
#include "botones/common_Boton_Selector.h"
#include "botones/common_Boton_Simular.h"
#include "botones/common_Boton_Invertir.h"
#include "botones/common_Boton_Imprimir.h"
#include "botones/common_Boton_Download.h"
#include "botones/common_Boton_Upload.h"



class Box_herramientas_Options: public Componente_Visual {

private:

	GtkWidget* _panel;

	Boton_Selector Select;
	Boton_Simular simular;
	Boton_Imprimir imprimir;
	Boton_Download download;
	Boton_Upload upload;




public:

	Box_herramientas_Options();

	void show();

	void escalar(int _fa);

	GtkWidget* getWidget();

	virtual ~Box_herramientas_Options();
};

#endif /* COMMON_BOX_HERRAMIENTAS_OPTIONS_H_ */

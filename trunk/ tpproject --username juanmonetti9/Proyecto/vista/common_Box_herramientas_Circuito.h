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
#include "botones/common_Boton_Selector.h"
#include "botones/common_Boton_Simular.h"
#include "botones/common_Boton_Invertir.h"
#include "botones/common_Boton_InvertirL.h"
#include "botones/common_Boton_Download.h"
#include "botones/common_Boton_Upload.h"
#include "botones/common_Boton_Salida.h"
#include "botones/common_Boton_entrada.h"
#include "botones/common_Boton_Mostrar.h"


const int WIDTH_BOTONERA= 68;
const int HEIGHT_BOTONERA= 470;

class Box_herramientas_Circuito: public Componente_Visual {

private:

	GtkWidget* _panel;
	GtkWidget* _panel_size;

	Boton_OR OR;
	Boton_AND AND;
	Boton_NOT NOT;
	Boton_Pista PISTA;
	Boton_XOR XOR;
	Boton_Invertir invert;
	Boton_InvertirL invertL;
	Boton_Delete Delete;
	Boton_Selector Select;
	Boton_Simular simular;
	Boton_Download download;
	Boton_Upload upload;
	Boton_entrada entrada;
	Boton_Salida salida;
	Boton_Mostrar mostrar;


public:

	Box_herramientas_Circuito();

	void show();

	void hide();

	void escalar(int _fa);

	GtkWidget* getWidget();

	virtual ~Box_herramientas_Circuito();
};

#endif /* COMMON_BOX_HERRAMIENTAS_CIRCUITO_H_ */

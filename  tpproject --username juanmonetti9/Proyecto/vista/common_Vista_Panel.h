/**************************   Clase Vista_Panel        *************************/
/**************************   Grupo 8                 *************************/

#ifndef CLASS_COMMON_VISTA_PANEL_H
#define CLASS_COMMON_VISTA_PANEL_H

#include "gtkmm.h"
#include "common_Componente_Visual.h"
#include "botones/common_Boton_AND.h"
#include "botones/common_Boton_OR.h"
#include "botones/common_Boton_XOR.h"
#include "botones/common_Boton_NOT.h"
#include "botones/common_Boton_Pista.h"
#include "botones/common_Boton_Selector.h"
#include "botones/common_Boton_Delete.h"
#include "botones/common_Boton_Simular.h"
#include "botones/common_Boton_Invertir.h"
#include "botones/common_Boton_Imprimir.h"
#include "botones/common_Boton_Download.h"
#include "botones/common_Boton_Upload.h"
#include "common_Box_herramientas_Circuito.h"
#include "common_Box_herramientas_options.h"


const int SIZE_COMPUERTA=40;
const int WIDTH_scroll=500;
const int HEIGHT_scroll=580;


class Vista_Panel: public Componente_Visual{

	private:

	GtkWidget* box_panel;
	Box_herramientas_Circuito box_circuit;
	Box_herramientas_Options box_options;



	public:

		/**
		 * Constructor
		 */
		Vista_Panel();

		/**
		 * Muestra el panel
		 */
		void show();

		/**
		 * Da un nuevo tamanio al componente visual
		 * @param: factor de amplificacion de la escala
		 */
		void escalar(int _fa);

		/**
		 * Retorna el widget
		 */
		GtkWidget* getWidget();

};
#endif


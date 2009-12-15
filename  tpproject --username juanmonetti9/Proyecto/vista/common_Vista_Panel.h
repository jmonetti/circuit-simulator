/**************************   Clase Vista_Panel        *************************/
/**************************   Grupo 8                 *************************/

#ifndef CLASS_COMMON_VISTA_PANEL_H
#define CLASS_COMMON_VISTA_PANEL_H

#include "gtkmm.h"
#include "common_Componente_Visual.h"
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

		void hide();

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


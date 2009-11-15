/**************************   Clase Vista_Panel        *************************/
/**************************   Grupo 8                 *************************/

#ifndef CLASS_COMMON_VISTA_PANEL_H
#define CLASS_COMMON_VISTA_PANEL_H

#include "gtkmm.h"
#include "common_Componente_Visual.h"
#include "common_Boton.h"

const int SIZE_COMPUERTA=40;
const int WIDTH_botton=75;
const int HEIGHT_botton=32;
const int WIDTH_scroll=500;
const int HEIGHT_scroll=580;


class Vista_Panel: public Componente_Visual{

	private:
	GtkWidget* box_panel;
	const static int CANT_BOTONES= 5;
	Boton botones[CANT_BOTONES];


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

/**************************   Clase Vista_Panel        *************************/
/**************************   Grupo 8                 *************************/

#ifndef CLASS_COMMON_VISTA_PANEL_H
#define CLASS_COMMON_VISTA_PANEL_H

#include "gtkmm.h"
#include "common_Componente_Visual.h"

const int SIZE_COMPUERTA=40;
const int WIDTH_botton=75;
const int HEIGHT_botton=32;
const int WIDTH_scroll=500;
const int HEIGHT_scroll=580;


class Vista_Panel: public Componente_Visual{

	private:
	GtkWidget* box_panel;
	GtkWidget* AND;
	GtkWidget* OR;
	GtkWidget* XOR;
	GtkWidget* NOT;
	GtkWidget* PISTA;
	GtkWidget* ENTRADA;
	GtkWidget* SALIDA;
	GtkWidget* DELETE;
	GtkWidget* INVERTIR;


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

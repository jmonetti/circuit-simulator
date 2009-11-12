/**************************   Clase Vista_Menu           ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_VISTA_MENU_H
#define CLASS_COMMON_VISTA_MENU_H

#include "gtkmm.h"
#include "common_Decorador.h"
#include "common_Componente_Visual.h"

class Decorador_Menu :public Decorador{

private:

	GtkWidget* menu[4];
	GtkWidget* root_menu[4];
	GtkWidget* menu_1_items[4];
	GtkWidget* menu_2_items[4];
	GtkWidget* menu_bar;
	GtkWidget* _box;



	public:
		/**
		 * Constructor
		 */
		Decorador_Menu(Componente_Visual* componente);

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

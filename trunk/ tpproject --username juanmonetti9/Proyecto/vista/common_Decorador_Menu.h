/**************************   Clase Vista_Menu           ********************/
/**************************   Grupo 8                      ********************/

#ifndef CLASS_COMMON_VISTA_MENU_H
#define CLASS_COMMON_VISTA_MENU_H

#include "gtkmm.h"
#include "common_Decorador.h"
#include "common_Componente_Visual.h"

class Decorador_Menu :public Decorador{

private:

	GtkWidget* _box;
	GtkWidget* menu_bar;
	GtkWidget* menu[4];
	GtkWidget* root_menu[4];
	GtkWidget* items_archivo[5];
	GtkWidget* items_ventana[5];
	GtkWidget* items_circuito[6];


	void cargar_Opcion_Archivo();

	void cargar_Opcion_Ventana();

	void cargar_Opcion_Circuito();

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

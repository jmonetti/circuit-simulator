/**************************   Clase Vista_Menu             ********************/
/**************************   Grupo 8                      ********************/

#include "common_Decorador_Menu.h"
#include "../controlador/common_Controladores_Archivo.h"
#include "../controlador/common_Controladores_Circuito.h"

Decorador_Menu::Decorador_Menu(Componente_Visual* componente):Decorador(componente){


	//Creo barra de menu
	menu_bar = gtk_menu_bar_new();
	gtk_widget_show(menu_bar);
	//creo la caja contenedora y le agrego el manu bar
	_box= gtk_vbox_new(false,0);
	gtk_box_pack_start(GTK_BOX(_box), menu_bar, FALSE, FALSE, 2);
	//agrego el componente decorado
	gtk_container_add (GTK_CONTAINER (_box),componente->getWidget());

	//agrego opciones de menu
	cargar_Opcion_Archivo();
	cargar_Opcion_Ventana();
	cargar_Opcion_Circuito();



}

/*----------------------------------------------------------------------------*/

void Decorador_Menu::cargar_Opcion_Archivo(){

	//creo el primer sub_menu
	menu[0] = gtk_menu_new();

	//Creo el y muestro el indicador Archivo
	 root_menu[0] = gtk_menu_item_new_with_label("Archivo");
	 gtk_widget_show(root_menu[0]);

	//Creo e inicializo el item Nuevo
	items_archivo[0] = gtk_menu_item_new_with_label("Nuevo");
	gtk_menu_append(GTK_MENU (menu[0]), items_archivo[0]);
	gtk_widget_show(items_archivo[0]);
	gtk_signal_connect_object(GTK_OBJECT(items_archivo[0]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Archivo::callback_nuevo), NULL);
	//Creo e inicializo el item abrir
	items_archivo[1] = gtk_menu_item_new_with_label("Abrir");
	gtk_menu_append(GTK_MENU (menu[0]), items_archivo[1]);
	gtk_widget_show(items_archivo[1]);
	gtk_signal_connect_object(GTK_OBJECT(items_archivo[1]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Archivo::callback_abrir), NULL);
	//Creo e inicializo el item Guardar
	items_archivo[2] = gtk_menu_item_new_with_label("Guardar");
	gtk_menu_append(GTK_MENU (menu[0]), items_archivo[2]);
	gtk_widget_show(items_archivo[2]);
	gtk_signal_connect_object(GTK_OBJECT(items_archivo[2]), "activate",
				GTK_SIGNAL_FUNC(Controlador_Archivo::callback_guardar), NULL);
	//Creo e inicializo el item Imprimir
	items_archivo[3] = gtk_menu_item_new_with_label("Imprimir");
	gtk_menu_append(GTK_MENU (menu[0]), items_archivo[3]);
	gtk_widget_show(items_archivo[3]);
	gtk_signal_connect_object(GTK_OBJECT(items_archivo[3]), "activate",
				GTK_SIGNAL_FUNC(Controlador_Archivo::callback_Imprimir), NULL);
	//Creo e inicializo el item Cerrar
	items_archivo[4] = gtk_menu_item_new_with_label("Cerrar");
	gtk_menu_append(GTK_MENU (menu[0]), items_archivo[4]);
	gtk_widget_show(items_archivo[4]);
	gtk_signal_connect_object(GTK_OBJECT(items_archivo[4]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Archivo::callback_cerrar), NULL);
	//lo cargo
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu[0]), menu[0]);

	//Agrego los submenues a la barra de menu
	 gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu[0]);
}


void Decorador_Menu::cargar_Opcion_Ventana(){

	//Creo el submenu Ventana
	menu[1] = gtk_menu_new();
	//Creo el y muestro el indicador Ver
	root_menu[1] = gtk_menu_item_new_with_label("Ventana");
	gtk_widget_show(root_menu[1]);

	//Creo e inicializo el item Cerrar_Actual
	items_ventana[0] = gtk_menu_item_new_with_label("Cerrar Actual");
	gtk_menu_append(GTK_MENU (menu[1]), items_ventana[0]);
	gtk_widget_show(items_ventana[0]);
	gtk_signal_connect_object(GTK_OBJECT(items_ventana[0]), "activate",
				GTK_SIGNAL_FUNC(Controlador_Archivo::callback_cerrar_ventana_circuit), NULL);

	//lo cargo
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu[1]), menu[1]);
    //Agrego los submenues a la barra de menu
    gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu[1]);


}

void Decorador_Menu::cargar_Opcion_Circuito(){

	//Creo el submenu Circuito
	menu[2] = gtk_menu_new();
	//Creo el y muestro el indicador Circuito
	root_menu[2] = gtk_menu_item_new_with_label("Circuito");
	gtk_widget_show(root_menu[2]);

	//Creo e inicializo el item compuerta and
	items_circuito[0] = gtk_menu_item_new_with_label("Compuerta AND");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[0]);
	gtk_widget_show(items_circuito[0]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[0]), "activate",
					GTK_SIGNAL_FUNC(Controlador_Circuito::callback_AND), NULL);
	//Creo e inicializo el item compuerta or
	items_circuito[1] = gtk_menu_item_new_with_label("Compuerta OR");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[1]);
	gtk_widget_show(items_circuito[1]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[1]), "activate",
					GTK_SIGNAL_FUNC(Controlador_Circuito::callback_OR), NULL);
	//Creo e inicializo el item compuerta NOT
	items_circuito[2] = gtk_menu_item_new_with_label("Compuerta NOT");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[2]);
	gtk_widget_show(items_circuito[2]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[2]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_NOT), NULL);

	//Creo e inicializo el item compuerta Xor
	items_circuito[3] = gtk_menu_item_new_with_label("Compuerta XOR");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[3]);
	gtk_widget_show(items_circuito[3]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[3]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_XOR), NULL);

	//Creo e inicializo el item compuerta Pista
	items_circuito[4] = gtk_menu_item_new_with_label("Pista");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[4]);
	gtk_widget_show(items_circuito[4]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[4]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_Pista), NULL);


	//Creo e inicializo el item Entrada
	items_circuito[5] = gtk_menu_item_new_with_label("Entrada");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[5]);
	gtk_widget_show(items_circuito[5]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[5]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_crear_entrada), NULL);

	//Creo e inicializo el item Salida
	items_circuito[6] = gtk_menu_item_new_with_label("Salida");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[6]);
	gtk_widget_show(items_circuito[6]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[6]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_crear_salida), NULL);

	//Creo e inicializo el item Subir circuito
	items_circuito[7] = gtk_menu_item_new_with_label("Subir Circuito");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[7]);
	gtk_widget_show(items_circuito[7]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[7]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_crear_Upload), NULL);

	//Creo e inicializo el item descargar circuito
	items_circuito[8] = gtk_menu_item_new_with_label("Descargar Circuito");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[8]);
	gtk_widget_show(items_circuito[8]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[8]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_crear_Download), NULL);

	//Creo e inicializo el item Simular
	items_circuito[9] = gtk_menu_item_new_with_label("Simular");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[9]);
	gtk_widget_show(items_circuito[9]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[9]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_Simulacion), NULL);

	//Creo e inicializo el item Rotar Izquierda
	items_circuito[10] = gtk_menu_item_new_with_label("Rotar Izquierda");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[10]);
	gtk_widget_show(items_circuito[10]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[10]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_InvertirL), NULL);

	//Creo e inicializo el item Rotar Derecha
	items_circuito[11] = gtk_menu_item_new_with_label("Rotar Derecha");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[11]);
	gtk_widget_show(items_circuito[11]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[11]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_InvertirR), NULL);

	//Creo e inicializo el item Eliminar
	items_circuito[12] = gtk_menu_item_new_with_label("Eliminar");
	gtk_menu_append(GTK_MENU (menu[2]), items_circuito[12]);
	gtk_widget_show(items_circuito[12]);
	gtk_signal_connect_object(GTK_OBJECT(items_circuito[12]), "activate",
			GTK_SIGNAL_FUNC(Controlador_Circuito::callback_Delete), NULL);


	//lo cargo
	gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu[2]), menu[2]);
	//Agrego los submenues a la barra de menu
	gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu[2]);

}

void Decorador_Menu::show(){

	show_componente();
    gtk_widget_show(_box);
}

void Decorador_Menu::hide() {

	gtk_widget_hide(_box);
}
/*----------------------------------------------------------------------------*/

GtkWidget* Decorador_Menu::getWidget(){
	return _box;
}

/*----------------------------------------------------------------------------*/



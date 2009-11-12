/**************************   Clase Vista_Menu             ********************/
/**************************   Grupo 8                      ********************/

#include "common_Decorador_Menu.h"

Decorador_Menu::Decorador_Menu(Componente_Visual* componente):Decorador(componente){

	//creo el primer menu
	menu[0] = gtk_menu_new();
	//Acciones del primer indicador
	menu_1_items[0] = gtk_menu_item_new_with_label("Archivo_1");
	gtk_menu_append(GTK_MENU (menu[0]), menu_1_items[0]);
	gtk_widget_show(menu_1_items[0]);
	/*TODO para activar señal-> gtk_signal_connect_object(GTK_OBJECT(menu_items), "activate",
	 GTK_SIGNAL_FUNC(menuitem_response), (gpointer) g_strdup(buf));*/

	menu_1_items[1] = gtk_menu_item_new_with_label("Archivo_2");
    gtk_menu_append(GTK_MENU (menu[0]), menu_1_items[1]);
    gtk_widget_show(menu_1_items[1]);

    menu_1_items[2] = gtk_menu_item_new_with_label("Archivo_3");
    gtk_menu_append(GTK_MENU (menu[0]), menu_1_items[2]);
    gtk_widget_show(menu_1_items[2]);

    menu_1_items[3] = gtk_menu_item_new_with_label("Archivo_4");
    gtk_menu_append(GTK_MENU (menu[0]), menu_1_items[3]);
    gtk_widget_show(menu_1_items[3]);

    //Creo el primer indicador del menu
    root_menu[0] = gtk_menu_item_new_with_label("Archivo");
    gtk_widget_show(root_menu[0]);

    /* Ahora especificamos que queremos que el recien creado "menu"
     * sea el menú para el "root menu" */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu[0]), menu[0]);


	//creo el Segundo menu
	menu[1] = gtk_menu_new();
	//Acciones del primer indicador
	menu_2_items[0] = gtk_menu_item_new_with_label("Ver_1");
	gtk_menu_append(GTK_MENU (menu[1]), menu_2_items[0]);
	gtk_widget_show(menu_2_items[0]);
	/*TODO para activar señal-> gtk_signal_connect_object(GTK_OBJECT(menu_items), "activate",
	 GTK_SIGNAL_FUNC(menuitem_response), (gpointer) g_strdup(buf));*/

	menu_2_items[1] = gtk_menu_item_new_with_label("Ver_2");
    gtk_menu_append(GTK_MENU (menu[1]), menu_2_items[1]);
    gtk_widget_show(menu_2_items[1]);

    menu_2_items[2] = gtk_menu_item_new_with_label("Ver_3");
    gtk_menu_append(GTK_MENU (menu[1]), menu_2_items[2]);
    gtk_widget_show(menu_2_items[2]);

    menu_2_items[3] = gtk_menu_item_new_with_label("Ver_4");
    gtk_menu_append(GTK_MENU (menu[1]), menu_2_items[3]);
    gtk_widget_show(menu_2_items[3]);

    //Creo el primer indicador del menu
    root_menu[1] = gtk_menu_item_new_with_label("Ver");
    gtk_widget_show(root_menu[1]);

    /* Ahora especificamos que queremos que el recien creado "menu"
     * sea el menú para el "root menu" */
    gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu[1]), menu[1]);



    //Creo barra de menu
    menu_bar = gtk_menu_bar_new();
    gtk_widget_show(menu_bar);
    //Agrego los submenues a la barra de menu
    gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu[0]);
    gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu[1]);

    _box= gtk_vbox_new(false,0);
    gtk_box_pack_start(GTK_BOX(_box), menu_bar, FALSE, FALSE, 2);
    gtk_container_add (GTK_CONTAINER (_box),componente->getWidget());

}

/*----------------------------------------------------------------------------*/

void Decorador_Menu::show(){

	show_componente();
    gtk_widget_show(_box);
}
/*----------------------------------------------------------------------------*/
void Decorador_Menu::escalar(int _fa){

}

GtkWidget* Decorador_Menu::getWidget(){
	return _box;
}



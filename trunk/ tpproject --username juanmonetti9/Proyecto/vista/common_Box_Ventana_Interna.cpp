/**************************   Clase Box_Ventana_Interna   *********************/
/**************************   Grupo 8                     *********************/

#include "common_Box_Ventana_Interna.h"

Box_Ventana_Interna::Box_Ventana_Interna(){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,0);

	//TODO
	GtkWidget* noteb= gtk_notebook_new();
	gtk_notebook_set_tab_pos((GtkNotebook*)noteb,GTK_POS_RIGHT);
	gtk_widget_show (noteb);
	GtkWidget* label = gtk_label_new ("Circuito 1");

	gtk_widget_show (label);
	grilla.show();
	gtk_notebook_append_page (GTK_NOTEBOOK (noteb), grilla.getWidget(), label);

	gtk_container_add (GTK_CONTAINER (_box_ventana),noteb);
	//fin TODO

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::show(){

    gtk_widget_show (_box_ventana);

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::escalar(int _fa){

}
/*----------------------------------------------------------------------------*/

GtkWidget* Box_Ventana_Interna::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

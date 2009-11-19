/**************************   Clase TAB GRILLA  **********************/
/**************************   	Grupo 8         **********************/

#include "common_Tab_Grilla.h"

Tab_Grilla::Tab_Grilla() {

	//Creo el tab
	tab_grilla= gtk_hbox_new(false,0);
	label_grilla= gtk_label_new ("Circuito  ");
	boton_grilla= gtk_button_new();
	box_image= gtk_hbox_new(false,0);
	imagen= gtk_image_new_from_file("imagenes/Close.png");

	gtk_container_add(GTK_CONTAINER(boton_grilla),box_image);
	gtk_box_pack_start(GTK_BOX(box_image), imagen, true, true, 0);
	gtk_box_pack_start(GTK_BOX(tab_grilla),label_grilla, true, true, 0);
	gtk_box_pack_start(GTK_BOX(tab_grilla),boton_grilla, true, true, 0);

	gtk_widget_set_usize(boton_grilla,16,18);
	gtk_widget_show(boton_grilla);
	gtk_widget_show(box_image);
	gtk_widget_show(imagen);
	gtk_widget_show (label_grilla);

}

void Tab_Grilla::show() {

	gtk_widget_show(tab_grilla);

}

void Tab_Grilla::escalar(int fa) {


}

GtkWidget* Tab_Grilla::getWidget() {

	return tab_grilla;

}
Tab_Grilla::~Tab_Grilla(){

}

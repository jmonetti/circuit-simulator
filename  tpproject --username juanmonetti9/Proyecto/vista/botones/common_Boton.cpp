/**************************   Clase BOTON   *************************/
/**************************   	Grupo 8     *************************/

#include "common_Boton.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton::Boton() {

	box= gtk_hbox_new(false,0);

	boton= gtk_button_new();



	gtk_container_add(GTK_CONTAINER(boton), box);

}

void Boton::agregarImagen(gchar* image) {

	GtkWidget* imagen= gtk_image_new_from_file(image);

	gtk_box_pack_start(GTK_BOX(box), imagen, true, true, 0);

	gtk_widget_show(imagen);

}

void Boton::show() {

	gtk_widget_show(boton);
	gtk_widget_show(box);

}

GtkWidget* Boton::getWidget() {

	return boton;

}

void Boton::escalar(int fa) {

}

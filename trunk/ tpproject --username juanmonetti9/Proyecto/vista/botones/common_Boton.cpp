/**************************   Clase BOTON   *************************/
/**************************   	Grupo 8     *************************/

#include "common_Boton.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton::Boton() {

	box= gtk_hbox_new(false,0);
	boton= gtk_button_new();
	tooltip= gtk_tooltips_new();

	gtk_container_add(GTK_CONTAINER(boton), box);

	//gtk_widget_set_usize(getWidget(),WIDTH_boton,HEIGHT_boton);

}

void Boton::agregarImagen(gchar* image) {

	GtkWidget* imagen= gtk_image_new_from_file(image);

	gtk_box_pack_start(GTK_BOX(box), imagen, true, true, 0);

	gtk_widget_show(imagen);

}
void Boton::agregarToolTip(gchar* etiqueta) {

	gtk_tooltips_set_tip(tooltip,boton,etiqueta,NULL);
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

/**************************   Clase GRILLA   *************************/
/**************************   	Grupo 8      *************************/

#include "common_Grilla.h"

Grilla::Grilla() {

	//Creo el notebook
	notebook= gtk_notebook_new();
	tab_noteb1= gtk_label_new ("Area de diseño");
	tab_noteb2= gtk_label_new ("Tabla logica");
	box_noteb1= gtk_hbox_new(false,0);
	box_noteb2= gtk_hbox_new(false,0);
	gtk_widget_show(tab_noteb1);
	gtk_widget_show(tab_noteb2);
	gtk_widget_show(box_noteb1);
	gtk_widget_show(box_noteb2);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook),box_noteb1,tab_noteb1);
	gtk_notebook_append_page (GTK_NOTEBOOK (notebook), box_noteb2,tab_noteb2);


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

void Grilla::show() {

	gtk_widget_show(notebook);
	gtk_widget_show(tab_grilla);

}

void Grilla::escalar(int fa) {


}

GtkWidget* Grilla::getWidget() {

	return notebook;

}

GtkWidget* Grilla::get_tabGrilla(){

	return tab_grilla;
}


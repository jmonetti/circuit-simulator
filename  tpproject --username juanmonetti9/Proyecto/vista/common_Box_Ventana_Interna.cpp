/**************************   Clase Box_Ventana_Interna   *********************/
/**************************   Grupo 8                     *********************/

#include "common_Box_Ventana_Interna.h"

Box_Ventana_Interna::Box_Ventana_Interna(){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,0);
	//Creo la notebook
	noteb= gtk_notebook_new();
	gtk_notebook_set_tab_pos((GtkNotebook*)noteb,GTK_POS_RIGHT);
	gtk_widget_show (noteb);
	agregar_AreaDisenio();
	//TODO Solo para mostrar una grilla mas
	grilla1.show();
	GtkWidget* label_grilla= gtk_label_new ("Circuito");
	gtk_notebook_append_page (GTK_NOTEBOOK (noteb), grilla1.getWidget(),label_grilla);
	//fin TODO
	//Agrego la notebook a la obx principal
	gtk_container_add (GTK_CONTAINER (_box_ventana),noteb);



}

void Box_Ventana_Interna::agregar_AreaDisenio(){

	grilla.show();
	GtkWidget* label_grilla= gtk_label_new ("Circuito");
	gtk_notebook_append_page (GTK_NOTEBOOK (noteb), grilla.getWidget(),label_grilla);

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::show(){

    gtk_widget_show (_box_ventana);

}
/*----------------------------------------------------------------------------*/

void Box_Ventana_Interna::escalar(int _fa){

}

void Box_Ventana_Interna::eliminar_pestania_actual(){

	gint page_num =gtk_notebook_get_current_page(GTK_NOTEBOOK(noteb));
	gtk_notebook_remove_page(GTK_NOTEBOOK(noteb), page_num);

}

void Box_Ventana_Interna::agregar_pestania(){
	//TODO agregar a una lista de paginas o something
	void gtk_notebook_prepend_page( GtkNotebook *notebook,
	                                GtkWidget   *child,
	                                GtkWidget   *tab_label );

}
/*----------------------------------------------------------------------------*/

GtkWidget* Box_Ventana_Interna::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

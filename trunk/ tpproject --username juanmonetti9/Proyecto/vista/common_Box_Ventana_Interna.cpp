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
	//Agrego la notebook a la obx principal
	gtk_container_add (GTK_CONTAINER (_box_ventana),noteb);



}

void Box_Ventana_Interna::agregar_AreaDisenio(){

	grilla.show();
	gtk_notebook_append_page (GTK_NOTEBOOK (noteb), grilla.getWidget(), grilla.get_tabGrilla());

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

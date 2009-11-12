/**************************   Clase Box_Ventana       *************************/
/**************************   Grupo 8                 *************************/

#include "common_Box_Ventana.h"

Box_Ventana::Box_Ventana():_decorador_scroll(&_box_ventana_int){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,0);

	//incluyo el panel en el box
	gtk_container_add (GTK_CONTAINER (_box_ventana),_panel.getWidget());
	//TODO
	_decorador_scroll.set_dimensiones(500,500);
	//fin TODO

	gtk_container_add (GTK_CONTAINER (_box_ventana),_decorador_scroll.getWidget());
}

/*----------------------------------------------------------------------------*/

void Box_Ventana::show(){

    gtk_widget_show (_box_ventana);
    _panel.show();
    _decorador_scroll.show();


}
/*----------------------------------------------------------------------------*/

void Box_Ventana::escalar(int _fa){

}
/*----------------------------------------------------------------------------*/

GtkWidget* Box_Ventana::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

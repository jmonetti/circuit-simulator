/**************************   Clase Box_Ventana       *************************/
/**************************   Grupo 8                 *************************/

#include "common_Box_Ventana.h"

Box_Ventana::Box_Ventana():_decorador_scroll(&_box_ventana_int){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,false);

	//incluyo el panel en el box
	//gtk_container_add (GTK_CONTAINER (_box_ventana),_panel.getWidget());
	gtk_box_pack_start(GTK_BOX (_box_ventana),_panel.getWidget(),false,false,false);
	//TODO gronchada para dimensinar
	_decorador_scroll.set_dimensiones(700,500);
	//fin TODO

	//agrego el decorador a la caja
	gtk_box_pack_start(GTK_BOX (_box_ventana),_decorador_scroll.getWidget(),true,true,true);

	//Creo y agrego el boton de cierre de ventanas
	box_boton= gtk_vbox_new(false,false);
	gtk_box_pack_start(GTK_BOX (box_boton),_boton_close_pestania.getWidget(),false,true,false);
	gtk_box_pack_start(GTK_BOX (_box_ventana),box_boton,false,true,false);

	//TODO conecto para cerrar pestanias
	_boton_close_pestania.conectar(&this->_box_ventana_int);
	//fin todo
}

/*----------------------------------------------------------------------------*/

void Box_Ventana::show(){

	gtk_widget_show (box_boton);
	gtk_widget_show (_box_ventana);
	_panel.show();
	_decorador_scroll.show();
	_boton_close_pestania.show();



}
/*----------------------------------------------------------------------------*/

void Box_Ventana::escalar(int _fa){

}
/*----------------------------------------------------------------------------*/

GtkWidget* Box_Ventana::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

/**************************   Clase Box_Ventana       *************************/
/**************************   Grupo 8                 *************************/

#include "common_Box_ventana.h"

Box_ventana::Box_ventana(){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,false);

	//incluyo el panel en el box
	gtk_box_pack_start(GTK_BOX (_box_ventana),_panel.getWidget(),false,false,false);

	//agrego el decorador a la caja
	gtk_box_pack_start(GTK_BOX (_box_ventana),_box_ventana_int.getWidget(),true,true,true);

	//Creo y agrego el boton de cierre de ventanas
	gtk_box_pack_start(GTK_BOX (_box_ventana),boton_close_pestania.get_Box_Widget(),false,true,false);

	//TODO conecto para cerrar pestanias
	boton_close_pestania.conectar(&this->_box_ventana_int);
	//fin todo
}

/*----------------------------------------------------------------------------*/

void Box_ventana::show(){


	gtk_widget_show (_box_ventana);
	_panel.show();
	_box_ventana_int.show();
	boton_close_pestania.show();



}
/*----------------------------------------------------------------------------*/

void Box_ventana::escalar(int _fa){

}
/*----------------------------------------------------------------------------*/

GtkWidget* Box_ventana::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

Box_ventana::~Box_ventana(){

}

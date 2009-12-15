/**************************   Clase Box_Ventana       *************************/
/**************************   Grupo 8                 *************************/

#include "common_Decorador_Box_ventana.h"

Decorador_Box_ventana::Decorador_Box_ventana(Componente_Visual* componente):Decorador(componente){

	//Creo el box de la ventana
	_box_ventana= gtk_hbox_new(false,false);

	//incluyo el panel en el box
	gtk_box_pack_start(GTK_BOX (_box_ventana),_panel.getWidget(),false,false,false);

	//agrego el componente a la caja
	gtk_box_pack_start(GTK_BOX (_box_ventana),componente->getWidget(),true,true,true);

	//Creo y agrego el boton de cierre de ventanas
	gtk_box_pack_start(GTK_BOX (_box_ventana),boton_close_pestania.get_Box_Widget(),false,true,false);

	boton_close_pestania.conectar();

}

/*----------------------------------------------------------------------------*/

void Decorador_Box_ventana::show(){

	show_componente();
	gtk_widget_show (_box_ventana);
	_panel.show();
	boton_close_pestania.show();



}

void Decorador_Box_ventana::hide() {

	gtk_widget_hide (_box_ventana);
}

/*----------------------------------------------------------------------------*/

GtkWidget* Decorador_Box_ventana::getWidget(){
	return _box_ventana;
}
/*----------------------------------------------------------------------------*/

Decorador_Box_ventana::~Decorador_Box_ventana(){

}

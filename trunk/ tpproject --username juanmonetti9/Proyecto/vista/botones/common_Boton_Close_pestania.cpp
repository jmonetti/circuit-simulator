/*
 * common_Boton_CloseWin.cpp
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#include "common_Boton_Close_pestania.h"
#include "../../controlador/common_Controladores_Archivo.h"

Boton_Close_pestania::Boton_Close_pestania():Boton() {
	box_boton= gtk_vbox_new(false,false);
	gtk_box_pack_start(GTK_BOX (box_boton),getWidget(),false,true,false);
	gtk_widget_show (box_boton);
	agregarImagen((gchar*)"imagenes/close.png");
	agregarToolTip((gchar*)"Cerrar pestaña en uso");




}

GtkWidget*  Boton_Close_pestania::get_Box_Widget(){

	return this->box_boton;
}


void Boton_Close_pestania::conectar(void* param){
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Archivo::callback_cerrar_ventana_circuit), param);
}

Boton_Close_pestania::~Boton_Close_pestania() {

}

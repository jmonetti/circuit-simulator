/*
 * common_Boton_Nuevo.cpp
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#include "common_Boton_Nuevo.h"

Boton_Nuevo::Boton_Nuevo():Boton() {

	agregarImagen((gchar*)"imagenes/new.png");
	agregarToolTip((gchar*)"Nuevo circuito");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Archivo::callback_nuevo), NULL);



}

Boton_Nuevo::~Boton_Nuevo() {

}

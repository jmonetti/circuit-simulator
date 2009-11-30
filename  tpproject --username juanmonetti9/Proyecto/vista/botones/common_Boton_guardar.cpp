/*
 * common_Boton_guardar.cpp
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#include "common_Boton_guardar.h"
#include "../../controlador/common_Controladores_Archivo.h"

Boton_guardar::Boton_guardar() {

	agregarImagen((gchar*)"imagenes/guardar.png");
	agregarToolTip((gchar*)"Guardar circuito");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Archivo::callback_guardar), NULL);



}

Boton_guardar::~Boton_guardar() {

}

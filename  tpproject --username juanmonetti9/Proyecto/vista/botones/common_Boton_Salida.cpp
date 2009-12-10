/*
 * common_Boton_Salida.cpp
 *
 *  Created on: 30/11/2009
 *      Author: juanm
 */

#include "common_Boton_Salida.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Salida::Boton_Salida() {

	agregarImagen((gchar*)"imagenes/salida.png");
	agregarToolTip((gchar*)"Agregar salida");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_crear_salida), NULL);


}

Boton_Salida::~Boton_Salida() {

}

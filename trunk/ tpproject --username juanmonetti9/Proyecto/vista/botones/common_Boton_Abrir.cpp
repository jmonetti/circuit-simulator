/*
 * common_Boton_Abrir.cpp
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#include "common_Boton_Abrir.h"
#include "../../controlador/common_Controladores_Archivo.h"

Boton_Abrir::Boton_Abrir():Boton() {
	agregarImagen((gchar*)"imagenes/abrir.png");
	agregarToolTip((gchar*)"Abrir circuito");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Archivo::callback_abrir), NULL);


}

Boton_Abrir::~Boton_Abrir() {

}

/*
 * common_Boton_CloseWin.cpp
 *
 *  Created on: 19/11/2009
 *      Author: juanm
 */

#include "common_Boton_CloseWin.h"
#include "../../controlador/common_Controlador_Archivo.h"

Boton_CloseWin::Boton_CloseWin():Boton() {

	agregarImagen((gchar*)"imagenes/close.png");
	agregarToolTip((gchar*)"Cerrar pestaña en uso");




}

void Boton_CloseWin::conectar(void* param){
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Archivo::callback_cerrar_ventana_circuit), param);
}
Boton_CloseWin::~Boton_CloseWin() {

}

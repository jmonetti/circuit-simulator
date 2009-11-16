/**************************   Clase BOTON NOT ***********************/
/**************************   	Grupo 8       ***********************/

#include "common_Boton_NOT.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_NOT::Boton_NOT():Boton() {

	agregarImagen((gchar*)"imagenes/NOT.png");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_NOT), NULL);

}

Boton_NOT::~Boton_NOT() {

}

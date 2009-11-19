/**************************   Clase BOTON NOT ***********************/
/**************************   	Grupo 8       ***********************/

#include "common_Boton_NOT.h"
#include "../../controlador/common_Controlador_Circuito.h"

Boton_NOT::Boton_NOT():Boton() {

	agregarImagen((gchar*)"imagenes/NOT.png");
	agregarToolTip((gchar*)"Agregar compuerta NOT");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_NOT), NULL);

}

Boton_NOT::~Boton_NOT() {

}

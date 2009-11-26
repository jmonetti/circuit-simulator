/**************************   Clase BOTON AND ***********************/
/**************************   	Grupo 8       ***********************/

#include "common_Boton_AND.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_AND::Boton_AND():Boton() {

	agregarImagen((gchar*)"imagenes/AND.png");
	agregarToolTip((gchar*)"Agregar compuerta AND");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_AND), NULL);

}

Boton_AND::~Boton_AND() {

}

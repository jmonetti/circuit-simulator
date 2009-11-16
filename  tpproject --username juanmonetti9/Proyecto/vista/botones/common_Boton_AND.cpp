/**************************   Clase BOTON AND ***********************/
/**************************   	Grupo 8       ***********************/

#include "common_Boton_AND.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_AND::Boton_AND():Boton() {

	agregarImagen((gchar*)"imagenes/AND.png");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_AND), NULL);
}

Boton_AND::~Boton_AND() {

}

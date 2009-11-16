/**************************   Clase BOTON Selector ******************/
/**************************   	Grupo 8            ******************/


#include "common_Boton_Selector.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Selector::Boton_Selector():Boton() {

	agregarImagen((gchar*)"imagenes/SELECT.png");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Selector), NULL);


}

Boton_Selector::~Boton_Selector() {

}

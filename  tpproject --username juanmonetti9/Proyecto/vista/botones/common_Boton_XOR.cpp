/**************************   Clase BOTON XOR   *********************/
/**************************   	Grupo 8         *********************/

#include "common_Boton_XOR.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_XOR::Boton_XOR():Boton() {

	agregarImagen((gchar*)"imagenes/XOR.png");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_XOR), NULL);


}

Boton_XOR::~Boton_XOR() {

}

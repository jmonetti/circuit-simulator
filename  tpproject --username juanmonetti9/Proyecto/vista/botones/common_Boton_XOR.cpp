/**************************   Clase BOTON XOR   *********************/
/**************************   	Grupo 8         *********************/

#include "common_Boton_XOR.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_XOR::Boton_XOR():Boton() {

	agregarImagen((gchar*)"imagenes/XOR.png");
	agregarToolTip((gchar*)"Agregar compuerta XOR");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_XOR), NULL);


}

Boton_XOR::~Boton_XOR() {

}

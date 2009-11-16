/**************************   Clase BOTON Invertir *******************/
/**************************   	Grupo 8            *******************/

#include "common_Boton_Invertir.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Invertir::Boton_Invertir():Boton() {

	agregarImagen((gchar*)"imagenes/invert.png");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Invertir), NULL);


}

Boton_Invertir::~Boton_Invertir() {

}

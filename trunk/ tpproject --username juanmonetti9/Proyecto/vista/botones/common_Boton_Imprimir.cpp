/**************************   Clase BOTON Imprimir *******************/
/**************************   	Grupo 8            *******************/

#include "common_Boton_Imprimir.h"
#include "../../controlador/common_Controlador_Archivo.h"

Boton_Imprimir::Boton_Imprimir():Boton() {

	agregarImagen((gchar*)"imagenes/print.png");
	agregarToolTip((gchar*)"Imprimir");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Archivo::callback_Imprimir), NULL);


}

Boton_Imprimir::~Boton_Imprimir() {



}

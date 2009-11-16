/**************************   Clase BOTON Imprimir *******************/
/**************************   	Grupo 8            *******************/

#include "common_Boton_Imprimir.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Imprimir::Boton_Imprimir():Boton() {

	agregarImagen((gchar*)"imagenes/imprimir.png");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Imprimir), NULL);


}

Boton_Imprimir::~Boton_Imprimir() {



}

/**************************   Clase BOTON Invertir *******************/
/**************************   	Grupo 8            *******************/

#include "common_Boton_Invertir.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Invertir::Boton_Invertir():Boton() {

	agregarImagen((gchar*)"imagenes/rotar_left.png");
	agregarToolTip((gchar*)"Invertir Seleccionado");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_InvertirR), NULL);


}

Boton_Invertir::~Boton_Invertir() {

}

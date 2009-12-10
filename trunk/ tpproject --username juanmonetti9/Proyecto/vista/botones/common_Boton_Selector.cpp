/**************************   Clase BOTON Selector ******************/
/**************************   	Grupo 8            ******************/


#include "common_Boton_Selector.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Selector::Boton_Selector():Boton() {

	agregarImagen((gchar*)"imagenes/SELECT.png");
	agregarToolTip((gchar*)"Mover");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Selector), NULL);


}

Boton_Selector::~Boton_Selector() {

}

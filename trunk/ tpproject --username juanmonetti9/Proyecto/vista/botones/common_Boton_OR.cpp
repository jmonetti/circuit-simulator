/**************************   Clase BOTON OR  ***********************/
/**************************   	Grupo 8       ***********************/

#include "common_Boton_OR.h"
#include "../../controlador/common_Controlador_Circuito.h"


Boton_OR::Boton_OR():Boton() {

	agregarImagen((gchar*)"imagenes/OR.png");
	agregarToolTip((gchar*)"Agregar compuerta OR");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_OR), NULL);


}

Boton_OR::~Boton_OR() {

}

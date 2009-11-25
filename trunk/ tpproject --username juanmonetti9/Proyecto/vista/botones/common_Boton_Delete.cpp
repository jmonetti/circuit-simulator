/**************************   Clase BOTON Delete ********************/
/**************************   	Grupo 8          *********************/

#include "common_Boton_Delete.h"
#include "../../controlador/common_Controlador_Circuito.h"


Boton_Delete::Boton_Delete():Boton() {

	agregarImagen((gchar*)"imagenes/delete.png");
	agregarToolTip((gchar*)"Borrar seleccionado");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Delete), NULL);

}

Boton_Delete::~Boton_Delete() {

}

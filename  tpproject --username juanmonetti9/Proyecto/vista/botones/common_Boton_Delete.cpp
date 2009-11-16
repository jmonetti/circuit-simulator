/**************************   Clase BOTON Delete ********************/
/**************************   	Grupo 8          *********************/

#include "common_Boton_Delete.h"
#include "../../controlador/common_Controlador_Boton.h"


Boton_Delete::Boton_Delete():Boton() {

	agregarImagen((gchar*)"imagenes/delete.png");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Delete), NULL);



}

Boton_Delete::~Boton_Delete() {

}

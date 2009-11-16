/**************************   Clase BOTON Download  ******************/
/**************************   	Grupo 8             ******************/


#include "common_Boton_Download.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Download::Boton_Download():Boton() {

	agregarImagen((gchar*)"imagenes/download.png");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Download), NULL);



}

Boton_Download::~Boton_Download() {

}

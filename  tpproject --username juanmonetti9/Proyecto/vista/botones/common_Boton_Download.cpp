/**************************   Clase BOTON Download  ******************/
/**************************   	Grupo 8             ******************/


#include "common_Boton_Download.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Download::Boton_Download():Boton() {

	agregarImagen((gchar*)"imagenes/download.png");
	agregarToolTip((gchar*)"Descargar circuito");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_crear_Download), NULL);



}

Boton_Download::~Boton_Download() {

}

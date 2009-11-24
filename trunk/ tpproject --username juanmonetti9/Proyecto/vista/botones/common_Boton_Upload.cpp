/**************************   Clase BOTON Upload ********************/
/**************************   	Grupo 8          ********************/

#include "common_Boton_Upload.h"
#include "../../controlador/common_Controlador_Circuito.h"

Boton_Upload::Boton_Upload():Boton() {

	agregarImagen((gchar*)"imagenes/upload.png");
	agregarToolTip((gchar*)"Subir circuito a servidor");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Upload), NULL);


}

Boton_Upload::~Boton_Upload(){

}

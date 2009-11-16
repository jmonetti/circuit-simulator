/**************************   Clase BOTON Upload ********************/
/**************************   	Grupo 8          ********************/

#include "common_Boton_Upload.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Upload::Boton_Upload():Boton() {

	agregarImagen((gchar*)"imagenes/upload.png");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Upload), NULL);


}

Boton_Upload::~Boton_Upload(){

}

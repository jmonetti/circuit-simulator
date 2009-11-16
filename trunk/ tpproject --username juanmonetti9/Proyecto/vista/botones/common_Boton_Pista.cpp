/**************************   Clase BOTON PISTA *********************/
/**************************   	Grupo 8         *********************/

#include "common_Boton_Pista.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Pista::Boton_Pista() {

	agregarImagen((gchar*)"imagenes/PISTA.png");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Pista), NULL);

}

Boton_Pista::~Boton_Pista() {

}

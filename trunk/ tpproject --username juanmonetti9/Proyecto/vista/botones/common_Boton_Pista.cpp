/**************************   Clase BOTON PISTA *********************/
/**************************   	Grupo 8         *********************/

#include "common_Boton_Pista.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Pista::Boton_Pista() {

	agregarImagen((gchar*)"imagenes/PISTA.png");
	agregarToolTip((gchar*)"Agregar Pista");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Pista), NULL);

}

Boton_Pista::~Boton_Pista() {

}

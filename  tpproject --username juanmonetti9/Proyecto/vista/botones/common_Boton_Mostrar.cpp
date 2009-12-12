
#include "common_Boton_Mostrar.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Mostrar::Boton_Mostrar() {

	agregarImagen((gchar*)"imagenes/mostrar.png");
	agregarToolTip((gchar*)"Mostrar Caja Negra");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Mostrar), NULL);


}

Boton_Mostrar::~Boton_Mostrar() {

}

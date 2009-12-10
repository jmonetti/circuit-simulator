/**************************   Clase BOTON Entrada   ******************/
/**************************   	Grupo 8             ******************/

#include "common_Boton_entrada.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_entrada::Boton_entrada() {

	agregarImagen((gchar*)"imagenes/entrada.png");
	agregarToolTip((gchar*)"Agregar entrada");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_crear_entrada), NULL);


}

Boton_entrada::~Boton_entrada() {

}

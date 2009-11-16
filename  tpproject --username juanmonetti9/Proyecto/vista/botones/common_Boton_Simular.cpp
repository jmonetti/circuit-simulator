/**************************   Clase BOTON Simulador  ****************/
/**************************   	Grupo 8              ****************/

#include "common_Boton_Simular.h"
#include "../../controlador/common_Controlador_Boton.h"

Boton_Simular::Boton_Simular():Boton() {

	agregarImagen((gchar*)"imagenes/Simulacion.png");
	gtk_signal_connect (GTK_OBJECT (getBoton()), "clicked", GTK_SIGNAL_FUNC (Controlador_Boton::callback_Simulacion), NULL);


}

Boton_Simular::~Boton_Simular() {
	// TODO Auto-generated destructor stub
}

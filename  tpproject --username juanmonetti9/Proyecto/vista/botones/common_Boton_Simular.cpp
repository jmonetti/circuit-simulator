/**************************   Clase BOTON Simulador  ****************/
/**************************   	Grupo 8              ****************/

#include "common_Boton_Simular.h"
#include "../../controlador/common_Controladores_Circuito.h"

Boton_Simular::Boton_Simular():Boton() {

	agregarImagen((gchar*)"imagenes/Simulacion.png");
	agregarToolTip((gchar*)"Simular");
	gtk_signal_connect (GTK_OBJECT (getWidget()), "clicked", GTK_SIGNAL_FUNC (Controlador_Circuito::callback_Simulacion), NULL);


}

Boton_Simular::~Boton_Simular() {
	// TODO Auto-generated destructor stub
}

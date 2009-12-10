/**************************   Clase Controlador Ventana  ************/
/**************************   	Grupo 8                  *************/

#include "common_Controladores_Window.h"
#include "common_Controlador.h"


gint Controlador_Ventana::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)	{

	Controlador* controlador = Controlador::get_instancia();

	if(controlador){
		controlador->destruir_vista();
	}
	return false;
}

void Controlador_Ventana::destroy (GtkWidget *widget, gpointer data){

		gtk_main_quit ();
}

Controlador_Ventana::~Controlador_Ventana() {

}


gint Controlador_Ventana::delete_event_true(GtkWidget *widget, GdkEvent *event, gpointer data) {

	return true;


}


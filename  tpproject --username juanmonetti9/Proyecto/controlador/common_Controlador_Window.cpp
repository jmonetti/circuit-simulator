/**************************   Clase Controlador Ventana  ************/
/**************************   	Grupo 8                  *************/

#include "common_Controlador_Window.h"


gint Controlador_Ventana::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)	{

	    return false;
}

void Controlador_Ventana::destroy (GtkWidget *widget, gpointer data){

		gtk_main_quit ();
}

Controlador_Ventana::~Controlador_Ventana() {

}

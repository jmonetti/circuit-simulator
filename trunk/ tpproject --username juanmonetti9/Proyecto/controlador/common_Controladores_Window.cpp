/**************************   Clase Controlador Ventana  ************/
/**************************   	Grupo 8                  *************/

#include "common_Controladores_Window.h"
#include "common_Controlador.h"
#include "../vista/common_Componente_Visual.h"


gint Controlador_Ventana::delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)	{

	return false;
}

void Controlador_Ventana::destroy (GtkWidget *widget, gpointer data){

		gtk_main_quit ();
}

Controlador_Ventana::~Controlador_Ventana() {

}

gint Controlador_Ventana::delete_event_esconder(GtkWidget *widget, GdkEvent *event, gpointer data) {

	Componente_Visual* ventana = (Componente_Visual*) data;
	ventana->hide();

	return true;

}


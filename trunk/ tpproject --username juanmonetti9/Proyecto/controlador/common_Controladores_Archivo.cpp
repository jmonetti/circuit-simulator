/**************************   Clase Controlador Archivo *************/
/**************************   	Grupo 8                 *************/

#include "common_Controladores_Archivo.h"
#include "../vista/common_Box_Ventana_Interna.h"
#include "common_Controlador.h"

void Controlador_Archivo::callback_Imprimir( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Imprimir\n");
	//fin TODO
}

void Controlador_Archivo::callback_nuevo(GtkWidget *widget, gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();
	if(controlador){
		controlador->crear_circuito();
	}
}

void Controlador_Archivo::callback_abrir(GtkWidget *widget, gpointer callback_data ){

	//TODO
	g_print("Abrir\n");
	//fin TODO
}

void Controlador_Archivo::callback_guardar(GtkWidget *widget, gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();
	if(controlador){
		controlador->guardar();
	}

}

void Controlador_Archivo::callback_cerrar_ventana_circuit(GtkWidget *widget, gpointer callback_data ){

	Controlador* controlador=Controlador::get_instancia();
	if(controlador){
		controlador->eliminar_circuito();
	}
}

void Controlador_Archivo::callback_cambiar_pestania(GtkNotebook *notebook,GtkNotebookPage *page,guint page_num,gpointer user_data){

	Controlador* controlador=Controlador::get_instancia();
		if(controlador){
			controlador->cambiar_circuito(page_num);
		}

}


void Controlador_Archivo::callback_cerrar(GtkWidget *widget, gpointer data){

		gtk_main_quit ();
}

Controlador_Archivo::~Controlador_Archivo() {

}

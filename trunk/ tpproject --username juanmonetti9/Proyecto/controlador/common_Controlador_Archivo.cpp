/**************************   Clase Controlador Archivo *************/
/**************************   	Grupo 8                 *************/

#include "common_Controlador_Archivo.h"

void Controlador_Archivo::callback_Imprimir( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Imprimir\n");
	//fin TODO
}

void Controlador_Archivo::callback_Upload( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el Upload\n");
	//fin TODO
}

void Controlador_Archivo::callback_Download( GtkWidget *widget,gpointer callback_data ){
	//TODO
	g_print("Apretado el download\n");
	//fin TODO
}
void Controlador_Archivo::callback_nuevo(GtkWidget *widget, gpointer callback_data ){

	//TODO
	g_print("Nuevo\n");
	//fin TODO
}

void Controlador_Archivo::callback_abrir(GtkWidget *widget, gpointer callback_data ){

	//TODO
	g_print("Abrir\n");
	//fin TODO
}

void Controlador_Archivo::callback_guardar(GtkWidget *widget, gpointer callback_data ){

	//TODO
	g_print("Guardar\n");
	//fin TODO
}

void Controlador_Archivo::callback_cerrar_ventana_circuit(GtkWidget *widget, gpointer callback_data ){

	//TODO
	g_print("Cerrar ventana circuito\n");
	//fin TODO
}


void Controlador_Archivo::callback_cerrar(GtkWidget *widget, gpointer data){

		gtk_main_quit ();
}

Controlador_Archivo::~Controlador_Archivo() {

}

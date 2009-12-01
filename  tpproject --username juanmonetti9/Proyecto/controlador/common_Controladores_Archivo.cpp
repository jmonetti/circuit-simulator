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

	Controlador* controlador=Controlador::get_instancia();
	if(controlador){
		controlador->guardar();
	}

}

void Controlador_Archivo::callback_cerrar_ventana_circuit(GtkWidget *widget, gpointer callback_data ){

	//TODO
	g_print("Cerrar ventana circuito\n");
	//fin TODO
	//TODO((Box_Ventana_Interna*)callback_data)->eliminar_pestania_actual();
}


void Controlador_Archivo::callback_cerrar(GtkWidget *widget, gpointer data){

		gtk_main_quit ();
}

Controlador_Archivo::~Controlador_Archivo() {

}

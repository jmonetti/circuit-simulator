/**************************   Clase Controlador Archivo *************/
/**************************   	Grupo 8                 *************/


#ifndef COMMON_CONTROLADORES_ARCHIVO_H_
#define COMMON_CONTROLADORES_ARCHIVO_H_
#include <gtkmm.h>

class Controlador_Archivo {

public:


	virtual ~Controlador_Archivo();

	static void callback_Imprimir( GtkWidget *widget,gpointer callback_data );

	static void callback_nuevo(GtkWidget *widget, gpointer callback_data );

	static void callback_cerrar(GtkWidget *widget, gpointer data);

	static void callback_abrir(GtkWidget *widget, gpointer data);

	static void callback_guardar(GtkWidget *widget, gpointer data);

	static void callback_cerrar_ventana_circuit(GtkWidget *widget, gpointer data);

	static void callback_cambiar_pestania(GtkNotebook *notebook,GtkNotebookPage *page,guint page_num,gpointer user_data);

	static void callback_aceptar_abrir(GtkWidget *widget, gpointer data);

	static void callback_cancelar_abrir(GtkWidget *widget, gpointer data);

	static void callback_aceptar_nuevo(GtkWidget *widget, gpointer data);

};

#endif /* COMMON_CONTROLADOR_ARCHIVO_H_ */

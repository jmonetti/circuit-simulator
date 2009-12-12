/**************************   Clase Controlador Boton  **************/
/**************************   	Grupo 8                **************/

#ifndef COMMON_CONTROLADORES_CIRCUITO_H_
#define COMMON_CONTROLADORES_CIRCUITO_H_
#include <gtkmm.h>
#include "Modelo_vista_circ/common_Modelo_vista_circuito.h"
#include "common_Controlador.h"

class Controlador_Circuito {


public:


	static void callback_crear_Upload( GtkWidget *widget,gpointer callback_data );

	static void callback_Upload( GtkWidget *widget,gpointer callback_data );

	static void callback_crear_Download( GtkWidget *widget,gpointer callback_data );

	static void callback_conectar( GtkWidget *widget,gpointer callback_data );

	static void callback_Download( GtkWidget *widget,gpointer callback_data );

	static void callback_AND( GtkWidget *widget,gpointer callback_data );

	static void callback_OR( GtkWidget *widget,gpointer callback_data );

	static void callback_XOR( GtkWidget *widget,gpointer callback_data );

	static void callback_NOT( GtkWidget *widget,gpointer callback_data );

	static void callback_Pista( GtkWidget *widget,gpointer callback_data );

	static void callback_crear_entrada(GtkWidget *widget,gpointer callback_data );

	static void callback_Entrada(GtkWidget *widget,gpointer callback_data );

	static void callback_crear_salida(GtkWidget *widget,gpointer callback_data );

	static void callback_Salida(GtkWidget *widget,gpointer callback_data );

	static void callback_Selector( GtkWidget *widget,gpointer callback_data );

	static void callback_Delete( GtkWidget *widget,gpointer callback_data );

	static void callback_InvertirR( GtkWidget *widget,gpointer callback_data );

	static void callback_InvertirL( GtkWidget *widget,gpointer callback_data );

	static void callback_Simulacion( GtkWidget *widget,gpointer callback_data );

	static void callback_Mostrar( GtkWidget *widget,gpointer callback_data );

	/**
	 * Controlador del evento de presionar el primer boton del raton
	 */
	static gint button_press_event (GtkWidget *widget, GdkEventButton *event);

	/**
	 * Controlador para cuando se suelte la seleccion. checkea si se solto sobre una
	 * parte valida del widget .
	 * Llama a la funcion gtk_drag_get_data que emite una señal de "drag-data-get"
	 * @param widget: destino
	 */
	static gboolean drag_drop_handl(GtkWidget *widget, GdkDragContext *context, gint x, gint y, guint time,gpointer user_data);




private:

	static void crearVentanaDialogoPuertas(const char* titulo);

	static void crearVentanaDialogoServidor();
};

#endif /* COMMON_CONTROLADOR_BOTON_H_ */

/**************************   Clase Controlador Boton  **************/
/**************************   	Grupo 8                **************/

#ifndef COMMON_CONTROLADOR_CIRCUITO_H_
#define COMMON_CONTROLADOR_CIRCUITO_H_
#include <gtkmm.h>
#include "Modelo_vista_circ/common_Modelo_vista_circuito.h"

class Controlador_Circuito {

private:
	static Modelo_vista_circuito matriz;
	static int pos_x; //pos de comienzo de arrastre
	static int pos_y; //pos de comienzo de arrastre

public:

	Controlador_Circuito();

	static void callback_Upload( GtkWidget *widget,gpointer callback_data );

	static void callback_Download( GtkWidget *widget,gpointer callback_data );

	static void callback_AND( GtkWidget *widget,gpointer callback_data );

	static void callback_OR( GtkWidget *widget,gpointer callback_data );

	static void callback_XOR( GtkWidget *widget,gpointer callback_data );

	static void callback_NOT( GtkWidget *widget,gpointer callback_data );

	static void callback_Pista( GtkWidget *widget,gpointer callback_data );

	static void callback_Selector( GtkWidget *widget,gpointer callback_data );

	static void callback_Delete( GtkWidget *widget,gpointer callback_data );

	static void callback_InvertirR( GtkWidget *widget,gpointer callback_data );

	static void callback_InvertirL( GtkWidget *widget,gpointer callback_data );

	static void callback_Simulacion( GtkWidget *widget,gpointer callback_data );

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


	virtual ~Controlador_Circuito();

private:

	static void crearVentanaDialogoPuertas(const char* titulo);

	static void crearVentanaDialogoServidor();
};

#endif /* COMMON_CONTROLADOR_BOTON_H_ */

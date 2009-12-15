/**************************   Clase Controlador Ventana  ************/
/**************************   	Grupo 8                  *************/

#ifndef COMMON_CONTROLADORES_WINDOW_H_
#define COMMON_CONTROLADORES_WINDOW_H_

#include "gtkmm.h"

class Controlador_Ventana {

public:


	static gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);

	static void destroy (GtkWidget *widget, gpointer data);

	virtual ~Controlador_Ventana();

	static gint delete_event_esconder(GtkWidget *widget, GdkEvent *event, gpointer data);
};


#endif /* COMMON_CONTROLADOR_VENTANA_H_ */

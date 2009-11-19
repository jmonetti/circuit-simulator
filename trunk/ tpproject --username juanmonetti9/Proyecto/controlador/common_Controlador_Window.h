/**************************   Clase Controlador Ventana  ************/
/**************************   	Grupo 8                  *************/

#ifndef COMMON_CONTROLADOR_WINDOW_H_
#define COMMON_CONTROLADOR_WINDOW_H_

#include "gtkmm.h"

class Controlador_Ventana {

public:


	static gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);

	static void destroy (GtkWidget *widget, gpointer data);



	virtual ~Controlador_Ventana();


};

#endif /* COMMON_CONTROLADOR_VENTANA_H_ */

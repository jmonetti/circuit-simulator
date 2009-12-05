
#ifndef COMMON_VENTANA_ABRIR_H_
#define COMMON_VENTANA_ABRIR_H_

#include "common_Componente_Visual.h"
#include <gtkmm.h>

class Ventana_Abrir: public Componente_Visual {

public:

	Ventana_Abrir();

	virtual ~Ventana_Abrir();

	void show();

	void hide();

	GtkWidget* getWidget();

	char* getCircuitoAbrir();

	void mostrarCircuitos();

	bool estaActiva();

private:

	GtkWidget* cuadro;
	GtkWidget* lista;

	const static char* titulo[];

	static char* circuitoAbrir;

	bool activa;

	static void select_row_callback(GtkWidget *widget, gint row, gint colum,
			GdkEventButton *event, gpointer data);

	static void unselect_row_callback(GtkWidget *widget, gint row, gint colum,
				GdkEventButton *event, gpointer data);


};

#endif /* COMMON_VENTANA_ABRIR_H_ */


#ifndef COMMON_VENTANA_ERROR_H_
#define COMMON_VENTANA_ERROR_H_

#include "common_Componente_Visual.h"
#include <string>
#include <gtkmm.h>

class Ventana_Error: public Componente_Visual {

public:

	Ventana_Error();

	virtual ~Ventana_Error();

	void show();

	void hide();

	GtkWidget* getWidget();

	void mostrarError(const std::string &texto);



private:

	GtkWidget* cuadro;
	GtkWidget* label;

	static void do_nothing(GtkWidget *widget, gpointer data);

	static gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data);

};

#endif /* COMMON_VENTANA_ERROR_H_ */

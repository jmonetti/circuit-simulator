
#ifndef COMMON_VENTANA_NUEVO_H_
#define COMMON_VENTANA_NUEVO_H_

#include "common_Componente_Visual.h"

class Ventana_Nuevo: public Componente_Visual {

public:

	Ventana_Nuevo();

	virtual ~Ventana_Nuevo();

	void show();

	GtkWidget* getWidget();

	void hide();

	const char* getNombre();

private:

	GtkWidget* cuadro;
	GtkWidget* entry;

	static void callback_cancelar(GtkWidget *widget, gpointer data);

};

#endif /* COMMON_VENTANA_NUEVO_H_ */
